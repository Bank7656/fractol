/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:31:24 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/09 05:07:03 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		update_border(t_fractol *data, long double zoom_factor);
static int32_t	update_zoom(t_fractol *data, long double zoom_factor);

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	int32_t		mouse_x;
	int32_t		mouse_y;
	t_fractol	*data;
	long double	zoom_factor;

	(void)xdelta;
	data = (t_fractol *)param;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.1;
	if (!update_zoom(data, zoom_factor))
		return ;
	data -> scale_x = pixel_to_complex_x(data, mouse_x);
	data -> scale_y = pixel_to_complex_y(data, mouse_y);
	update_border(data, zoom_factor);
}

static int32_t	update_zoom(t_fractol *data, long double zoom_factor)
{
	data->zoom *= zoom_factor;
	if (data->zoom > ZOOM_MAX_RANGE)
	{
		data->zoom = ZOOM_MAX_RANGE;
		return (0);
	}
	else if (data->zoom < ZOOM_MIN_RANGE)
	{
		data->zoom = ZOOM_MIN_RANGE;
		return (0);
	}
	return (1);
}

static void	update_border(t_fractol *data, long double zoom_factor)
{
	data->range.x_min = data -> scale_x + \
						((data->range.x_min - data -> scale_x) * \
						zoom_factor);
	data->range.x_max = data -> scale_x + \
						((data->range.x_max - data -> scale_x) * \
						zoom_factor);
	data->range.y_min = data -> scale_y + \
						((data->range.y_min - data -> scale_y) * \
						zoom_factor);
	data->range.y_max = data -> scale_y + \
						((data->range.y_max - data -> scale_y) * \
						zoom_factor);
	data->is_zoom = 1;
}
