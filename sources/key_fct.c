/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/17 19:50:10 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_frac	*recenter(t_frac *frac, int x, int y)
{
	frac->xmin = (frac->xmax - frac->xmin) * (x / frac->size - 1);
	frac->xmax = (frac->xmax - frac->xmin) * (x / frac->size);
	frac->ymin = (frac->ymax - frac->ymin) * (y / frac->size - 1);
	frac->ymax = (frac->ymax - frac->ymin) * (y / frac->size);
	y++;
	return (frac);
}

int		my_key_funct(int keycode, t_frac *frac)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	frac++;
	return (0);
}

int		my_mouse_funct(int button, int x, int y, t_frac *frac)
{
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putstr("pos x : ");
	ft_putnbr(x);
	ft_putstr(" pos y : ");
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 7)
	{
		frac->zoom += 0.5;
		mlx_clear_window(frac->mlx, frac->win);
		frac = recenter(frac, x, y);
		frac_display(frac);
	}
	if (button == 6)
	{
		frac->zoom -= 0.5;
		mlx_clear_window(frac->mlx, frac->win);
		frac = recenter(frac, x, y);
		frac_display(frac);
	}
	return (0);
}


