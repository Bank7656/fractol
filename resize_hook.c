/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:23 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 18:51:03 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_resizefunc(int32_t width, int32_t height, void* param)
{
	int32_t	new_width;
	int32_t	new_height;
	t_fractol *data;

	data = (t_fractol *)param;
	mlx_delete_image(data->mlx, data->image);
	new_width = width;
	// new_height = width * 10 / 16;
	new_height = height;
	printf("Normal size: %i, Cal size: %i\n", height, new_height);
	mlx_set_window_size(data->mlx, new_width, new_height);
	data->image = mlx_new_image(data->mlx, new_width, new_height);
	if (data->image == NULL)
		ft_error();
	data->mlx->width = new_width;
	data->mlx->height = new_height;
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		ft_error();
	plot(data, 0);
}