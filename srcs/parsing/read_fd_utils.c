/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <ygorget@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:44:10 by ygorget           #+#    #+#             */
/*   Updated: 2025/03/13 14:40:08 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3D.h>

t_buff	*ft_lst_last(t_buff *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lst_clear(t_buff **lst)
{
	t_buff	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_lstaddback(t_buff **lst, t_buff *new)
{
	t_buff	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_buff	*ft_lst_new(void)
{
	t_buff	*str;

	str = malloc(sizeof(*str));
	if (str)
	{
		ft_memset(&str->buffer, 0, BUFFER_SIZE + 1);
		str->next = NULL;
	}
	return (str);
}
