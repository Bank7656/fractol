/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:53:07 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/27 03:23:01 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_loophook(void *param)
{
    t_fractol *data;
   
    data = (t_fractol *)param;
    if (data->is_zoom)
    {
        create_mandelbrot(data, 0);
        data->is_zoom = 0;
    }
    else
    {
    
        create_mandelbrot(data, 1);
    }
    // if (data->is_zoom == 1)
    // {
    //     zoom_in(data, data->scale_x, data->scale_y);
    //     data->is_zoom = 0;
    //     data->max_iteration /= 1.02;
    // }
    // if (data->is_zoom == -1)
    // {
    //     zoom_out(data, data->scale_x, data->scale_y);
    //     data->is_zoom = 0;
    //     data->max_iteration *= 1.02;
    // }
    // printf("Iteration: %.2f\n", data->max_iteration);
    return ;
}