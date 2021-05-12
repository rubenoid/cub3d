/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 19:30:01 by rvan-sch      #+#    #+#                 */
/*   Updated: 2019/11/22 19:32:20 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tdst;
	unsigned char	*tsrc;

	i = 0;
	tdst = (unsigned char*)dst;
	tsrc = (unsigned char*)src;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		if (tsrc[i] == (unsigned char)c)
			return (tdst + i + 1);
		i++;
	}
	return (NULL);
}
