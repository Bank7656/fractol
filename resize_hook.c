/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:42:23 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 22:29:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_resizefunc(int32_t width, int32_t height, void* param)
{
	t_fractol *data;

	data = (t_fractol *)param;
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, width, height);
	if (data->image == NULL)
		ft_error();
	data->mlx->width = width;
	data->mlx->height = height;
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		ft_error();
	plot(data, 1);
}