/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:44:00 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/06 00:59:34 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Using escape time algorithm to calculate mandelbrot set
*/
uint32_t    draw_mandelbrot(t_fractol *data)
{
	long double 	x;
	long double 	y;
	long double 	x_squared;
	long double 	y_squared;
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
		y = (x + x) * y + data->scale_y;
		x = x_squared - y_squared + data->scale_x;
		x_squared = x * x;
		y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration, sqrt(x_squared + y_squared)));
}