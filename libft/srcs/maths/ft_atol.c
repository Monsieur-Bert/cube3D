/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:55:36 by antauber          #+#    #+#             */
/*   Updated: 2025/03/13 14:38:38 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long int	ft_atol(const char *nptr)
{
	long int		i;
	long int		sign;
	long int		nb;
	unsigned char	*str;

	i = 0;
	sign = 1;
	nb = 0;
	str = (unsigned char *)nptr;
	while (ft_isspaces(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] != '-') - (str[i] == '-');
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
