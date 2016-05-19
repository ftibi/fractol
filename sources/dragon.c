/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:25:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 13:54:22 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_ens		*dragon_un(t_ens *ens)
{
	t_ens	*new;
	t_ens	*start;

	new = new_ens(0, 1);
	start = new;
	while (ens)
	{
		new->next = new_ens(0.5 * (ens->rz - ens->iz), 0.5 *
				(ens->rz + ens->iz));
		new = new->next;
		ens = ens->next;
	}
	return (start);
}

t_ens		*dragon_deux(t_ens *ens)
{
	t_ens	*new;
	t_ens	*start;

	new = new_ens(0, 1);
	start = new;
	while (ens)
	{
		new->next = new_ens(1 - 0.5 * (ens->rz + ens->iz), 0.5 *
				(ens->iz - ens->rz));
		new = new->next;
		ens = ens->next;
	}
	return (start);
}

void		print_ens(t_ens *ens, t_frac *frac)
{
	double	x;
	double	y;
	double	q;

	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	while (ens)
	{
		x = (-frac->xmin + ens->rz) / q;
		y = (-frac->ymin + ens->iz) / q;
		if (x >= 0 && x < frac->size && y >= 0 && y < frac->size)
			my_pixel_put_img(frac, x, y, frac->color);
		ens = ens->next;
	}
}

t_ens		*new_ens(double rz, double iz)
{
	t_ens *new;

	if (!(new = (t_ens*)ft_memalloc(sizeof(t_ens))))
		ft_error("malloc error");
	new->rz = rz;
	new->iz = iz;
	new->next = 0;
	return (new);
}

void		aff_dragon(void *frac2)
{
	t_frac	*frac;
	t_ens	*tmp;
	t_ens	*ens;
	t_ens	*ens1;
	t_ens	*ens2;

	ens = new_ens(0, 1);
	frac = (t_frac*)frac2;
	clear_data(frac->data, frac->size, frac->bpp);
	frac->a = 0;
	while (frac->a < frac->amax)
	{
		ens1 = dragon_un(ens);
		ens2 = dragon_deux(ens);
		ens = ens1;
		tmp = ens;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ens2;
		print_ens(ens, frac);
		frac->a++;
	}
	mlx_clear_window(frac->mlx, frac->win);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}
