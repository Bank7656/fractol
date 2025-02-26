/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:18:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/27 03:34:31 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *data);
static void	check_hook(t_fractol *data);

int main(int argc, char *argv[])
{
	t_fractol   data;

	data_init(&data);
	// Create mandelbrot
	create_mandelbrot(&data, 1);
	check_hook(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

void ft_error(void)
{
	exit(EXIT_FAILURE);
}

static void	check_hook(t_fractol *data)
{
	mlx_resize_hook(data->mlx, &my_resizefunc, data);
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
	mlx_loop_hook(data->mlx, &my_loophook, data);
}

static void	data_init(t_fractol *data)
{
	// Initialize
	data->color_style = 1;
	data->is_zoom = 0;
	data->zoom = 1.0;
	data->range.x_min = -2;
	data->range.x_max = 0.5;
	data->range.y_min = -1.12;
	data->range.y_max = 1.12;
	data->max_iteration = 100.0;
	// Init mlx
	data->image_buffer = (uint8_t *)malloc(WIDTH * HEIGHT * sizeof(uint32_t));
	if (data->image_buffer == NULL)
		exit(EXIT_FAILURE);
	
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (data->mlx == NULL)
		ft_error();
	

	// Create image
	data->image = mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	if (data->image == NULL)
		ft_error();
	// Put image to window
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		ft_error();
}
