/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:53:07 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 14:56:11 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    plot(t_fractol *data, int32_t is_full_pixel);

void    my_loophook(void *param)
{
    t_fractol *data;
   
    data = (t_fractol *)param;
    if (data->is_zoom)
    {
        plot(data, 0);
        data->is_zoom = 0;
    }
    else if (data->is_move)
    {
        plot(data, 0);
        data->is_move = 0;
    }
    else if (data->is_new_iteration)
    {
        plot(data, 1);
        data->is_new_iteration = 0;   
    }
    else
    {
        plot(data, 1);
        // create_mandelbrot(data, 1);
    }
    // printf("Iteration: %.2f\n", data->max_iteration);
    // printf("[x_min: %.7f] [x_max: %.7f] [y_min: %.7f] [y_max: %.7f]\n", data->range.x_min, data->range.x_max, data->range.y_min, data->range.y_max);
    return ;
}

void    plot(t_fractol *data, int32_t is_full_pixel)
{
    if (data->plot == MANDELBROT)
        create_mandelbrot(data, is_full_pixel);
    else if (data->plot == JULIA)
    {
        // printf("Still in progress\n");
        create_julia(data, is_full_pixel);
        // exit(EXIT_SUCCESS);
    }
}