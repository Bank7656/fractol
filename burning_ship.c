/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:45:06 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/04 02:35:46 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t    draw_burning_ship(t_fractol *data);

void    create_burning_ship(t_fractol *data, int is_full_pixel)
{
    long double		scaled_x;
	long double		scaled_y;
	uint32_t	pixel_x;
	uint32_t	pixel_y;
	uint32_t	color;

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
			data->scale_x = pixel_to_complex_x(data, pixel_x);
			data->scale_y = pixel_to_complex_y(data, pixel_y);
			color = draw_burning_ship(data);
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
	Using escape time algorithm to calculate burning ship set
*/
static uint32_t    draw_burning_ship(t_fractol *data)
{
	long double 	x;
	long double 	y;
	long double 	x_squared;
	long double 	y_squared;
    long double     x_temp;
	int32_t iteration;
	int32_t	loop;

	x = 0;
	y = 0;
	x_squared = 0;
	y_squared = 0;
	iteration = 0;
	loop = (data->max_iteration);
	while ((x_squared + y_squared < 4) && (iteration < loop))
	{
        x_temp = x * x - y * y + data->scale_x;
		y = fabs((x + x) * y) - data->scale_y;
		x = fabs(x_temp);
		x_squared = x * x;
		y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration, sqrt(x_squared + y_squared)));
}