/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:44:00 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/24 16:45:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t    draw_mandelbrot(t_fractol *data, float x0, float y0);

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