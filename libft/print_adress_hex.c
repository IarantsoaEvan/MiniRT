/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:33:49 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/20 14:01:16 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len_p(unsigned long nbr)
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

static void	ft_putnbr_base_16_p(unsigned long nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_16_p(nbr / 16, base);
		ft_putnbr_base_16_p(nbr % 16, base);
	}
	else
		ft_print_char(base[nbr]);
}

static int	print_hex_p(unsigned long nbr, char c)
{
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_putnbr_base_16_p(nbr, base);
	return (nbr_len_p(nbr));
}

int	print_adress_hex(void *adress)
{
	int				i;
	int				j;
	unsigned long	nbr;	

	nbr = (unsigned long)adress;
	i = 0;
	j = 0;
	if (nbr == 0)
	{
		i = print_str("(nil)");
		return (i);
	}
	i = print_str("0x");
	j = print_hex_p(nbr, 'x');
	return (i + j);
}
