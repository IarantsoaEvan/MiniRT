/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:38:48 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/24 08:54:18 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem_block, int search_value, size_t size)
{
	const char	*cmem_block;
	char		c;
	size_t		i;

	cmem_block = (const char *)mem_block;
	c = (char)search_value;
	i = 0;
	while (i < size)
	{
		if (cmem_block[i] == c)
			return ((char *)cmem_block + i);
		i++;
	}
	return ((char *) NULL);
}
