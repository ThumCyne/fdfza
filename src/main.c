/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:39:54 by razaha            #+#    #+#             */
/*   Updated: 2021/09/18 14:34:52 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_destroywindown(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_presskey(int key, t_fdf *data)
{
	if (key == 53)
		ft_destroywindown();
	if (key == 126)
		data->shift_y -= 5;
	if (key == 125)
		data->shift_y += 5;
	if (key == 123)
		data->shift_x -= 5;
	if (key == 124)
		data->shift_x += 5;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2 || (open(av[1], O_RDONLY, 0) == -1))
		return(1);
	data = read_file(av[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw(data);
	system("leaks fdf");
	mlx_hook(data->win_ptr, BUTTONPRESS, (1L << 0), ft_presskey, data);
	mlx_hook(data->win_ptr, DESTROYPRESS, 0L,
		ft_destroywindown, data);
	mlx_loop(data->mlx_ptr);
}
