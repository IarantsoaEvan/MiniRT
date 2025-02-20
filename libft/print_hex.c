/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:25:39 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 14:01:19 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

static void	ft_putnbr_base_16(unsigned int nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_16(nbr / 16, base);
		ft_putnbr_base_16(nbr % 16, base);
	}
	else
		ft_print_char(base[nbr]);
}

int	print_hex(int nbr, char c)
{
	char			*base;
	unsigned int	n;

	n = (unsigned int)nbr;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_putnbr_base_16(n, base);
	return (nbr_len(n));
}
