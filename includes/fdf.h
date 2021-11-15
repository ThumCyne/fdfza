/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:39:59 by razaha            #+#    #+#             */
/*   Updated: 2021/09/11 16:34:58 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <math.h>

# define BUTTONPRESS 2
# define DESTROYPRESS 17
# define SCALE 20

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		**z_matrix;
	int		color;
	float	x1;
	float	y1;
	int		shift_x;
	int		shift_y;
}	t_fdf;

t_fdf	*read_file(char *file_name);
int		get_next_line(int fd, char **line);
int		ft_wdcounter(char const *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	draw(t_fdf *data);
void	bresenham(float x, float y, int bool, t_fdf *data);
int		ft_max(int a, int b);
int		ft_abs(int a);

#endif
