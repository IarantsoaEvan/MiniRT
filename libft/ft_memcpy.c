/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:38:43 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 19:39:13 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned char		*source;
	size_t				i;

	i = 0;
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
