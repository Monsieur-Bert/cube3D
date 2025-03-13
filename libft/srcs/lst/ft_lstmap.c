/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:38:41 by antauber          #+#    #+#             */
/*   Updated: 2024/12/18 12:21:01 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new;
	void	*buffer;

	map = NULL;
	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		buffer = f(lst->content);
		if (buffer)
			new = ft_lstnew(buffer);
		if (new == NULL || buffer == NULL)
		{
			if (buffer)
				del(buffer);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new);
		lst = lst->next;
	}
	return (map);
}
