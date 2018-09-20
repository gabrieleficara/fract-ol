/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:33:48 by gficara           #+#    #+#             */
/*   Updated: 2018/09/20 18:21:56 by gficara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define HEIGHT		720
# define WIDTH		1280
# define MAX_ITER	100
# define RADIUS		6

typedef struct	s_pars
{
	int			fract;
	int			size[2];
	void		*mini;
	void		*window;
	void		*img;
	char		*img_c;
	double		zoom;
	double		cons[2];
	double		mv[2];
	double		center[2];
	int			color[6];
	int			hide;
	int			m_coor[2];
	int			f_mov;
	int			color_mod;
}				t_pars;

typedef struct	s_thr
{
	pthread_t	thread;
	int			min[2];
	int			max[2];
	char		*img_c;
	int			bpp;
	int			sl;
	int			end;
	t_pars		*pars;
}				t_thr;

int				parsing(int ac, char **av, t_pars *pars);
int				delete_image(t_pars *pars, int flag);
int				init_pars(t_pars *pars);
void			putimg(t_pars *pars);
void			draw_dot(int x, int y, int color, t_thr *thr);
void			legend(t_pars *pars);
int				esc_reset(int key, t_pars *pars);
int				rrggbb_key(int key, t_pars *pars);
int				movement(int key, t_pars *pars);
int				color_to_number(int rr, int gg, int bb);
int				color_transform(int n, int i, t_pars *pars);
int				color_julia(t_pars *pars, int coor[2]);
int				color_abs_julia(t_pars *pars, int coor[2]);
int				color_mandelbrot(t_pars *pars, int coor[2]);
int				color_burning_ship(t_pars *pars, int coor[2]);
int				color_newton(t_pars *pars, int coor[2]);

#endif
