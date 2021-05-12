/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 20:13:37 by rvan-sch      #+#    #+#                 */
/*   Updated: 2019/11/23 00:06:32 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (s[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char *)s + i);
}
