/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:18:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/24 15:55:46 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	int32_t     max_iteration;
	t_range     range;
}   t_fractol;


void    create_mandelbrot(t_fractol *data);

static void ft_error(void)
{
	exit(EXIT_FAILURE);
}

void	my_resizefunc(int32_t width, int32_t height, void* param)
{
	t_fractol *data;

	data = (t_fractol *)param;
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, width, height);
	if (data->image == NULL)
		ft_error();
	data->mlx->width = width;
	data->mlx->height = height;
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		ft_error();
	create_mandelbrot(data);
}

int main(int argc, char *argv[])
{
	t_fractol   data;

	// Initialize
	data.color_style = 0;
	data.range.x_min = -2;
	data.range.x_max = 0.5;
	data.range.y_min = -1.12;
	data.range.y_max = 1.12;
	data.max_iteration = 100;
	// Init mlx
	data.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (data.mlx == NULL)
		return (EXIT_FAILURE);
	// Create image
	printf("width:%i height:%i\n", data.mlx->width, data.mlx->height);
	data.image = mlx_new_image(data.mlx, data.mlx->width, data.mlx->height);
	if (data.image == NULL)
		return (EXIT_FAILURE);
	// Put image to window
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
		return (EXIT_FAILURE);

	// Create mandelbrot
	create_mandelbrot(&data);
	mlx_resize_hook(data.mlx, &my_resizefunc, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);    
}

uint32_t    black_red_gradient(t_fractol *data, int32_t iteration)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;

	if (iteration == data->max_iteration)
		return (0x000000FF);
	r = (iteration * 255) / data->max_iteration;
	g = (iteration * 128) / data->max_iteration;
	b = (iteration * 64) / data->max_iteration;

	return ((r << 24) | (g << 16) | (b << 8) | 255);
}


/*
	Parsing to each color style
*/
uint32_t    get_color(t_fractol *data, int32_t iteration)
{
	if (data->color_style == 0)
		return (black_red_gradient(data, iteration));
	return (0xFF0000FF);
}

/*
	Using escape time algorithm to calculate mandelbrot set
*/
uint32_t    draw_mandelbrot(t_fractol *data, float x0, float y0)
{
	float 	x;
	float 	y;
	float 	x_squared;
	float 	y_squared;
	int32_t iteration;

	x = 0;
	y = 0;
	x_squared = 0;
	y_squared = 0;
	iteration = 0;
	while ((x_squared + y_squared <= 4) && (iteration < data->max_iteration))
	{
		y = (x + x) * y + y0;
		x = x_squared - y_squared + x0;
		x_squared = x * x;
		y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration));
}


float pixel_to_complex_x(t_fractol *data, int32_t x_pixel)
{
	float min;
	float max;
	float complex_x;
	
	min = data->range.x_min;
	max = data->range.x_max;
	complex_x = min + ((max - min) * ((float)x_pixel / data->mlx->width));
	return (complex_x);    
}

float pixel_to_complex_y(t_fractol *data, int32_t y_pixel)
{
	float min;
	float max;
	float complex_y;

	min = data->range.y_min;
	max = data->range.y_max;
	complex_y = max - ((max - min) * ((float)y_pixel/ data->mlx->height));
	return (complex_y);    
}

/*
   Create mandelbrot set by looping each pixel that appear on the window
*/
void    create_mandelbrot(t_fractol *data)
{
	float		scaled_x;
	float		scaled_y;
	uint32_t	pixel_x;
	uint32_t	pixel_y;
	uint32_t	color;
	
	pixel_y = -1;
	while (++pixel_y < data->mlx->height)
	{
		pixel_x = -1;
		while (++pixel_x < data->mlx->width)
		{
			scaled_x = pixel_to_complex_x(data, pixel_x);
			scaled_y = pixel_to_complex_y(data, pixel_y);
			color = draw_mandelbrot(data, scaled_x, scaled_y);
			mlx_put_pixel(data->image, pixel_x, pixel_y, color);
		}
	}    
}