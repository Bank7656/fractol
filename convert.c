/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:46:00 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/24 18:27:46 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float pixel_to_complex_x(t_fractol *data, int32_t x_pixel)
{
	float min;
	float max;
	float complex_x;
	
	min = data->range.x_min;
	max = data->range.x_max;
	complex_x = min + (max - min) * ((float)x_pixel / data->mlx->width);
	return (complex_x);    
}

float pixel_to_complex_y(t_fractol *data, int32_t y_pixel)
{
	float min;
	float max;
	float complex_y;

	min = data->range.y_min;
	max = data->range.y_max;
	complex_y = max - (max - min) * ((float)y_pixel/ (data->mlx->height * data->zoom));
	return (complex_y);    
}