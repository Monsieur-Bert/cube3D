/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antauber <antauber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:14:50 by bert              #+#    #+#             */
/*   Updated: 2024/12/02 08:07:20 by antauber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

/**
 * Structure representing a node of a list.
 * 
 * @param Member-Content Data contained in the node 
 * (Void* allows any kind of data).
 * @param Member-*Next Address of the next node 
 * (NULL if the next node is the last).
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * Adds the node ’new’ at the end of the list.
 * 
 * @param lst: The address of a pointer to the first 
 * link of a list.
 * @param new: The address of a pointer to the node 
 * to be added to the list.
 * @return None.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Adds the node ’new’ at the beginning of the list.
 * 
 * @param lst: The address of a pointer to the first link of a list.
 * @param new: The address of a pointer to the node to be added to the list.
 * @return None.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Deletes and frees the given node and every
 * successor of that node, using the function ’del and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * @param ls: The address of a pointer to a node.
 * @param del: The address of the function used to delete 
 * the content of the node.
 * @return None.
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free(3) the node.
 * 
 * @param lst: The node to free.
 * @param del: The address of the function used to 
 * delete the content.
 * @return None.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * Iterates the list ’lst’ and applies the function ’f’ 
 * on the content of each node.
 * 
 * @param lst: The address of a pointer to a node.
 * @param f: The address of the function used to iterate on the list.
 * @return None.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Returns the last node of the list.
 * 
 * @param lst: The beginning of the list.
 * @return Last node of the list.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * Iterates the list ’lst’ and applies the function ’f’ 
 * on the content of each node.
 * Creates a new list resulting of the successive applications 
 * of the function ’f’.
 * The ’del’ function is used to delete the content of a 
 * node if needed.
 * 
 * @param lst: The address of a pointer to a node.
 * @param f: The address of the function used to iterate on the list.
 * @param del: The address of the function used to delete 
 * the content of the node.
 * @return The new allocated list (NULL if the allocation fails).
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * Allocates with malloc(3) and returns a new node.
 * The member variable ’content’ is initialized with 
 * the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 * 
 * @param content: The allocated content to create the node with.
 * @return The new allocated node.
 */
t_list		*ft_lstnew(void *content);

/**
 * Counts the number of nodes in a list.
 * 
 * @param st: The beginning of the list.
 * @return The lengh of the list.
 */
int			ft_lstsize(t_list *lst);

#endif