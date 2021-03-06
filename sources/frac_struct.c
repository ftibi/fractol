/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:52:17 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 14:13:07 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

static t_frac	*frac_init3(char *ensemble, t_frac *frac, void *img)
{
	frac->color = 0xFFFFFF;
	frac->endian = 1;
	frac->offx = 0;
	frac->offy = 0;
	ensemble++;
	img++;
	return (frac);
}

static t_frac	*frac_init2(char *ensemble, t_frac *frac, void *img)
{
	int size_line;

	size_line = frac->size * frac->bpp / 8;
	frac = frac_init3(ensemble, frac, img);
	frac->juliax = 0.285;
	frac->juliay = 0.01;
	frac->juliamove = 1;
	frac->xpoint = 0;
	frac->ypoint = 0;
	frac->img = img;
	frac->data = 0;
	if (frac->img)
		frac->data = mlx_get_data_addr(frac->img, &frac->bpp, &size_line,
			&frac->endian);
	frac->bpp = 32;
	frac->ens = ft_strdup(ensemble);
	if (!ft_strcmp(ensemble, "julia"))
		frac->aff_frac = aff_frac_julia;
	else if (!ft_strcmp(ensemble, "mandelbrot"))
		frac->aff_frac = aff_frac_mandel;
	else if (!ft_strcmp(ensemble, "dragon"))
		frac->aff_frac = aff_dragon;
	return (frac);
}

t_frac			*frac_init(char *ensemble, void *mlx, void *win, void *img)
{
	t_frac	*frac;

	if (!(frac = (t_frac*)ft_memalloc(sizeof(t_frac))))
		ft_error("malloc error");
	frac->size = WIN_SIZE;
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
	frac->amax = 50;
	if (!ft_strcmp(ensemble, "dragon"))
		frac->amax = 15;
	frac->a = 0;
	frac->k = 10;
	frac->zoom = 1;
	frac->mlx = mlx;
	frac->win = win;
	frac = frac_init2(ensemble, frac, img);
	return (frac);
}
