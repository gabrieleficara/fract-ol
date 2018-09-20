#include "fractol.h"

void	*filling(void *param)
{
	int		coor[2];
	int		(*fract)(t_pars *paars, int coor[2]);
	t_thr	*thread;

	thread = (t_thr *)param;
	if (thread->pars->fract == 1)
		fract = color_julia;
	else if (thread->pars->fract == 2)
		fract = color_mandelbrot;
	else if (thread->pars->fract == 3)
		fract = color_burning_ship;
	else if (thread->pars->fract == 4)
		fract = color_newton;
	else
		fract = color_abs_julia;
	coor[1] = thread->min[1] - 1;
	while (++coor[1] < thread->max[1])
	{
		coor[0] = thread->min[0] - 1;
		while (++coor[0] < thread->max[0])
			draw_dot(coor[0], coor[1], (*fract)(thread->pars, coor),
					thread);
	}
	pthread_exit(NULL);
}

void	init_thr(t_thr *thr, int i, t_pars *pars)
{
	if (i < 2)
	{
		thr->min[0] = 0;
		thr->max[0] = pars->size[0] / 2;
	}
	else
	{
		thr->min[0] = pars->size[0] / 2;
		thr->max[0] = pars->size[0];
	}
	if (i % 2 == 0)
	{
		thr->min[1] = 0;
		thr->max[1] = pars->size[1] / 2;
	}
	else
	{
		thr->min[1] = pars->size[1] / 2;
		thr->max[1] = pars->size[1];
	}
}

void	putimg(t_pars *pars)
{
	t_thr	thr[4];
	int		i;

	i = -1;
	while (++i < 4)
	{
		init_thr(&(thr[i]), i, pars);
		thr[i].img_c = mlx_get_data_addr(pars->img, &thr[i].bpp, &thr[i].sl,
				&thr[i].end);
		thr[i].pars = pars;
		pthread_create(&(thr[i].thread), NULL, *filling, (void *) &(thr[i]));
	}
	i = -1;
	while (++i < 4)
		pthread_join(thr[i].thread, NULL);
	mlx_put_image_to_window(pars->mini, pars->window, pars->img, 0, 0);
}
