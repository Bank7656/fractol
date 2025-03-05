/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:02:58 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/06 01:04:02 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fill_image(t_fractol *data, uint32_t x, uint32_t y, uint32_t color);
static uint32_t	draw_fractal(t_fractol *data);

void    plot(t_fractol *data, int32_t is_full_pixel)
{
	int32_t     step;
	uint32_t	pixel_x;
	uint32_t	pixel_y;
	uint32_t	color;

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
			color = draw_fractal(data);
			mlx_put_pixel(data->image, pixel_x, pixel_y, color);
			if (is_full_pixel == 0)
				fill_image(data, pixel_x, pixel_y, color);
			pixel_x += step;
		}
		pixel_y += step;
	}
}

static uint32_t    draw_fractal(t_fractol *data)
{
	if (data->plot == MANDELBROT)
	   return (draw_mandelbrot(data));
	else if (data->plot == JULIA)
		return (draw_julia(data));
	else if (data->plot == BURNING_SHIP)
		return (draw_burning_ship(data));
	return (0); 
}

static void fill_image(t_fractol *data, uint32_t x, uint32_t y, uint32_t color)
{
	int dx;
	int dy;
	int step;

	step = 2;
	dy = 0;
	while (dy < step)
	{
		dx = 0;
		while (dx < step)
		{
			if (x + dx < data->mlx->width && y + dy < data->mlx->height)
				mlx_put_pixel(data->image, x + dx, y + dy, color); 
			dx++;
		}
		dy++;
	}
}