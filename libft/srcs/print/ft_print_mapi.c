/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mapi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:59:16 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:41 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_mapi(int **tab, int size_x, int size_y, char *color)
{
	int	y;

	y = 0;
	while (y < size_y)
	{
		ft_print_tabi(tab[y], size_x, color);
		y++;
	}
}
