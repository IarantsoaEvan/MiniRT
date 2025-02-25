/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:16:27 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/25 09:20:51 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isspace(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            i++;
        else
            return (0);
    }
    return (1);
}