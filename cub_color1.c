/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_color1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:43:36 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/03 20:43:49 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_color_line_space(const char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}
