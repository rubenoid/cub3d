/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_resolution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:08:35 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/21 20:35:30 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_check_resolution(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != 0)
	{
		if (ft_isdigit(line[i]) == 0 && !cub->save)
			ft_error("Resolution contains non digit character", cub);
		i++;
	}
	return (i);
}

static void	ft_screen_size_check(t_cub *cub, t_mlx *mlx)
{
	int x;
	int y;

	if (cub->save == 1)
	{
		if (cub->screen_w > 16383)
			cub->screen_w = 16383;
		if (cub->screen_h > 16383)
			cub->screen_h = 16383;
		if (cub->screen_w * cub->screen_h > 10000 * 10000)
			ft_printf("Warning, file might be too big\n"
			"For reference: w:10000 * h:10000 results in a file of ~400mb");
	}
	if (cub->save == 0)
	{
		mlx_get_screen_size(mlx->mlx_p, &x, &y);
		if ((unsigned int)x < cub->screen_w)
			cub->screen_w = x;
		if ((unsigned int)y < cub->screen_h)
			cub->screen_h = y;
	}
}

void		ft_parse_resolution(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	cub->screen_w = abs(ft_atoi(line + i));
	i += ft_check_resolution(cub, line + i);
	while (line[i] == ' ')
		i++;
	cub->screen_h = abs(ft_atoi(line + i));
	i += ft_check_resolution(cub, line + i);
	while (line[i] == ' ')
		i++;
	if (line[i] != 0)
		ft_error("Resolution contains non digit character", cub);
	if (cub->screen_w == 0)
		ft_error("Screen width is not specified or specified as 0", cub);
	if (cub->screen_h == 0)
		ft_error("Screen height is not specified or specified as 0", cub);
	cub->mapval.r += 1;
	ft_screen_size_check(cub, &cub->mlx);
}
