/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 18:57:37 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_frac	*recenter(t_frac *frac, int x, int y)
{
//	double qx;
//	double qy;


//	qx = (frac->xmax - frac->xmin) / frac->size;
//	qy = (frac->ymax - frac->ymin) / frac->size;
//	frac->xmin = (frac->xmax - frac->xmin) * (x / frac->size - 1);
//	frac->xmax = (frac->xmax - frac->xmin) * (x / frac->size);
//	frac->ymin = (frac->ymax - frac->ymin) * (y / frac->size - 1);
//	frac->ymax = (frac->ymax - frac->ymin) * (y / frac->size);
//	frac->xmin = ((frac->xmin + x * qx)) * frac->zoom  - (frac->xmax - frac->xmin) / 2;//* frac->zoom;
//	frac->xmax = ((frac->xmax + x * qx)) * frac->zoom  + (frac->xmax - frac->xmin) / 2;//* frac->zoom;
//	frac->ymin = ((frac->ymin + y * qy)) * frac->zoom  - (frac->ymax - frac->ymin) / 2;//* frac->zoom;
//	frac->ymax = ((frac->ymax + y * qy)) * frac->zoom  + (frac->ymax - frac->ymin) / 2;//* frac->zoom;
//	frac->zoom = 1;
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double zoom;

	xmin = (frac->xmin + x * (frac->xmax - frac->xmin) / frac->size) - (frac->xmax - frac->xmin) / 2;
	xmax = (frac->xmin + x * (frac->xmax - frac->xmin) / frac->size) + (frac->xmax - frac->xmin) / 2;
	ymin = (frac->ymin + y * (frac->ymax - frac->ymin) / frac->size) - (frac->ymax - frac->ymin) / 2;
	ymax = (frac->ymin + y * (frac->ymax - frac->ymin) / frac->size) + (frac->ymax - frac->ymin) / 2;
	zoom = frac->zoom;
	printf("avt frac %f %f %f %f %f\n", frac->zoom, frac->xmin, frac->xmax, frac->ymin, frac->ymax);
	frac = frac_init(frac->ens, frac->mlx, frac->win);
	frac->xmin = xmin;	
	frac->xmax = xmax;	
	frac->ymin = ymin;	
	frac->ymax = ymax;	
	frac->zoom = zoom;
	printf("ap  frac %f %f %f %f %f\n", frac->zoom, frac->xmin, frac->xmax, frac->ymin, frac->ymax);
//	mlx_clear_window(frac->mlx, frac->win);
//	aff_frac(frac);
	return (frac);
}

int		my_key_funct(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	ft_putstr("keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 15)
	{
		mlx_clear_window(frac->mlx, frac->win);
		frac = frac_init(frac->ens, frac->mlx, frac->win);
		aff_frac(frac);
	}
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_frac *frac)
{
//	ft_putstr("button : ");
//	ft_putnbr(button);
//	ft_putchar('\n');
//	ft_putstr("pos x : ");
//	ft_putnbr(x);
//	ft_putstr(" pos y : ");
//	ft_putnbr(y);
//	ft_putchar('\n');
//	printf(" mouse %f %f %f %f %f\n", frac->zoom, frac->xmin, frac->xmax, frac->ymin, frac->ymax);
	frac->offx = x - frac->size / 2;
	frac->offy = y - frac->size / 2;
	printf(" mouse %f %d %d  %d %d\n", frac->zoom,x, y, frac->offx, frac->offy);
	if (button == 7)
	{
		mlx_clear_window(frac->mlx, frac->win);
		if (frac->zoom <= 0.5)
			frac->zoom *= 2;
		else
			frac->zoom += 0.5;
		aff_frac(frac);
	}
	else if (button == 6)
	{
		
		mlx_clear_window(frac->mlx, frac->win);
				if (frac->zoom <= 0.5)
		{
			frac->zoom = frac->zoom / 2.;
		}
		else
			frac->zoom -= 0.5;
		aff_frac(frac);
	}
	else if (button == 1)
	{
		frac->zoom += 1;
		ft_putnbr(frac->zoom);
		ft_putchar('\n');
		mlx_clear_window(frac->mlx, frac->win);
		frac = recenter(frac, x, y);
		aff_frac(frac);
	}
	return (0);
}


