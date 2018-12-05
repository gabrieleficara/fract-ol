/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:24:46 by gficara           #+#    #+#             */
/*   Updated: 2018/09/25 14:10:29 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion(int x, int y, void *param)
{
	t_pars	*pars;

	pars = (t_pars *)param;
	if (pars->f_mov < 0)
		return (0);
	if (pars->f_mov > 0)
	{
		pars->cons[0] += 0.0001 * (x - pars->m_coor[0]);
		pars->cons[1] += 0.0001 * (y - pars->m_coor[1]);
		putimg(pars);
	}
	else
		pars->f_mov = 1;
	pars->m_coor[0] = x;
	pars->m_coor[1] = y;
	return (0);
}

int			mouse_hook(int button, int x, int y, void *param)
{
	t_pars	*pars;

	pars = (t_pars *)param;
	if (button == 4)
	{
		pars->zoom += 0.1;
		pars->center[0] += 0.1 * (pars->size[0] / 2 - x);
		pars->center[1] += 0.1 * (pars->size[0] / 2 - y);
	}
	if (button == 5 && pars->zoom > 0.1)
	{
		pars->zoom -= 0.1;
		pars->center[0] += 0.1 * (pars->size[0] / 2 - x);
		pars->center[1] += 0.1 * (pars->size[1] / 2 - y);
	}
	putimg(pars);
	x = 0;
	y = 0;
	return (0);
}

int			dealkey(int key, void *param)
{
	t_pars	*pars;

	pars = (t_pars *)param;
	if (key == 53 || key == 8)
		return (esc_reset(key, pars));
	if (key == 15 || key == 5 || key == 11)
		return (rrggbb_key(key, pars));
	if (key == 17 || key == 4 || key == 45 || key == 48)
		return (rrggbb_key(key, pars));
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 257)
		return (movement(key, pars));
	if (key == 49)
		return ((pars->f_mov = (pars->f_mov >= 0) ? -1 : 0));
	return (0);
}

int			init_pars(t_pars *pars)
{
	pars->size[0] = WIDTH;
	pars->size[1] = HEIGHT;
	pars->center[0] = WIDTH / 2;
	pars->center[1] = HEIGHT / 2;
	pars->cons[0] = -0.7;
	pars->cons[1] = 0.27015;
	pars->mv[0] = 0;
	pars->mv[1] = 0;
	pars->m_coor[0] = 0;
	pars->m_coor[1] = 0;
	pars->color[0] = 1;
	pars->color[1] = 1;
	pars->color[2] = 1;
	pars->color[3] = 0;
	pars->color[4] = 0;
	pars->color[5] = 0;
	pars->zoom = 1;
	pars->f_mov = 0;
	pars->color_mod = 510;
	putimg(pars);
	return (0);
}

int			main(int ac, char **av)
{
	t_pars	pars;

	if (parsing(ac, av, &pars) < 0)
		return (delete_image(&pars, 0));
	if (!(pars.mini = mlx_init()))
		return (delete_image(&pars, 0));
	if (!(pars.img = mlx_new_image(pars.mini, WIDTH + 2, HEIGHT + 2)))
		return (delete_image(&pars, 0));
	if (!(pars.window = mlx_new_window(pars.mini, WIDTH, HEIGHT, "Fract'ol")))
		return (delete_image(&pars, 1));
	init_pars(&pars);
	mlx_hook(pars.window, 6, 0L, motion, (void *)&pars);
	mlx_key_hook(pars.window, dealkey, (void *)&pars);
	mlx_mouse_hook(pars.window, mouse_hook, (void *)&pars);
	mlx_hook(pars.window, 17, 1L << 17, exit_x, (void *)&pars);
	mlx_loop(pars.mini);
	return (0);
}
