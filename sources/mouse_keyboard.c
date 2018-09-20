#include "fractol.h"

int		esc_reset(int key, t_pars *pars)
{
	if (key == 53)
	{
		delete_image(pars, 0);
		exit(0);
	}
	init_pars(pars);
	return (0);
}

int		rrggbb_key(int key, t_pars *pars)
{
	if (key == 15)
		pars->color[0] = (pars->color[0] == 1) ? 0 : 1;
	if (key == 5)
		pars->color[1] = (pars->color[1] == 1) ? 0 : 1;
	if (key == 11)
		pars->color[2] = (pars->color[2] == 1) ? 0 : 1;
	if (key == 17)
		pars->color[3] = (pars->color[3] == 1) ? 0 : 1;
	if (key == 4)
		pars->color[4] = (pars->color[4] == 1) ? 0 : 1;
	if (key == 45)
		pars->color[5] = (pars->color[5] == 1) ? 0 : 1;
	if (key == 48)
		pars->color_mod = (pars->color_mod == 255) ? 610 : 255;
	putimg(pars);
	return (0);
}

int		movement(int key, t_pars *pars)
{
	if (key == 123)
		pars->mv[0] -= 0.1;
	if (key == 124)
		pars->mv[0] += 0.1;
	if (key == 125)
		pars->mv[1] += 0.1;
	if (key == 126)
		pars->mv[1] -= 0.1;
	if (key == 257)
		pars->fract = (pars->fract % 5) + 1;
	putimg(pars);
	return (0);
}
