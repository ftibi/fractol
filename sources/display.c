/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:24:02 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/18 20:03:44 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double			ft_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

t_frac			*zoom_frac(t_frac *frac)
{
	double	q;

	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	frac->xmin = frac->xpoint - frac->offx * q * frac->zoom;
	frac->xmax = frac->xmin + q * frac->size * frac->zoom;
	frac->ymin = frac->ypoint - frac->offy * q * frac->zoom;
	frac->ymax = frac->ymin + q * frac->size * frac->zoom;
	if (frac->zoom == 0.5)
	{
		if (!ft_strcmp(frac->ens, "dragon"))
			frac->amax++;
		else
			frac->amax += 10;
	}
	else
	{
		if (!ft_strcmp(frac->ens, "dragon"))
			frac->amax--;
		else
			frac->amax -= 10;
	}
	frac->zoom = 1;
	return (frac);
}

void			frac_display(char *str)
{
	t_frac *frac;
	int		endian = 1;

	frac = frac_init(str, 0, 0, 0);
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, frac->size, frac->size, "fractol");
	frac->img = mlx_new_image(frac->mlx, frac->size, frac->size);
	int size_line = frac->size * frac->bpp / 8;
	frac->data = mlx_get_data_addr(frac->img, &frac->bpp, &size_line, &endian);
	frac->aff_frac(frac);
	// mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	mlx_key_hook(frac->win, my_key_funct, frac);
	mlx_mouse_hook(frac->win, my_mouse_funct, frac);
	mlx_hook(frac->win, 6, (1L << 6), mouse_pos, frac);
	mlx_loop(frac->mlx);
}
