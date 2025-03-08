/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:43:25 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 04:09:12 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Using escape time algorithm to calculate julia set
*/
uint32_t	draw_julia(t_fractol *data)
{
	int32_t		iteration;
	long double	x;
	long double	y;
	long double	x_squared;
	long double	y_squared;

	x = data -> scale_x;
	y = (-1) * (data -> scale_y);
	x_squared = x * x;
	y_squared = y * y;
	iteration = 0;
	while ((x_squared + y_squared <= 4) && (iteration < data->max_iteration))
	{
		y = (x + x) * y + data->cy;
		x = x_squared - y_squared + data->cx;
		x_squared = x * x;
		y_squared = y * y;
		iteration++;
	}
	return (get_color(data, iteration));
}
