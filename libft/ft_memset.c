/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:30:28 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 19:39:19 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	char		*str;
	size_t		i;

	str = (char *)pointer;
	i = 0;
	while (count-- != 0)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
