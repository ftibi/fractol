/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:58:19 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/18 18:30:47 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		my_pixel_put_img(t_frac *frac, int x, int y, int color)
{
	unsigned char	color1;
	unsigned char	color2;
	unsigned char	color3;

	color1 = (color & 0xFF000000) >> 24;
	color2 = (color & 0xFF000000) >> 16;
	color3 = (color & 0xFF000000) >> 8;
	frac->data[x * frac->bpp / 8 + (int)frac->size * y] = mlx_get_color_value(frac->mlx, color);
	// frac->data[(int)frac->size * y + x * frac->bpp / 8 ] = (unsigned char)color;
	// frac->data[x * frac->bpp / 8 + (int)frac->size * y] = (unsigned char)color1;
	// frac->data[x * frac->bpp / 8 + (int)frac->size * y + 1] = (unsigned char)color2;
	// frac->data[x * frac->bpp / 8 + (int)frac->size * y + 2] = (unsigned char)color3;
}
