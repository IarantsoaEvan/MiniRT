/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:39:03 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 19:39:09 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	int			delta;
	size_t		i;

	i = 0;
	while (i < size)
	{
		delta = *(const unsigned char *)p1++ - *(const unsigned char *)p2++;
		if (delta)
			return (delta);
		i++;
	}
	return (0);
}
