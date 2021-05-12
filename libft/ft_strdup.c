/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:52:55 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/07/06 20:52:58 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_copy;
	int		i;

	s_copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
