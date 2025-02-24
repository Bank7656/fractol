/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:18:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/24 16:50:32 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_error(void)
{
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	t_fractol   data;

	// Initialize
	data.color_style = 0;
	data.range.x_min = -2;
	data.range.x_max = 0.5;
	data.range.y_min = -1.12;
	data.range.y_max = 1.12;
	data.max_iteration = 100;
	// Init mlx
	data.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (data.mlx == NULL)
		return (EXIT_FAILURE);
	// Create image
	printf("width:%i height:%i\n", data.mlx->width, data.mlx->height);
	data.image = mlx_new_image(data.mlx, data.mlx->width, data.mlx->height);
	if (data.image == NULL)
		return (EXIT_FAILURE);
	// Put image to window
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
		return (EXIT_FAILURE);

	// Create mandelbrot
	create_mandelbrot(&data);
	mlx_resize_hook(data.mlx, &my_resizefunc, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);    
}
