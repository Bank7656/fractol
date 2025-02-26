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

#define WIDTH 1080
#define HEIGHT 720

typedef struct s_range
{
	float x_min;
	float x_max;
	float y_min;
	float y_max;
}   t_range;

typedef struct s_fractol
{
	mlx_t       *mlx;
	mlx_image_t *image;
	int32_t     color_style;
	float		max_iteration;
    uint8_t     *image_buffer;
    float       zoom;
	int32_t		is_zoom;
	float		scale_x;
	float		scale_y;
	t_range     range;
}   t_fractol;


/* main.c */
void    ft_error(void);

/* convert.c*/
float pixel_to_complex_x(t_fractol *data, int32_t x_pixel);
float pixel_to_complex_y(t_fractol *data, int32_t y_pixel);

/* mandelbrot.c */
void    create_mandelbrot(t_fractol *data, int is_full_pixel);

/* color.c */
uint32_t    get_color(t_fractol *data, int32_t iteration, double zn);

/* resize_hook.c */
void	my_resizefunc(int32_t width, int32_t height, void *param);

/* scroll_hook.c */
void    my_scrollhook(double xdelta, double ydelta, void *param);
void	zoom_in(t_fractol *data, float scaled_x, float scaled_y);
void	zoom_out(t_fractol *data, float scaled_x, float scaled_y);

/* loop_hook.c*/
void    my_loophook(void *param);