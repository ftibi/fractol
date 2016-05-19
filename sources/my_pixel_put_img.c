/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:58:19 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 13:08:30 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		my_pixel_put_img(t_frac *frac, int x, int y, int color)
{
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;
	unsigned int	ucolor;

	ucolor = mlx_get_color_value(frac->mlx, color);
	color1 = (ucolor & 0xFF0000) >> 16;
	color2 = (ucolor & 0xFF00) >> 8;
	color3 = (ucolor & 0xFF);
	frac->data[frac->bpp / 8 * (x + (int)frac->size * y)] = color1;
	frac->data[frac->bpp / 8 * (x + (int)frac->size * y) + 1] = color2;
	frac->data[frac->bpp / 8 * (x + (int)frac->size * y) + 2] = color3;
}
