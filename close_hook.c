/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:37:07 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 05:15:51 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_closehook(void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	mlx_terminate(data->mlx);
	exit(EXIT_SUCCESS);
}
