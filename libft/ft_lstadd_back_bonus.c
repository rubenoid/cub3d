/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:08:44 by rvan-sch      #+#    #+#                 */
/*   Updated: 2019/11/23 18:22:31 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!alst || !new)
		return ;
	else if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast(*alst);
	tmp->next = new;
}
