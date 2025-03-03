/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:41:20 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 22:14:45 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_keyhook(mlx_key_data_t keydata, void *param)
{
    float     move_factor;
    t_fractol *data;

    data = (t_fractol *)param;
    move_factor = (data->range.x_max - data->range.x_min) * 0.025;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(data->mlx);
    else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
        plot_init(data);
    else if (keydata.key == MLX_KEY_EQUAL 
        && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    {
        data->max_iteration += 10;
        data->is_new_iteration = 1;
    }
    else if (keydata.key == MLX_KEY_MINUS 
        && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    {
        data->max_iteration -= 10;
        data->is_new_iteration = 1;
    }
    else if (keydata.key == MLX_KEY_W 
        && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    {
        data->range.y_max += move_factor;
        data->range.y_min += move_factor;
        data->is_move = 1;
    }
    else if (keydata.key == MLX_KEY_A 
        && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    {
        data->range.x_max -= move_factor;
        data->range.x_min -= move_factor;
        data->is_move = 1;
    }
    else if (keydata.key == MLX_KEY_S 
        && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    {
        data->range.y_max -= move_factor;
        data->range.y_min -= move_factor;
        data->is_move = 1;
    }
    else if (keydata.key == MLX_KEY_D
        && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
    {
        data->range.x_max += move_factor;
        data->range.x_min += move_factor;
        data->is_move = 1;
    }
    else if (keydata.key == MLX_KEY_SPACE && data->plot == JULIA &&
        keydata.action == MLX_PRESS)
    {
        if (data->is_toggle == 0)
            data->is_toggle = 1;
        else
            data->is_toggle = 0;
    }
    
}