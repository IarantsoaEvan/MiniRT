/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:26:02 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 14:01:22 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	print_str(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
