/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:44:00 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 05:08:53 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Using escape time algorithm to calculate tricorn set
*/
uint32_t	draw_tricorn(t_fractol *data)
{
	int32_t		iteration;
	long double	x;
	long double	y;
	long double	x_squared;
	long double	y_squared;

	x = 0;
	y = 0;
	x_squared = 0;
	y_squared = 0;
	iteration = 0;
	while ((x_squared + y_squared < 4) && (iteration < data->max_iteration))
	{
		y = (-1) * (x + x) * y + data->scale_y;
		x = x_squared - y_squared + data->scale_x;
		x_squared = x * x;
		y_squared = y * y;
		iteration++;
	}
	return (get_color(data, iteration));
}
