/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:30:47 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/20 01:55:51 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data -> mlx);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		data -> center_real = 0;
		data -> center_imag = 0;
		data -> zoom = 1;
		draw_mandelbrot(data -> img, data -> center_real, data -> center_imag, data -> zoom);
	}
	else if (keydata.key == MLX_KEY_W)
		set_move_key(keydata, data -> move_keys, 0);
	else if (keydata.key == MLX_KEY_S)
		set_move_key(keydata, data -> move_keys, 1);
	else if (keydata.key == MLX_KEY_A)
		set_move_key(keydata, data -> move_keys, 2);	
	else if (keydata.key == MLX_KEY_D)
		set_move_key(keydata, data -> move_keys, 3);
	else if (keydata.key == MLX_KEY_E && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		zoom(data, 1);
	else if (keydata.key == MLX_KEY_Q && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		zoom(data, -1);
	else if (keydata.key == MLX_KEY_Q && (keydata.action == MLX_RELEASE))
		draw_mandelbrot(data -> img, data -> center_real, data -> center_imag, data -> zoom);
	else if (keydata.key == MLX_KEY_E && (keydata.action == MLX_RELEASE))
		draw_mandelbrot(data -> img, data -> center_real, data -> center_imag, data -> zoom);
		
	
}

void	set_move_key(mlx_key_data_t keydata, bool *move_keys, int pressed)
{
	int		i;
	bool	is_pressed;
	bool	not_pressed;

	i = 0;
	is_pressed = (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT);
	while (i < 4)
	{
		if (i == pressed)
			move_keys[i] = is_pressed;
		else
			move_keys[i] = false;
		i++;
	}	
}


void	update(void *param)
{
	t_data *data;
	bool	moved;
	double move_factor;
	
	data = (t_data *)param;
	moved = false;
	if (data -> zoom == 1)
		move_factor = (1.0 / data -> zoom) * MOVE_SPEED;
	else
		move_factor = (1.0 / fabs((log2(data -> zoom)))) * MOVE_SPEED;
	if (data -> move_keys[0])
	{
		data -> center_imag -= move_factor;
		moved = true;
	}
	else if (data -> move_keys[1])
	{
		data -> center_imag += move_factor;
		moved = true;
	}
	else if (data -> move_keys[2])
	{
		data -> center_real -= move_factor;
		moved = true;
	}
	else if (data -> move_keys[3])
	{
		data -> center_real += move_factor;
		moved = true;
	}
	
	if (moved == true)
	{
		draw_mandelbrot(data -> img, data -> center_real, data -> center_imag, data -> zoom);
	}
}