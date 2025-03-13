/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:59:16 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:44 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_tabstr(char **tab, char *color)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf(1, "| %s%s%s ", color, tab[i], RESET);
		i++;
	}
	ft_printf(1, "||\n");
}
