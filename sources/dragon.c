/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:25:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/26 16:45:28 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	aff_dragon(void *frac2)
{
	double	x;
	double	y;
	t_frac	*frac;
	double	q;

	frac = (t_frac*)frac2;
	q = ft_abs((frac->xmax - frac->xmin) / frac->size);
	x = 0;
	while (x < frac->size)
	{
		y = 0;
		while (y < frac->size)
		{
			frac->rz = frac->xmin + x * q;
			frac->iz = frac->ymin + y * q;
			y++;
		}
		x++;
	}
}

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
