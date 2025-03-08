/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 04:41:16 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 04:41:37 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instruction(void)
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
