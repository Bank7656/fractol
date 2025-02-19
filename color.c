/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:32:59 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/18 18:33:09 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_gradient(int i)
{
	int r;
	int g;
	int b;
	int a;

	r = (i * 255) / MAX_ITERATION;
	g = (i * 128) / MAX_ITERATION;
	b = (i * 64) / MAX_ITERATION;
	a = 255;

	return (r << 24) | (g << 16) | (b << 8) | a;
}