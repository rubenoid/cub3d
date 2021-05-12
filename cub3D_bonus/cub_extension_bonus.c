/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_extension.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:44:16 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/03 20:45:22 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_test_extension(char *av, t_cub *cub)
{
	int i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (av[i] == '/')
		ft_error("Can not open directories. Please specify a valid .cub file",
					cub);
	if (strncmp(av + (i - 4), ".cub", 4) == 0)
		return ;
	else
		ft_error("Not a valid file. Please specify a valid .cub file", cub);
}
