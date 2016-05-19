/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:56:11 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 14:10:02 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_color(t_frac *frac, int key)
{
	if (key == 8)
	{
		frac->color *= 2;
		if (frac->color == 0)
			frac->color = 0xFFFFFF;
		frac->aff_frac(frac);
	}
}
