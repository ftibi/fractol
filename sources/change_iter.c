/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:52:08 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 13:03:47 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_iter(t_frac *frac, int key)
{
	if (key == 24)
	{
		frac->amax += 1;
		frac->aff_frac(frac);
	}
	if (key == 27)
	{
		frac->amax -= 1;
		frac->aff_frac(frac);
	}
}
