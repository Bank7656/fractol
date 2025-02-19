/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:29:09 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/18 18:33:14 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(float x0, float y0)
{
	int		i;
	float x;
	float y;
	float x2;
	float y2;
	
	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;

	i = 0;
	while ((x2 + y2) <= 4 && (i < MAX_ITERATION))
	{
		y = (x + x) * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		i++;
	}
	return i;
}

void	draw_mandelbrot(mlx_image_t *image, double center_x, double center_y, float zoom)
{
	// t_complex number;
	int	x;
	int	y;
	int	i;
	int color;
	double	real_max;
	double	real_min;
	double	imag_max;
	double	imag_min;
	
	real_max = 2;
	real_min = -2;
	imag_max = 2;
	imag_min = -2;

	float scale_x = ((real_max - real_min) / zoom) / WIDTH; // Scale to (-2.00, 1)
	float scale_y = ((imag_max - imag_min) / zoom) / HEIGHT; // Scale to (-1.5, 1.5)
	float real;
	float imaginary;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = center_x - (real_max / zoom) + x * scale_x;
			imaginary = center_y - (imag_max / zoom) + y * scale_y;
			i = mandelbrot(real, imaginary);
			if (i == MAX_ITERATION)
				color = BLACK;
			else
				color = get_gradient(i);
			mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}