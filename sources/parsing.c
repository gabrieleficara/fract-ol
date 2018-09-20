/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:05:39 by gficara           #+#    #+#             */
/*   Updated: 2018/09/20 18:07:31 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		usage(char *str)
{
	ft_printf("Usage : %s <fractal_name>\nfractal:\tJulia\n", str);
	ft_printf("\t\tMandelbrot\n\t\tBurning ship\n", str);
	return (-ft_printf("\t\tNewton\n\t\tAbs julia\n", str));
}

void		legend(t_pars *pars)
{
	if (pars->hide == 1)
		return ;
	mlx_string_put(pars->mini, pars->window, 0, 0, 0xffffff,
		"esc -> Quit the program\n r-g-b color\n t-h-n negative\n");
}

int		delete_image(t_pars *pars, int flag)
{
	if (pars->mini && flag > 1)
		mlx_destroy_image(pars->mini, pars->img);
	if (pars->window && flag > 0)
		mlx_destroy_window(pars->mini, pars->window);
	return (1);
}

int		parsing(int ac, char **av, t_pars *pars)
{
	pars->fract = 0;
	if (ac != 2)
		return (usage(av[0]));
	if (!ft_strcmp("Julia", av[1]) || !ft_strcmp("julia", av[1]))
		return((pars->fract = 1));
	if (!ft_strcmp("Mandelbrot", av[1]) || !ft_strcmp("mandelbrot", av[1]))
		return ((pars->fract = 2));
	if (!ft_strcmp("Burning ship", av[1]) || !ft_strcmp("burning ship", av[1]))
		return ((pars->fract = 3));
	if (!ft_strcmp("Newton", av[1]) || !ft_strcmp("newton", av[1]))
		return ((pars->fract = 4));
	if (!ft_strcmp("Abs julia", av[1]) || !ft_strcmp("abs julia", av[1]))
		return ((pars->fract = 5));
	return (usage(av[0]));
}
