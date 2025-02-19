/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:57:15 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/20 03:02:14 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#endif

#define MAX_ITERATION 100
#define MOVE_SPEED 0.05
#define WIDTH 1080
#define HEIGHT 720
#define BPP sizeof(int32_t)

#define BLACK 0x000000FF

#include <math.h>
#include <stdbool.h>

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
    float center_real;
    float center_imag;
    float zoom;
    bool    move_keys[4];
    int    zoom_keys;
    uint8_t   *prev_pixels;
    mlx_t       *mlx;
    mlx_image_t *img;
}   t_data;

int mandelbrot(float x0, float y0);
void	draw_mandelbrot(mlx_image_t *image, double center_x, double center_y, float zoom);


void my_keyhook(mlx_key_data_t keydata, void *param);
void	set_move_key(mlx_key_data_t keydata, bool *move_keys, int pressed);
void	zoom(t_data *data, int is_zoom_in);
void	update(void *param);

int get_gradient(int i);
