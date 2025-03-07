/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:31:24 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 22:55:57 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static void	zoom_in(t_fractol *data, float scaled_x, float scaled_y);
void	zoom_in(t_fractol *data, float mouse_x, float mouse_y);
// void	zoom_in(t_fractol *data, float scaled_x, float scaled_y);
uint32_t	bilinear_interpolate(t_fractol *data, float x, float y);
void	zoom_out(t_fractol *data, float x, float y);

void    my_scrollhook(double xdelta, double ydelta, void* param)
{
	int32_t mouse_x;
	int32_t mouse_y;
	t_fractol *data;
	long double	zoom_factor;

	(void)xdelta;
	data = (t_fractol *)param;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.1;
	data->zoom *= zoom_factor;
	if (data->zoom > ZOOM_MAX_RANGE)
	{
		data->zoom = ZOOM_MAX_RANGE;
		return;
	}
	else if (data->zoom < ZOOM_MIN_RANGE)
	{
		data->zoom = ZOOM_MIN_RANGE;
		return;
	}
	data -> scale_x = pixel_to_complex_x(data, mouse_x);
	data -> scale_y = pixel_to_complex_y(data, mouse_y);
	data->range.x_min = data -> scale_x + (data->range.x_min - data -> scale_x) * zoom_factor;
	data->range.x_max = data -> scale_x + (data->range.x_max - data -> scale_x) * zoom_factor;
	data->range.y_min = data -> scale_y + (data->range.y_min - data -> scale_y) * zoom_factor;
	data->range.y_max = data -> scale_y + (data->range.y_max - data -> scale_y) * zoom_factor;
	data->is_zoom = 1;
}

// void	zoom_in(t_fractol *data, float scaled_x, float scaled_y)
// {
// 	data->range.x_min = scaled_x + (data->range.x_min - scaled_x) * 1.0r5;
// 	data->range.x_max = scaled_x + (data->range.x_max - scaled_x) * 1.05;
// 	data->range.y_min = scaled_y + (data->range.y_min - scaled_y) * 1.05;
// 	data->range.y_max = scaled_y + (data->range.y_max - scaled_y) * 1.05;
// 	create_mandelbrot(data);
// }

// void	zoom_out(t_fractol *data, float scaled_x, float scaled_y)
// {
// 	data->range.x_min = scaled_x + (data->range.x_min - scaled_x) / 1.05;
// 	data->range.x_max = scaled_x + (data->range.x_max - scaled_x) / 1.05;
// 	data->range.y_min = scaled_y + (data->range.y_min - scaled_y) / 1.05;
// 	data->range.y_max = scaled_y + (data->range.y_max - scaled_y) / 1.05;
// 	create_mandelbrot(data);
// }

// void	zoom_in(t_fractol *data, float mouse_x, float mouse_y)
// {
// 	float	zoom_factor;
// 	float	zoom_width;
// 	float	zoom_height;

// 	// float x_min;
// 	// float x_max;
// 	// float y_min;
// 	// float y_max;

// 	data->zoom *= 1.05;
// 	zoom_width = data->image->width / data->zoom;
// 	zoom_height = data->image->height / data->zoom;

// 	data->range.x_min = mouse_x - zoom_width / 2;
// 	data->range.y_min = mouse_y - zoom_height / 2;
// 	data->range.x_max = mouse_x + zoom_width / 2;
// 	data->range.y_max = mouse_y + zoom_height / 2;
	// if (data->range.x_min < 0)
	// {
	// 	data->range.x_max = data->range.x_max - data->range.x_min;
	// 	data->range.x_min = 0;	
	// }
	// if (data->range.y_min < 0)
	// {
	// 	data->range.y_max = data->range.y_max - data->range.y_min;
	// 	data->range.y_min = 0;	
	// }
	// if (data->range.x_max > data->image->width)
	// {
	// 	data->range.x_min = data->range.x_min - (data->range.x_max - data->image->width);
	// 	data->range.x_max = data->image->width;	
	// }
	// if (data->range.y_max > data->image->height)
	// {
	// 	data->range.y_min = data->range.y_min - (data->range.y_max - data->image->height);
	// 	data->range.y_max = data->image->height;	
	// }
// 	// printf("x_min: %.2f, x_max: %.2f, y_min: %.2f y_max: %.2f\n", data->range.x_min, data->range.x_max, data->range.y_min, data->range.y_max);
// 	int	x;
// 	int	y;
// 	float scaled_x;
// 	float scaled_y;
// 	uint32_t color;
	
// 	y = 0;
// 	while (y < data->image->height)
// 	{
// 		x = 0;
// 		while (x < data->image->width)
// 		{
// 			scaled_x = data->range.x_min + ((float)x / data->image->width) * (data->range.x_max - data->range.x_min);	
// 			scaled_y = data->range.y_min + ((float)y / data->image->height) * (data->range.y_max - data->range.y_min);
// 			color = bilinear_interpolate(data, scaled_x, scaled_y);		
// 			mlx_put_pixel(data->image, x, y, color);		
// 			x++;
// 		}
// 		y++;
// 	}

// 	// create_mandelbrot(data);
// }

// uint32_t	bilinear_interpolate(t_fractol *data, float x, float y)
// {
// 	int	x1;
// 	int	y1;
// 	int	x2;
// 	int	y2;

// 	x1 = (int)(x);
// 	y1 = (int)(y);
// 	x2 = x1 + 1;
// 	y2 = y1 + 1;
// 	if (x2 >= WIDTH)
// 		x2 = WIDTH - 1;
// 	if (y2 >= HEIGHT)
// 		y2 = HEIGHT - 1;

// 	double dx = x - x1;
// 	double dy = y - y1;
	
//     uint8_t *pixels = data -> image_buffer;

//     uint32_t idx11 = (y1 * data -> image -> width + x1) * 4;
//     uint32_t idx21 = (y1 * data -> image -> width + x2) * 4;
//     uint32_t idx12 = (y2 * data -> image -> width + x1) * 4;
//     uint32_t idx22 = (y2 * data -> image -> width + x2) * 4;

//     uint8_t r11 = pixels[idx11], g11 = pixels[idx11 + 1], b11 = pixels[idx11 + 2];
//     uint8_t r21 = pixels[idx21], g21 = pixels[idx21 + 1], b21 = pixels[idx21 + 2];
//     uint8_t r12 = pixels[idx12], g12 = pixels[idx12 + 1], b12 = pixels[idx12 + 2];
//     uint8_t r22 = pixels[idx22], g22 = pixels[idx22 + 1], b22 = pixels[idx22 + 2];

//     // Bilinear interpolation on each color channel
// 	uint8_t r = (uint8_t)((1 - dx) * (1 - dy) * r11 + dx * (1 - dy) * r21 + (1 - dx) * dy * r12 + dx * dy * r22);
// 	uint8_t g = (uint8_t)((1 - dx) * (1 - dy) * g11 + dx * (1 - dy) * g21 + (1 - dx) * dy * g12 + dx * dy * g22);
// 	uint8_t b = (uint8_t)((1 - dx) * (1 - dy) * b11 + dx * (1 - dy) * b21 + (1 - dx) * dy * b12 + dx * dy * b22);
	

//     // Return the color in RGBA format
//     return (r << 24) | (g << 16) | (b << 8) | 255;
// }

