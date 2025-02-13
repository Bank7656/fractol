/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:57:51 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/13 21:48:00 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ft_error(void)
{
	// ft_putstr_fd(mlx_sterror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Get the red channel.
int get_r(int rgba)
{
    // Move 3 bytes to the right and mask out the first byte.
    return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
    // Move 2 bytes to the right and mask out the first byte.
    return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
    // Move 1 byte to the right and mask out the first byte.
    return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
    // Move 0 bytes to the right and mask out the first byte.
    return (rgba & 0xFF);
}

#include <stdio.h>


void	get_background(mlx_image_t *image, int rgba)
{
	int	x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(image, x, y, rgba);
			x++;	
		}
		y++;
	}
}

void	draw_axis(mlx_image_t *image)
{
	int	x;
	int	y;
	int	mid_x;
	int mid_y;

	x = 0;
	y = 0;
	mid_x = WIDTH / 2;
	mid_y = HEIGHT / 2;
	while (x < WIDTH)
	{
		mlx_put_pixel(image, x, mid_y, 0xFFFFFFFF);
		x++;
	}
	while (y < HEIGHT)
	{
		mlx_put_pixel(image, mid_x, y, 0xFFFFFFFF);
		y++;
	}
}

int mandelbrot(float x0, float y0)
{
	int		i;
	float x;
	float y;
	float x2;
	float y2;
	
	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;

	i = 0;
	while ((x2 + y2) <= 4 && (i < MAX_ITERATION))
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		i++;
	}
	return i;
}

int get_gradient(int i)
{
	int r;
	int g;
	int b;
	int a;

	r = (i * 255) / MAX_ITERATION;
	g = (i * 128) / MAX_ITERATION;
	b = (i * 64) / MAX_ITERATION;
	a = 255;

	return (r << 24) | (g << 16) | (b << 8) | a;
}

void	draw_mandelbrot(mlx_image_t *image, double center_x, double center_y, float zoom)
{
	// t_complex number;
	int	x;
	int	y;
	int	i;
	int color;

	float scale_x = (3 / zoom) / WIDTH; // Scale to (-2.00, 1)
	float scale_y = (3 / zoom) / HEIGHT;// Scale to (-1.5, 1.5)
	float real;
	float imaginary;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = center_x - (2.00 / zoom) + x * scale_x;
			imaginary = center_y - (1.5 / zoom) + y * scale_y;
			i = mandelbrot(real, imaginary);
			if (i == MAX_ITERATION)
				color = BLACK;
			else
				color = get_gradient(i);
			mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}

	
}


void my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_data 		data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!(data.mlx))
		ft_error();
	
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);

	get_background(data.img, 0xFFFFFFFF);
	
	if (!(data.img) || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
		ft_error();
		
	draw_mandelbrot(data.img, 0.0, 0.0, 1.0);
		
	
	mlx_key_hook(data.mlx, &my_keyhook, NULL);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}