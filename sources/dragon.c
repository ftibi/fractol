/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:25:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/26 19:53:28 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


t_ens	*dragon_un(t_ens *ens)
{
	t_ens	*new;
	t_ens	*start;

	new = new_ens(0, 1);
	start = new;
	while (ens)
	{
		new->next = new_ens(0.5 * (ens->rz - ens->iz), 0.5 * (ens->rz + ens->iz));
		new = new->next;
		ens = ens->next;
	}
	return (start);
}

t_ens	*dragon_deux(t_ens *ens)
{
	t_ens	*new;
	t_ens	*start;

	new = new_ens(0, 1);
	start = new;
	while (ens)
	{
		new->next = new_ens(1 - 0.5 * (ens->rz + ens->iz), 0.5 * (ens->iz - ens->rz));
		new = new->next;
		ens = ens->next;
	}
	return (start);
}

void	print_ens(t_ens *ens, t_frac *frac)
{
	double	x;
	double	y;
	double	q;

	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	while (ens)
	{
		x = ens->rz / q;
		y = ens->iz / q;
		mlx_pixel_put(frac->mlx, frac->win, x, y, 0xFFFFFF);
		ens = ens->next;
	}
}

t_ens *new_ens(double rz, double iz)
{
	t_ens *new;

	if (!(new = (t_ens*)ft_memalloc(sizeof(t_ens))))
		ft_error("malloc error");
	new->rz = rz;
	new->iz = iz;
	new->next = 0;
	return (new);
}

t_ens *add_ens(t_ens *ens, t_ens *ens2)
{
	t_ens	*tmp;

	tmp = ens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ens2;
	return (ens);
}

void	aff_dragon(void *frac2)
{
	t_frac	*frac;
	int 	a;
	t_ens	*tmp;

	frac = (t_frac*)frac2;
	frac->amax = 25;
	t_ens *ens = new_ens(0, 1);
	t_ens *ens1 = new_ens(0, 1);
	t_ens *ens2 = new_ens(0, 1);
	a = 0;
	while (a < frac->amax)
	{
		ens1 = dragon_un(ens);
		ens2 = dragon_deux(ens);
		ens = ens1;
		tmp = ens;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ens2;
		print_ens(ens, frac);
		a++;
	}
}
