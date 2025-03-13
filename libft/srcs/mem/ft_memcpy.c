/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:38:50 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:33 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_src;
	unsigned char	*cast_dest;

	cast_src = (unsigned char *)src;
	cast_dest = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*cast_dest = *cast_src;
		cast_dest++;
		cast_src++;
		n--;
	}
	return (dest);
}
