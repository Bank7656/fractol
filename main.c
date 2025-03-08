/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:18:03 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 03:18:06 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *data);
static void instruction(void);
static void	check_hook(t_fractol *data);

int main(int argc, char *argv[])
{
	t_fractol   data;

	if (argc < 2)
		exit(usage_prompt());
	if (parser(&data, argc, argv) == -1)
		exit(usage_prompt());
	data_init(&data);
	instruction();
	check_hook(&data);
	mlx_loop(data.mlx);
	mlx_delete_image(data.mlx, data.image);
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
		ft_error();
	mlx_set_window_limit(data->mlx, 1024, 768, -1, -1);
	data->image = mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);
	if (data->image == NULL)
	{
		mlx_terminate(data->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		// mlx_delete_image(data->mlx, da);
		mlx_terminate(data->mlx);
		exit(EXIT_FAILURE);
	}
}

static void	instruction(void)
{
	ft_putstr_fd("\nCommands:\n", STDOUT_FILENO);
	ft_putstr_fd("  w: moving upwards\n", STDOUT_FILENO);
	ft_putstr_fd("  s: moving downwards\n", STDOUT_FILENO);
	ft_putstr_fd("  a: moving left\n", STDOUT_FILENO);
	ft_putstr_fd("  d: moving right\n\n", STDOUT_FILENO);
	ft_putstr_fd("  =: increase max iteration\n", STDOUT_FILENO);
	ft_putstr_fd("  -: decrease max iteration\n\n", STDOUT_FILENO);
	ft_putstr_fd("  r: reset view\n", STDOUT_FILENO);
	ft_putstr_fd("  space: toggle mode (only for julia)\n\n", STDOUT_FILENO);
	ft_putstr_fd("  1: color scheme 1\n", STDOUT_FILENO);
	ft_putstr_fd("  2: color scheme 2\n", STDOUT_FILENO);
	ft_putstr_fd("  3: color scheme 3\n", STDOUT_FILENO);
	ft_putstr_fd("  4: color scheme 4\n\n", STDOUT_FILENO);
}

int	usage_prompt(void)
{
	ft_putstr_fd("\nInvalid Arguments\n", STDOUT_FILENO);
	ft_putstr_fd("\nUsage: ./fractol", STDOUT_FILENO);
	ft_putstr_fd(" [option] {Real} {Imaginary}\n\n", STDOUT_FILENO);
	ft_putstr_fd("Option:\n", STDOUT_FILENO);
	ft_putstr_fd("  Mandelbrot/mandelbrot: Mandelbrot set\n", STDOUT_FILENO);
	ft_putstr_fd("  Julia/julia: Julia set\n", STDOUT_FILENO);
	ft_putstr_fd("  Burning ship/Burning ship: Burning ship\n", STDOUT_FILENO);
	ft_putstr_fd("  Tricorn/tricorn: Tricorn set\n\n", STDOUT_FILENO);
	ft_putstr_fd("{Real} and {imaginary} number argument", STDOUT_FILENO);
	ft_putstr_fd(" only for julia set.\n", STDOUT_FILENO);
	ft_putstr_fd("Please enter real and imaginary number", STDOUT_FILENO);
	ft_putstr_fd("between -10 and 10.\n", STDOUT_FILENO);
	return (EXIT_FAILURE);
}
