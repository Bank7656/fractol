/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:48:59 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/26 19:25:35 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	black_red_gradient(t_fractol *data, int32_t iteration);
static uint32_t	smooth_color(t_fractol *data, int32_t iteration, double zn);

/*
	Parsing to each color style
*/
uint32_t    get_color(t_fractol *data, int32_t iteration, double zn)
{
	if (data->color_style == 0)
		return (black_red_gradient(data, iteration));
	else if (data->color_style == 1)
		return (smooth_color(data, iteration, zn));
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

static uint32_t	smooth_color(t_fractol *data, int32_t iteration, double zn)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	smooth;
	double	t;

	smooth = iteration + 1 - log2(log2(zn));
	t = pow(smooth / data->max_iteration, 0.7);
    r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (((r << 24) | (g << 16) | (b << 8) | 255));
}