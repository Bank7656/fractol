/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:18:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 19:57:07 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *data);
static int	usage_prompt(void);
static void	check_hook(t_fractol *data);

int main(int argc, char *argv[])
{
	t_fractol   data;

	if (argc != 2)
		exit(usage_prompt());
	// Create mandelbrot
	if (parser(&data, argv[1]) == 0)
		exit(usage_prompt());
	data_init(&data);
	// create_mandelbrot(&data, 1);
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
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_resize_hook(data->mlx, &my_resizefunc, data);
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
	mlx_loop_hook(data->mlx, &my_loophook, data);
}

static void	data_init(t_fractol *data)
{
	plot_init(data);
	// Initialize
	data->color_style = 1;
	data->is_zoom = 0;
	data->is_move = 0;
	data->is_new_iteration = 0;
	// Init mlx
	
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

static	int	usage_prompt(void)
{
	ft_putstr_fd("\nUsage: ./fractol [option]\n\n", STDOUT_FILENO);
	ft_putstr_fd("Option:\n", STDOUT_FILENO);
	ft_putstr_fd("  Mandelbrot/mandelbrot: Mandelbrot set\n", STDOUT_FILENO);
	ft_putstr_fd("  Julia/julia: Julia set\n\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
