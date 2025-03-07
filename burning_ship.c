/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:45:06 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 23:01:06 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Using escape time algorithm to calculate burning ship set
*/
uint32_t    draw_burning_ship(t_fractol *data)
{
	long double 	x;
	long double 	y;
	long double 	x_squared;
	long double 	y_squared;
    long double     x_temp;
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
        x_temp = x * x - y * y + data->scale_x;
		y = fabs((x + x) * y) - data->scale_y;
		x = fabs(x_temp);
		x_squared = x * x;
		y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration));
}