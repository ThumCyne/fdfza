/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:05:55 by razaha            #+#    #+#             */
/*   Updated: 2021/09/11 13:54:37 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	slen;

	slen = len;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (b - slen);
}
