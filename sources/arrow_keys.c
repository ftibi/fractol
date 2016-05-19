/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:42:00 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 13:11:08 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	arrow_keys(t_frac *frac, int key)
{
	double offset;

	offset = ft_abs(frac->xmax - frac->xmin) / 10;
	if (key == 123)
	{
		frac->xmax -= offset;
		frac->xmin -= offset;
	}
	if (key == 124)
	{
		frac->xmax += offset;
		frac->xmin += offset;
	}
	if (key == 125)
	{
		frac->ymax += offset;
		frac->ymin += offset;
	}
	if (key == 126)
	{
		frac->ymax -= offset;
		frac->ymin -= offset;
	}
	if (key == 123 || key == 124 || key == 125 || key == 126)
		frac->aff_frac(frac);
}
