#include "fractol.h"

int		color_julia(t_pars *pars, int coor[2])
{
	int		n;
	double	new[2];
	double	old[2];

	n = -1;
	new[0] = 1.5 * (coor[0] - pars->center[0]) /
		(0.5 * pars->zoom * pars->size[0]) + pars->mv[0];
	new[1] = (coor[1] - pars->center[1]) /
		(0.5 * pars->zoom * pars->size[1]) + pars->mv[1];
	while (++n < MAX_ITER)
	{
		old[0] = new[0];
		old[1] = new[1];
		new[0] = old[0] * old[0] - old[1] * old[1] + pars->cons[0];
		new[1] = 2 * old[0] * old[1] + pars->cons[1];
		if (new[0] * new[0] + new[1] + new[1] > 4)
			break;
	}
	n = (pars->color_mod * n) / MAX_ITER;
	return (color_to_number(color_transform(n, 0, pars),
				color_transform(n, 1, pars), color_transform(n, 2, pars)));
}

int		color_mandelbrot(t_pars *pars, int coor[2])
{
	int		n;
	double	new[2];
	double	old[2];
	double	p[2];

	n = -1;
	p[0] = 1.5 * (coor[0] - pars->center[0]) /
		(0.5 * pars->zoom * pars->size[0]) + pars->mv[0];
	p[1] = (coor[1] - pars->center[1]) /
		(0.5 * pars->zoom * pars->size[1]) + pars->mv[1];
	new[0] = 0;
	new[1] = 0;
	while (++n < MAX_ITER)
	{
		old[0] = new[0];
		old[1] = new[1];
		new[0] = old[0] * old[0] - old[1] * old[1] + p[0];
		new[1] = 2 * old[0] * old[1] + p[1];
		if (new[0] * new[0] + new[1] + new[1] > 4)
			break;
	}
	n = (pars->color_mod * n) / MAX_ITER;
	return (color_to_number(color_transform(n, 0, pars),
				color_transform(n, 1, pars), color_transform(n, 2, pars)));
}

int		color_newton(t_pars *pars, int coor[2])
{
	int		n;
	double	new[2];
	double	old[2];

	n = -1;
	new[0] = 1.5 * (coor[0] - pars->center[0]) /
		(0.5 * pars->zoom * pars->size[0]) + pars->mv[0];
	new[1] = (coor[1] - pars->center[1]) /
		(0.5 * pars->zoom * pars->size[1]) + pars->mv[1];
	while (++n < MAX_ITER)
	{
		old[0] = new[0];
		old[1] = new[1];
		new[0] = old[0] * old[0] * old[0] - old[1] * old[1] * old[0] * 3 +
			pars->cons[0];
		new[1] = 3 * old[0] * old[0] * old[1] - old[1] * old[1] * old[1] +
			pars->cons[1];
		if (new[0] * new[0] + new[1] + new[1] > 4)
			break;
	}
	n = (pars->color_mod * n) / MAX_ITER;
	return (color_to_number(color_transform(n, 0, pars),
				color_transform(n, 1, pars), color_transform(n, 2, pars)));
}

int		color_abs_julia(t_pars *pars, int coor[2])
{
	int		n;
	double	new[2];
	double	old[2];

	n = -1;
	new[0] = 1.5 * (coor[0] - pars->center[0]) /
		(0.5 * pars->zoom * pars->size[0]) + pars->mv[0];
	new[1] = (coor[1] - pars->center[1]) /
		(0.5 * pars->zoom * pars->size[1]) + pars->mv[1];
	while (++n < MAX_ITER)
	{
		old[0] = fabs(new[0]);
		old[1] = fabs(new[1]);
		new[0] = old[0] * old[0] - old[1] * old[1] + pars->cons[0];
		new[1] = 2 * old[0] * old[1] + pars->cons[1];
		if (new[0] * new[0] + new[1] + new[1] > 4)
			break;
	}
	n = (pars->color_mod * n) / MAX_ITER;
	return (color_to_number(color_transform(n, 0, pars),
				color_transform(n, 1, pars), color_transform(n, 2, pars)));
}
int		color_burning_ship(t_pars *pars, int coor[2])
{
	int		n;
	double	new[2];
	double	old[2];
	double	tmp;

	n = -1;
	new[0] = 1.5 * (coor[0] - pars->center[0]) /
		(0.5 * pars->zoom * pars->size[0]) + pars->mv[0];
	new[1] = (coor[1] - pars->center[1]) /
		(0.5 * pars->zoom * pars->size[1]) + pars->mv[1];
	old[0] = new[0];
	old[1] = new[1];
	while (++n < MAX_ITER)
	{
		tmp = new[0] * new[0] - new[1] * new[1] + old[0];
		new[1] = 2 * fabs(new[0] * new[1]) + old[1];
		new[0] = fabs(tmp);
		if (new[0] * new[0] + new[1] + new[1] > 4)
			break;
	}
	n = (pars->color_mod * n) / MAX_ITER;
	return (color_to_number(color_transform(n, 0, pars),
				color_transform(n, 1, pars), color_transform(n, 2, pars)));
}
