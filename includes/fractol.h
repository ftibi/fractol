/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:34:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/19 18:56:06 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_frac
{
	double			size;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;

	double			rc;
	double			ic;

	double			rz;
	double			iz;
	double			z2;

	double			a;
	double			amax;

	double			k;
	double			rz2;

	double			zoom;
	void			*mlx;
	void			*win;
	
	char			*ens;
	int				offx;
	int				offy;

}					t_frac;

t_frac				*frac_init(char* ens, void *mlx, void *win);
void				frac_display(char *av1);
void				aff_frac(t_frac *frac);

int					my_mouse_funct(int button, int x, int y, t_frac *frac);
int					my_key_funct(int keycode, t_frac *param);
#endif
