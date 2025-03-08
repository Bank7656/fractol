/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:18:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 04:41:41 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *data);
static void	check_hook(t_fractol *data);

int	main(int argc, char *argv[])
{
	t_fractol	data;

	if (argc < 2)
		exit(usage_prompt());
	if (parser(&data, argc, argv) == -1)
		exit(usage_prompt());
	data_init(&data);
	instruction();
	check_hook(&data);
	mlx_loop(data.mlx);
	ft_error(&data);
	return (EXIT_SUCCESS);
}

void	ft_error(t_fractol *data)
{
	if (data->image != NULL)
		mlx_delete_image(data->mlx, data->image);
	if (data->mlx != NULL)
		mlx_terminate(data->mlx);
	exit(EXIT_FAILURE);
}

static void	check_hook(t_fractol *data)
{
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
	mlx_close_hook(data->mlx, &my_closehook, data);
	mlx_loop_hook(data->mlx, &my_loophook, data);
}

static void	data_init(t_fractol *data)
{
	plot_init(data);
	data->is_toggle = 0;
	data->color_style = 0;
	data->is_zoom = 0;
	data->is_move = 0;
	data->is_new_iteration = 0;
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (data->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx_set_window_limit(data->mlx, 1024, 768, -1, -1);
	data->image = mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	if (data->image == NULL)
		ft_error(data);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		ft_error(data);
}
