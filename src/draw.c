/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:13:20 by razaha            #+#    #+#             */
/*   Updated: 2021/09/11 16:30:08 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham2(float x, float y, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x += data->shift_x;
	y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	x_step = data->x1 - x;
	y_step = data->y1 - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			x + 200, y + 200, data->color);
		x += x_step;
		y += y_step;
	}
}

void	bresenham(float x, float y, int bool, t_fdf *data)
{
	int	z;
	int	z1;

	if (bool)
	{
		data->x1 = x + 1;
		data->y1 = y;
	}
	else
	{
		data->x1 = x;
		data->y1 = y + 1;
	}
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	x *= SCALE;
	y *= SCALE;
	data->x1 *= SCALE;
	data->y1 *= SCALE;
	isometric(&x, &y, z);
	isometric(&data->x1, &data->y1, z1);
	data->color = 0xfffffff;
	if (z || z1)
		data->color = 0xe80c0c;
	bresenham2(x, y, data);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, 1, data);
			if (y < data->height - 1)
				bresenham(x, y, 0, data);
			x++;
		}
		y++;
	}
}
