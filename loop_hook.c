/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:53:07 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 04:30:13 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_loophook(void *param)
{
	t_fractol	*data;

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
	return ;
}
