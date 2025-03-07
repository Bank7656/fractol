/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:48:59 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 22:53:18 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	black_red_gradient(t_fractol *data, int32_t iteration);
static uint32_t	smooth_color(t_fractol *data, int32_t iteration);
static uint32_t black_white(t_fractol *data, int32_t iteration);
static uint32_t rainbow(t_fractol *data, int32_t iteration);

/*
	Parsing to each color style
*/
uint32_t    get_color(t_fractol *data, int32_t iteration)
{
	if (data->color_style == 0)
		return (black_red_gradient(data, iteration));
	else if (data->color_style == 1)
		return (smooth_color(data, iteration));
	else if (data->color_style == 2)
		return (black_white(data, iteration));
	else if (data->color_style == 3)
		return (rainbow(data, iteration));
	return (0xFF0000FF);
		
}

static uint32_t    black_red_gradient(t_fractol *data, int32_t iteration)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t max_iterate;


	max_iterate = data->max_iteration;
	if (iteration == max_iterate)
		return (0x000000FF);
	r = (iteration * 255) / max_iterate;
	g = (iteration * 128) / max_iterate;
	b = (iteration * 64) / max_iterate;

	return ((r << 24) | (g << 16) | (b << 8) | 255);
}

static uint32_t	smooth_color(t_fractol *data, int32_t iteration)
{
	uint32_t colors[16];
	
	colors[0] = 0x421E0FFF;
	colors[1] = 0x19071AFF;
	colors[2] = 0x09012FFF;
	colors[3] = 0x040447FF;
	colors[4] = 0x000764FF;
	colors[5] = 0x0C2C8AFF;
	colors[6] = 0x1852B1FF;
	colors[7] = 0x397DD1FF;
	colors[8] = 0x86B5E5FF;
	colors[9] = 0xD3ECF8FF;
	colors[10] = 0xF1E9BFFF;
	colors[11] = 0xF8C95FFF;
	colors[12] = 0xFFAA00FF;
	colors[13] = 0xCC8000FF;
	colors[14] = 0x995700FF;
	colors[15] = 0x6A3403FF;
	if (iteration == data->max_iteration)
		return (0x000000FF);
	return (colors[iteration % 16]);
}

static uint32_t black_white(t_fractol *data, int32_t iteration)
{
	uint32_t black;
	uint32_t white;

	black = 0x000000FF;
	white = 0xFFFFFFFF;

	if (iteration == data->max_iteration)
		return (black);
	else if (iteration % 2 == 0)
		return (black);
	return (white);
}

static uint32_t rainbow(t_fractol *data, int32_t iteration)
{
	uint32_t colors[7];
	
	colors[0] = 0xFF0000FF;
	colors[1] = 0xFF7F00FF;
	colors[2] = 0xFFFF00FF;
	colors[3] = 0x00FF00FF;
	colors[4] = 0x00FFFFFF;
	colors[5] = 0x0000FFFF;
	colors[6] = 0x8B0000FF;

	if (iteration == data->max_iteration)
		return (0x000000FF);
	return (colors[iteration % 7]);
}