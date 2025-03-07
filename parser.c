/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:50:52 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 16:57:31 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	parser(t_fractol *data, int argc, char *argv[])
{
	if (ft_strncmp(argv[1], "Mandelbrot", -1) == 0
		|| ft_strncmp(argv[1], "mandelbrot", -1) == 0)
		data->plot = MANDELBROT;
	else if (ft_strncmp(argv[1], "Julia", -1) == 0
		|| ft_strncmp(argv[1], "julia", -1) == 0)
		data->plot = JULIA;
	else if (ft_strncmp(argv[1], "Burning ship", -1) == 0
		|| ft_strncmp(argv[1], "burning ship", -1) == 0)
		data->plot = BURNING_SHIP;
	else
		return (0);
	if (argc != 2 && (data->plot == MANDELBROT || data->plot == BURNING_SHIP))
		exit(usage_prompt());
	else if (argc != 4 && data->plot == JULIA)
		exit(usage_prompt());
	if (data->plot == JULIA)
	{
		data->cx = (-1) * my_atof(argv[2]);
		data->cy = (-1) * my_atof(argv[3]);
	}
	return (1);
}