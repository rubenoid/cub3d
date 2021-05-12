/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_texture.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:09:06 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/04 19:09:41 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_parse_texture(t_cub *cub, char *line, int index_text)
{
	int j;

	j = 0;
	while (line[j] == ' ')
		j++;
	cub->mlx.tex_path[index_text] = ft_strdup(line + j);
	if (cub->mlx.tex_path[index_text] == NULL)
		ft_error("Texture path could not be initialized", cub);
	if (index_text == 0)
		cub->mapval.no += 1;
	if (index_text == 1)
		cub->mapval.so += 1;
	if (index_text == 2)
		cub->mapval.we += 1;
	if (index_text == 3)
		cub->mapval.ea += 1;
	if (index_text == 4)
		cub->mapval.s += 1;
}
