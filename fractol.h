/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:57:15 by thacharo          #+#    #+#             */
/*   Updated: 2025/02/13 21:35:18 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#endif

#define MAX_ITERATION 100
#define WIDTH 1280
#define HEIGHT 1080
#define BPP sizeof(int32_t)

#define BLACK 0x000000FF

#include <math.h>

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
    mlx_t       *mlx;
    mlx_image_t *img;
}   t_data;

typedef struct s_complex
{
    float real;
    float imaginary;
}   t_complex;
