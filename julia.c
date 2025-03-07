/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:43:25 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 23:00:55 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t    draw_julia(t_fractol *data)
{
	long double 	x;
	long double 	y;
	long double 	x_squared;
	long double 	y_squared;
	int32_t iteration;
	int32_t	loop;

	x = data -> scale_x;
	y = data -> scale_y;
	x_squared = x * x;
	y_squared = y * y;
	iteration = 0;
	loop = (data->max_iteration);
	while ((x_squared + y_squared <= 4) && (iteration < loop))
	{
        
        y = (x + x) * y + data->cy;
		x = x_squared - y_squared + data->cx;
        x_squared = x * x;
        y_squared = y * y;
		iteration++; 
	}
	return (get_color(data, iteration));
}