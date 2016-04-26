/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:25:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/26 18:25:41 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


t_frac	*dragon_un(t_frac *frac)
{
	double	rz_save;

	rz_save = frac->rz;
	frac->rz = 0.5 * (frac->rz - frac->iz);
	frac->iz = 0.5 * (rz_save + frac->iz);
	return (frac);
}

t_frac	*dragon_deux(t_frac *frac)
{
	double	rz_save;
	
	rz_save = frac->rz;
	frac->rz = 1 - 0.5 * (frac->rz + frac->iz);
	frac->iz = 0.5 * (rz_save - frac->iz);
	return (frac);
}

typedef struct s_ens
{
	double rz;
	double iz;
	struct s_ens *next;
}				t_ens;

t_ens *new_ens(int rz, int iz)
{
	t_ens *new;

	new = (t_ens*)ft_memalloc(sizeof(t_ens));
	new->rz = rz;
	new->iz = iz;
	new->next = 0;
	return (new);
}

t_ens *add_ens(t_ens *ens, int rz, int iz)
{
	t_ens	*tmp;

	tmp = ens;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_ens(rz, iz);
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
	while (a < frac->amax)
	{
		ens = add_ens(ens,x, y);

		a++;
	}







}


