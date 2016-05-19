/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manuel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:34:24 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 15:11:25 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	manuel(void)
{
	ft_putendl("use mousewheel to zoom in and out");
	ft_putendl("use arrow keys to move around");
	ft_putendl("J   : toggle Julia's parameter change");
	ft_putendl("K   : reset Julia's parameters");
	ft_putendl("+ - : change interrations");
	ft_putendl("C   : change color panel");
	ft_putendl("ESC : exit");
}
