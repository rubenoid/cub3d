/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:14:36 by rvan-sch      #+#    #+#                 */
/*   Updated: 2019/11/23 18:23:12 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *lst2;

	if (!*lst)
		return ;
	lst2 = *lst;
	while (lst2)
	{
		tmp = lst2->next;
		del(lst2->content);
		free(lst2);
		lst2 = tmp;
	}
	*lst = NULL;
}
