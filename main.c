/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:57:51 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/20 03:26:57 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

uint32_t	billionear_interpolate(mlx_image_t *image, double x, double y);

void	ft_error(void)
{
	// ft_putstr_fd(mlx_sterror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}



uint32_t	bilinear_interpolate(t_data *data, double x, double y)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (int)(x);
	y1 = (int)(y);
	x2 = x1 + 1;
	y2 = y1 + 1;
	// x1 = (int)floor(x);
	// y1 = (int)floor(y);
	// x2 = (int)(fmin(x1 + 1, WIDTH - 1));
	// y2 = (int)(fmin(y1 + 1, HEIGHT - 1));

	// x1 = fmax(0, fmin(WIDTH - 1, x1));
	// y1 = fmax(0, fmin(HEIGHT - 1, y1));
	// x2 = fmax(0, fmin(WIDTH - 1, x2));
	// y2 = fmax(0, fmin(HEIGHT - 1, y2));
	// if (x1 < 0 || y1 < 0 || x2 >= WIDTH || y2 >= HEIGHT)
	// 	return (0xFF0000FF);
	
    // if (x1 < 0) x1 = 0;
    // if (y1 < 0) y1 = 0;
	if (x2 >= WIDTH)
		x2 = WIDTH - 1;
	if (y2 >= HEIGHT)
		y2 = HEIGHT - 1;

	double dx = x - x1;
	double dy = y - y1;
	
    uint8_t *pixels = data -> prev_pixels;

    uint32_t idx11 = (y1 * data -> img -> width + x1) * 4;
    uint32_t idx21 = (y1 * data -> img -> width + x2) * 4;
    uint32_t idx12 = (y2 * data -> img -> width + x1) * 4;
    uint32_t idx22 = (y2 * data -> img -> width + x2) * 4;

    uint8_t r11 = pixels[idx11], g11 = pixels[idx11 + 1], b11 = pixels[idx11 + 2];
    uint8_t r21 = pixels[idx21], g21 = pixels[idx21 + 1], b21 = pixels[idx21 + 2];
    uint8_t r12 = pixels[idx12], g12 = pixels[idx12 + 1], b12 = pixels[idx12 + 2];
    uint8_t r22 = pixels[idx22], g22 = pixels[idx22 + 1], b22 = pixels[idx22 + 2];

    // Bilinear interpolation on each color channel
	uint8_t r = (uint8_t)((1 - dx) * (1 - dy) * r11 + dx * (1 - dy) * r21 + (1 - dx) * dy * r12 + dx * dy * r22);
	uint8_t g = (uint8_t)((1 - dx) * (1 - dy) * g11 + dx * (1 - dy) * g21 + (1 - dx) * dy * g12 + dx * dy * g22);
	uint8_t b = (uint8_t)((1 - dx) * (1 - dy) * b11 + dx * (1 - dy) * b21 + (1 - dx) * dy * b12 + dx * dy * b22);
	

    // Return the color in RGBA format
    return (r << 24) | (g << 16) | (b << 8) | 255;
}

void 	zoom_mandelbrot(t_data *data, double scale)
{
	int	x;
	int	y;
	double scale_x;
	double scale_y;

	double center_x = data -> img -> width / 2.0;
	double center_y = data -> img -> height / 2.0;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			scale_x = center_x + (x - center_x) / scale;
			scale_y = center_y + (y - center_y) / scale;
			// scale_x = fmax(0, fmin(WIDTH - 1, scale_x));
			// scale_y = fmax(0, fmin(HEIGHT - 1, scale_y));

			// Debugging: print the scale_x and scale_y for each pixel
			// printf("scale_x: %f, scale_y: %f\n", scale_x, scale_y);
			// uint32_t color = bilinear_interpolate(data, scale_x, scale_y);
			// mlx_put_pixel(data->img, x, y, color);

            if (scale_x < 0 || scale_x >= WIDTH || scale_y < 0 || scale_y >= HEIGHT) {
				mlx_put_pixel(data->img, x, y, 0xFF0000FF);  // Black if out of bounds
            } else {
				uint32_t color = bilinear_interpolate(data, scale_x, scale_y);
                mlx_put_pixel(data->img, x, y, color);
            }
			x++;
		}
		y++;
	}
}

void	zoom(t_data *data, int is_zoom_in)
{
	// ft_memset(data -> prev_pixels, BLACK, WIDTH * HEIGHT * sizeof(uint8_t));
	ft_memmove(data -> prev_pixels, data -> img -> pixels, WIDTH * HEIGHT * sizeof(uint8_t) * 4);
	if (is_zoom_in == 1)
	{
		zoom_mandelbrot(data, 1.05);
		data -> zoom *= 1.05;
	}	
	else if (is_zoom_in == -1)
	{
		zoom_mandelbrot(data, 0.95);
		data -> zoom /= 1.05;
	}
	
	return ;
}




int	main(void)
{
	t_data 		data;

	data.center_real = 0.0;
	data.center_imag = 0.0;
	data.zoom = 1.0;
	data.move_keys[0] = false;
	data.move_keys[1] = false;
	data.move_keys[2] = false;
	data.move_keys[3] = false;
	data.zoom_keys = 0;
	data.prev_pixels = (uint8_t *)malloc(WIDTH * HEIGHT * sizeof(uint8_t) * 4);
	if (data.prev_pixels == NULL)
		exit(EXIT_FAILURE);
	ft_bzero(data.prev_pixels, WIDTH * HEIGHT * sizeof(uint8_t) * 4);
	data.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!(data.mlx))
		ft_error();
	
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	
	if (!(data.img) || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
		ft_error();
		
	draw_mandelbrot(data.img, data.center_real, data.center_imag, 1.0);
	// free(data.prev_pixels);
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	mlx_loop_hook(data.mlx, &update, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}