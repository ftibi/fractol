/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:25:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/26 19:10:04 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


t_ens	*dragon_un(t_ens *ens)
{
	t_ens	*new;
	
	new = new_ens(0.5 * (ens->rz - ens->iz), 0.5 * (ens->rz + ens->iz));
	return (new);
}

t_ens	*dragon_deux(t_ens *ens)
{
	t_ens	*new;
	
	new = new_ens(1 - 0.5 * (ens->rz + ens->iz), 0.5 * (ens->iz - ens->rz));
	return (new);
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

	new = (t_ens*)ft_memalloc(sizeof(t_ens));
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
	double	x;
	double	y;
	t_frac	*frac;
	double	q;
	int 	a;

	frac = (t_frac*)frac2;
	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	a = 0;

	t_ens *ens = new_ens(0, 1);
	t_ens *ens1 = new_ens(0, 1);
	t_ens *ens2 = new_ens(0, 1);
	
	while (a < frac->amax)
	{

		a++;
	}







}


