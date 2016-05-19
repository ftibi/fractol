/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:42:00 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 12:49:57 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	arrow_keys(t_frac *frac, int key)
{
	double offset;

	offset = ft_abs(frac->xmax - frac->xmin) / 10;
	if (key == 123) //gauche
	{
		frac->xmax -= offset;
		frac->xmin -= offset;
		frac->aff_frac(frac);
	}
	if (key == 124) //droite
	{
		frac->xmax += offset;
		frac->xmin += offset;
		frac->aff_frac(frac);
	}
	if (key == 125) //haut
	{
		frac->ymax += offset;
		frac->ymin += offset;
		frac->aff_frac(frac);
	}
	if (key == 126) //bas
	{
		frac->ymax -= offset;
		frac->ymin -= offset;
		frac->aff_frac(frac);
	}
}
