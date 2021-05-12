/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:53:16 by rvan-sch      #+#    #+#                 */
/*   Updated: 2019/11/22 19:53:18 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char*)s1;
	ts2 = (unsigned char*)s2;
	while (i < n)
	{
		if (ts1[i] != ts2[i])
			return (ts1[i] - ts2[i]);
		else
			i++;
	}
	return (0);
}
