/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:50:52 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/03 22:51:19 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	parser(t_fractol *data, char *str)
{
	if (ft_strncmp(str, "Mandelbrot", -1) == 0
		|| ft_strncmp(str, "mandelbrot", -1) == 0)
		data->plot = MANDELBROT;
	else if (ft_strncmp(str, "Julia", -1) == 0
		|| ft_strncmp(str, "julia", -1) == 0)
		data->plot = JULIA;
	else if (ft_strncmp(str, "Burning ship", -1) == 0
		|| ft_strncmp(str, "burning ship", -1) == 0)
		data->plot = BURNING_SHIP;
	else
		return (0);
	return (1);
}