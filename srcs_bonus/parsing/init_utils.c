/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:37:09 by ygorget           #+#    #+#             */
/*   Updated: 2025/04/14 14:10:53 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

int	ft_ato(const char *nptr)
{
	int				i;
	int				nb;
	unsigned char	*str;

	i = 0;
	nb = 0;
	str = (unsigned char *)nptr;
	while (ft_isspaces(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 255)
			return (256);
		i++;
	}
	return (nb);
}

int	no_map(int i)
{
	if (i == 6)
	{
		print_error(ERR_MAP);
		return (1);
	}
	return (0);
}
