/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:08:33 by antauber          #+#    #+#             */
/*   Updated: 2025/01/23 08:55:49 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_len(int nb_str, va_list params)
{
	int		total_len;
	int		i;
	char	*curr;

	total_len = 0;
	i = 0;
	while (i < nb_str)
	{
		curr = va_arg(params, char *);
		if (curr)
			total_len += ft_strlen(curr);
		i++;
	}
	return (total_len);
}

static void	construct_join(int nb_str, va_list params, char *joined)
{
	char	*curr;
	char	*ptr;
	int		i;

	ptr = joined;
	i = 0;
	while (i < nb_str)
	{
		curr = va_arg(params, char *);
		while (curr && *curr)
			*ptr++ = *curr++;
		i++;
	}
	*ptr = '\0';
}

char	*ft_strjoinvar(int nb_str, ...)
{
	va_list	params;
	int		total_len;
	char	*joined;

	if (nb_str <= 0)
		return (NULL);
	va_start(params, nb_str);
	total_len = get_len(nb_str, params);
	va_end(params);
	joined = ft_calloc(total_len + 1, sizeof(char));
	if (joined == NULL)
		return (NULL);
	va_start(params, nb_str);
	construct_join(nb_str, params, joined);
	va_end(params);
	return (joined);
}
