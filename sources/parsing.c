/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:05:39 by gficara           #+#    #+#             */
/*   Updated: 2018/09/24 18:52:31 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		usage(char *str)
{
	ft_printf("Usage : %s <fractal 1>\nfractal:\tJulia\n", str);
	ft_printf("\t\tMandelbrot\n\t\tBurning ship\n", str);
	ft_printf("\t\tNewton\n\t\tAbs julia\n", str);
	ft_printf("Arrows: move the fractal\nMouse: transform the fractal", str);
	ft_printf("(if possible)\nMouse Wheel: zoom in/out\n", str);
	ft_printf("Shift: switch Fractal\nTab: switch color mode\n");
	return (-ft_printf("r-g-b|t-h-n: manage colors|negative \n", str));
}

void	legend(t_pars *pars)
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

void	fractchoise(char **av, int i, t_pars *pars)
{
	if (!ft_strcmp("Julia", av[i]) || !ft_strcmp("julia", av[i]))
		pars->fract = 1;
	else if (!ft_strcmp("Mandelbrot", av[i]) || !ft_strcmp("mandelbrot", av[i]))
		pars->fract = 2;
	else if (!ft_strcmp("Burning ship", av[i]) ||
			!ft_strcmp("burning ship", av[i]))
		pars->fract = 3;
	else if (!ft_strcmp("Newton", av[i]) || !ft_strcmp("newton", av[i]))
		pars->fract = 4;
	else if (!ft_strcmp("Abs julia", av[i]) || !ft_strcmp("abs julia", av[i]))
		pars->fract = 5;
	else
		pars->fract = -1;
}

int		parsing(int ac, char **av, t_pars *pars)
{
	if (ac != 2)
		return (usage(av[0]));
	fractchoise(av, 1, pars);
	return ((pars->fract == -1) ? usage(av[0]) : 1);
}
