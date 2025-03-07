/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:53:07 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 23:30:46 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


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
    else if (data->is_toggle)
        toggle_mode(data);
    else
        plot(data, 1);
    // printf("Iteration: %.2f\n", data->max_iteration);
    // printf("Zoom factor: %.20Lf\n", data->zoom);
    // printf("[x_min: %Lf] [x_max: %Lf] [y_min: %Lf] [y_max: %Lf]\n", data->range.x_min, data->range.x_max, data->range.y_min, data->range.y_max);
    // printf("Slope: %Lf\n", (data->range.y_max - data->range.y_min)/(data->range.x_max - data->range.x_min));
    return ;
}
