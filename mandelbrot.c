/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:44:00 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/27 03:46:07 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t    draw_mandelbrot(t_fractol *data, float x0, float y0);

/*
   Create mandelbrot set by looping each pixel that appear on the window
*/
void    create_mandelbrot(t_fractol *data, int is_full_pixel)
{
	float		scaled_x;
	float		scaled_y;
	uint32_t	pixel_x;
	uint32_t	pixel_y;
	uint32_t	color;

	// int step = (int)(data->zoom * 2);  // Adjust scaling factor as needed
	int step = 2;  // Adjust scaling factor as needed
	// if (step < 1) step = 1;	

	if (is_full_pixel == 1)
		step = 1;

	pixel_y = 0;
	while (pixel_y < data->mlx->height)
	{
		pixel_x = 0;
		while (pixel_x < data->mlx->width)
		{
			scaled_x = pixel_to_complex_x(data, pixel_x);
			scaled_y = pixel_to_complex_y(data, pixel_y);
			color = draw_mandelbrot(data, scaled_x, scaled_y);
			mlx_put_pixel(data->image, pixel_x, pixel_y, color);
			if (is_full_pixel == 0)
			{				
				for (int dy = 0; dy < step; dy++) {
				    for (int dx = 0; dx < step; dx++) {
				        if (pixel_x + dx < data->mlx->width && pixel_y + dy < data->mlx->height) {
				            mlx_put_pixel(data->image, pixel_x + dx, pixel_y + dy, color);
				        }
				    }
				}
			}
			pixel_x += step;
		}
		pixel_y += step;
	}    
}

/*
	Using escape time algorithm to calculate mandelbrot set
*/
static uint32_t    draw_mandelbrot(t_fractol *data, float x0, float y0)
{
	float 	x;
	float 	y;
	float 	x_squared;
	float 	y_squared;
	int32_t iteration;
	int32_t	loop;

	x = 0;
	y = 0;
	x_squared = 0;
	y_squared = 0;
	iteration = 0;
	loop = (data->max_iteration);
	while ((x_squared + y_squared <= 4) && (iteration < loop))
	{
		y = (x + x) * y + y0;
		x = x_squared - y_squared + x0;
		x_squared = x * x;
		y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration, sqrt(x_squared + y_squared)));
}