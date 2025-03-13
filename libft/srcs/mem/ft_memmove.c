/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:02:55 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:35 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	unsigned char		*temp_src;
	size_t				i;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	i = -1;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (temp_dest < temp_src)
	{
		while (++i < n)
			temp_dest[i] = temp_src[i];
	}
	else
	{
		while (n > 0)
		{
			n--;
			temp_dest[n] = temp_src[n];
		}
	}
	return (temp_dest);
}
