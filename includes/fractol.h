/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:34:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/26 19:44:10 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# define WIN_SIZE 800

typedef void			(t_frac_fct_ptr)(void *frac);
struct					s_frac
{
	double				size;
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;

	double				rc;
	double				ic;

	double				rz;
	double				iz;
	double				z2;

	double				a;
	double				amax;

	double				k;
	double				rz2;

	double				zoom;
	void				*mlx;
	void				*win;

	char				*ens;
	double				offx;
	double				offy;

	double				xpoint;
	double				ypoint;

	double				juliax;
	double				juliay;
	int					juliamove;

	t_frac_fct_ptr		*aff_frac;
};
typedef struct s_frac	t_frac;

double					ft_abs(double a);
t_frac					*frac_init(char *ens, void *mlx, void *win);
void					frac_display(char *av1);
void					aff_frac_julia(void *frac);
void					aff_frac_mandel(void *frac);
void					aff_dragon(void *frac);

int						my_mouse_funct(int button, int x, int y, t_frac *frac);
int						my_key_funct(int keycode, t_frac *param);
int						mouse_pos(int x, int y, t_frac *frac);
t_frac					*zoom_frac(t_frac *frac);
void					ft_error(char *str);
void					in_loop(t_frac *frac, double x, double y);
void					manuel(void);

typedef struct s_ens
{
	double rz;
	double iz;
	struct s_ens *next;
}				t_ens;
t_ens					*new_ens(double rz, double iz);

#endif
