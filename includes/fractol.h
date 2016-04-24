/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:34:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 17:45:50 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# define PointerMotionMask (1L<<6)
# define MotionNotify 6

typedef void(frac_fct_ptr)(void *frac);
struct		s_frac
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
	double			offx;
	double			offy;

	double			juliax;
	double			juliay;

	int				paramchange; //a utiliser pour Julia
	frac_fct_ptr	*aff_frac;
};		
typedef struct s_frac	t_frac;

t_frac				*frac_init(char* ens, void *mlx, void *win);
void				frac_display(char *av1);
void				aff_frac_julia(void *frac);
void				aff_frac_mandel(void *frac);

int					my_mouse_funct(int button, int x, int y, t_frac *frac);
int					my_key_funct(int keycode, t_frac *param);
int					mouse_pos(int x, int y, t_frac *frac);
#endif
