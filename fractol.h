/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 05:24:14 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 05:49:07 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2
# define TRICORN 3

# define WIDTH 1024
# define HEIGHT 768

# define ZOOM_MIN_RANGE 1.0E-10L
# define ZOOM_MAX_RANGE 5.0L

typedef struct s_range
{
	long double	x_min;
	long double	x_max;
	long double	y_min;
	long double	y_max;
}	t_range;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_range			range;
	int32_t			plot;
	int32_t			color_style;
	int32_t			is_new_iteration;
	int32_t			is_zoom;
	int32_t			is_toggle;
	int32_t			is_move;
	float			max_iteration;
	long double		zoom;
	long double		scale_x;
	long double		scale_y;
	long double		cx;
	long double		cy;
}	t_fractol;

/* main.c */
void			ft_error(t_fractol *data);

/* prompt.c */
void			instruction(void);
int				usage_prompt(void);

/* my_atof.c*/
double			my_atof(const char *str);

/* parser.c */
int32_t			parser(t_fractol *data, int argc, char *argv[]);

/* init.c */
void			plot_init(t_fractol *data);

/* convert.c*/
long double		pixel_to_complex_x(t_fractol *data, int32_t x_pixel);
long double		pixel_to_complex_y(t_fractol *data, int32_t y_pixel);

/* mandelbrot.c */
uint32_t		draw_mandelbrot(t_fractol *data);

/* julia.c */
uint32_t		draw_julia(t_fractol *data);

/* burning_ship.c*/
uint32_t		draw_burning_ship(t_fractol *data);

/* tricorn.c*/
uint32_t		draw_tricorn(t_fractol *data);

/* toggle.c */
void			toggle_mode(t_fractol *data);

/* color.c */
uint32_t		get_color(t_fractol *data, int32_t iteration);

/* key_hook.c */
void			my_keyhook(mlx_key_data_t keydata, void *param);

/* scroll_hook.c */
void			my_scrollhook(double xdelta, double ydelta, void *param);
void			zoom_in(t_fractol *data, float scaled_x, float scaled_y);
void			zoom_out(t_fractol *data, float scaled_x, float scaled_y);

/* close_hook.c */
void			my_closehook(void *param);

/* loop_hook.c*/
void			my_loophook(void *param);
void			plot(t_fractol *data, int32_t is_full_pixel);
#endif
