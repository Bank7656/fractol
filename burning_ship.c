/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:45:06 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 05:15:11 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Using escape time algorithm to calculate burning ship set
*/
uint32_t	draw_burning_ship(t_fractol *data)
{
	double	x;
	double	y;
	double	x_squared;
	double	y_squared;
	int32_t	iteration;

	x = 0;
	y = 0;
	x_squared = 0;
	y_squared = 0;
	iteration = 0;
	while ((x_squared + y_squared < 4) && (iteration < data->max_iteration))
	{
		y = (fabs((x + x) * y)) - data->scale_y;
		x = fabs(x_squared - y_squared + data->scale_x);
		x_squared = x * x;
		y_squared = y * y;
		iteration++;
	}
	return (get_color(data, iteration));
}
