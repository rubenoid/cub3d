/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_length.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 20:53:30 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/07/06 20:53:43 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_length(unsigned long long d)
{
	int i;

	if (d == 0)
		return (1);
	i = 0;
	while (d)
	{
		i++;
		d = d / 16;
	}
	return (i);
}
