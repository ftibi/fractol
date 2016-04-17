/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 18:36:10 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/17 18:51:54 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	if (button == 1)
	{
		frac->zoom += 0.5;
		mlx_clear_window(frac->mlx, frac->win);
		frac_display(frac);
	}
	return (0);
}


