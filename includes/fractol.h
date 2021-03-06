/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:34:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/05/19 13:59:38 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
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
	void				*img;
	char				*data;
	int					bpp;

	char				*ens;
	double				offx;
	double				offy;

	double				xpoint;
	double				ypoint;

	double				juliax;
	double				juliay;
	int					juliamove;
	int					endian;
	int					color;

	t_frac_fct_ptr		*aff_frac;
};
typedef struct s_frac	t_frac;

double					ft_abs(double a);
t_frac					*frac_init(char *ens, void *mlx, void *win, void *img);
void					frac_display(char *av1);
void					aff_frac_julia(void *frac);
void					aff_frac_mandel(void *frac);
void					aff_dragon(void *frac);

int						my_mouse_funct(int button, int x, int y, t_frac *frac);
int						my_key_funct(int keycode, t_frac *param);
void					arrow_keys(t_frac *frac, int key);
void					change_iter(t_frac *frac, int key);
void					change_color(t_frac *frac, int key);
int						mouse_pos(int x, int y, t_frac *frac);
t_frac					*zoom_frac(t_frac *frac);
void					ft_error(char *str);
void					in_loop(t_frac *frac, double x, double y);
void					manuel(void);
void					frac_reset(t_frac *frac);

typedef struct			s_ens
{
	double				rz;
	double				iz;
	struct s_ens		*next;
}						t_ens;
t_ens					*new_ens(double rz, double iz);

void					my_pixel_put_img(t_frac *frac, int x, int y, int color);
void					clear_data(char *data, int size, int bpp);

#endif
