/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:48:59 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/24 16:50:14 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t    black_red_gradient(t_fractol *data, int32_t iteration);

/*
	Parsing to each color style
*/
uint32_t    get_color(t_fractol *data, int32_t iteration)
{
	if (data->color_style == 0)
		return (black_red_gradient(data, iteration));
	return (0xFF0000FF);
}

static uint32_t    black_red_gradient(t_fractol *data, int32_t iteration)
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