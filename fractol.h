/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:57:15 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/21 03:03:24thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#endif

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define NONE -1
#define	MANDELBROT 0
#define JULIA 1
#define BURNING_SHIP 2

#define WIDTH 1080
#define HEIGHT 720

typedef struct s_range
{
	long double x_min;
	long double x_max;
	long double y_min;
	long double y_max;
}   t_range;

typedef struct s_fractol
{
	int32_t		plot;
	mlx_t       *mlx;
	mlx_image_t *image;
	int32_t     color_style;
	float		max_iteration;
    float       zoom;
	int32_t		is_new_iteration;
	int32_t		is_zoom;
	int32_t		is_toggle;
	int32_t		is_move;
	long double		scale_x;
	long double		scale_y;
	long double		cx;
	long double		cy;
	t_range     range;
}   t_fractol;


/* main.c */
void		ft_error(void);

/* parser.c */
int32_t		parser(t_fractol *data, char *str);

/* init.c */
void		plot_init(t_fractol *data);

/* convert.c*/
long double		pixel_to_complex_x(t_fractol *data, int32_t x_pixel);
long double		pixel_to_complex_y(t_fractol *data, int32_t y_pixel);

/* mandelbrot.c */
void    	create_mandelbrot(t_fractol *data, int is_full_pixel);

/* julia.c */
void		create_julia(t_fractol *data, int32_t is_full_pixel);

/* toggle.c */
void    toggle_mode(t_fractol *data);

/* color.c */
uint32_t    get_color(t_fractol *data, int32_t iteration, double zn);

/* resize_hook.c */
void		my_resizefunc(int32_t width, int32_t height, void *param);

/* key_hook.c */
void		my_keyhook(mlx_key_data_t keydata, void *param);

/* scroll_hook.c */
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		zoom_in(t_fractol *data, float scaled_x, float scaled_y);
void		zoom_out(t_fractol *data, float scaled_x, float scaled_y);

/* loop_hook.c*/
void		my_loophook(void *param);
void    plot(t_fractol *data, int32_t is_full_pixel);