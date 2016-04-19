/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:52:17 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 15:59:07 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_frac		*frac_init(char *ensemble, void *mlx, void *win)
{
	t_frac	*frac;

	if(!(frac = (t_frac*)ft_memalloc(sizeof(t_frac))))
		return (0);
	frac->size = 600;
	frac->xmin = -2.;
	frac->xmax = 2.;
	frac->ymin = -2.;
	frac->ymax = 2.;
	frac->rc = 0;
	frac->ic = 0;

	frac->rz = 0;
	frac->iz = 0;
	frac->z2 = 0;
	frac->rz2 = 0;

	frac->amax = 200;
	frac->a = 0;

	frac->k = 10;
	frac->zoom = 1;
	frac->mlx = mlx;
	frac->win = win;
	
	frac->ens = ensemble;
	return (frac);
}



