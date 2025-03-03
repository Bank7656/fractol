/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:17:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 22:06:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    mandelbrot_init(t_fractol *data);
static void    julia_init(t_fractol *data);

void    plot_init(t_fractol *data)
{
    if (data->plot == MANDELBROT)
        mandelbrot_init(data);
    else if (data->plot == JULIA)
        julia_init(data);
}

static void    mandelbrot_init(t_fractol *data)
{
    data->range.x_min = -2;
    data->range.x_max = 0.5;
    data->range.y_min = -1.12;
    data->range.y_max = 1.12;
    data->zoom = 1.0;
	data->max_iteration = 100.0;
    data->cx = 0;
    data->cy = 0;
}

static void    julia_init(t_fractol *data)
{
    data->range.x_min = -2;
    data->range.x_max = 2;
    data->range.y_min = -2;
    data->range.y_max = 2;
    data->zoom = 1.0;
	data->max_iteration = 500.0;
    data->cx = -0.7269;
    data->cy = 0.1889;
}
