/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:29:02 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 12:28:35 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clear_data(char *data, int size, int bpp)
{
	int	i;

	i = 0;
	while (i < size * size * bpp / 8)
	{
		data[i] = 0;
		i++;
	}
}
