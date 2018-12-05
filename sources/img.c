/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:08:07 by gficara           #+#    #+#             */
/*   Updated: 2018/09/24 18:50:04 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_to_number(int rr, int gg, int bb)
{
	int		num;

	num = ((bb & 255) << 16) + ((gg & 255) << 8) + (rr & 255);
	return (num);
}

int		color_transform(int n, int i, t_pars *pars)
{
	if (pars->color_mod < 300)
	{
		if (pars->color[i + 3] == 0)
			return (n * pars->color[i]);
		else
			return (255 - n * pars->color[i]);
	}
	else
	{
		if (pars->color[i + 3] == 0)
		{
			if (n > 255)
				return (255 - ((n - 255) * pars->color[i]));
			else
				return (n * pars->color[i]);
		}
		else
		{
			if (n > 255)
				return (((n - 255) * pars->color[i]));
			else
				return (255 - n * pars->color[i]);
		}
	}
}

void	draw_dot(int x, int y, int color, t_thr *thr)
{
	int		i;

	i = y * thr->sl + x * 4;
	if (x > 0 && y > 0 && x < thr->pars->size[0] && y < thr->pars->size[1])
	{
		thr->img_c[i] = (char)(color & 255);
		thr->img_c[i + 1] = (char)((color >> 8) & 255);
		thr->img_c[i + 2] = (char)((color >> 16) & 255);
		thr->img_c[i + 3] = (char)0;
	}
}
