/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:52:17 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 12:23:06 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_frac		*frac_init(char *ensemble, void *mlx, void *win)
{
	t_frac	*frac;

	if(!(frac = (t_frac*)ft_memalloc(sizeof(t_frac))))
		return (0);
	frac->xmin = -2;
	frac->xmax = 2;
	frac->ymin = -2;
	frac->ymax = 2;
	frac->amax = 200;
	frac->k = 10;
	frac->zoom = 1;
	frac->size = 600;
	frac->ens = ensemble;
	frac->mlx = mlx;
	frac->win = win;
	return (frac);
}



