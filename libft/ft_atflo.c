/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atflo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:20:33 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/15 10:46:47 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

static float get_decimal(const char *str, float sign)
{
    float prec;
    float div;
	div = 1.0;
	prec = 0.0;
	while (*str && *str != '.')
		str++;
    if (*str == '.')
	{
        str++; 
        while (*str >= '0' && *str <= '9') {
            div *= 10.0;
            prec += (*str - '0') / div;
            str++;
        }
    }
    return prec * sign; 
}

float	ft_atflo(char *str)
{
	float	res;
	float	sign;

	sign = 1.0;
	if (str && str[0] == '-')
		sign = sign * -1.0;
	else if (str && str[0] == '+')
		str++;
	res = (float)ft_atoi(str);
	res += get_decimal(str, sign);
	return (res);
}
