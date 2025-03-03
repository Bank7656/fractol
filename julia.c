/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:43:25 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 22:00:31 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t    draw_julia(t_fractol *data);

void    create_julia(t_fractol *data, int32_t is_full_pixel)
{
    int32_t step;
    uint32_t color;
    uint32_t pixel_x;
    uint32_t pixel_y;

    step = 2;
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
			color = draw_julia(data);
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

static uint32_t    draw_julia(t_fractol *data)
{
	long double 	x;
	long double 	y;
	long double 	x_squared;
	long double 	y_squared;
	int32_t iteration;
	int32_t	loop;

	x = data -> scale_x;
	y = data -> scale_y;
	x_squared = x * x;
	y_squared = y * y;
	iteration = 0;
	loop = (data->max_iteration);
	while ((x_squared + y_squared <= 4) && (iteration < loop))
	{
        
        y = (x + x) * y + data->cy;
		x = x_squared - y_squared + data->cx;
        x_squared = x * x;
        y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration, sqrt(x_squared + y_squared)));
}