/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_parse_map2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:51:43 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/04 19:04:44 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_line_not_empty(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_map_started(t_cub *cub, const char *line)
{
	int i;

	if (cub->mapval.hatefull_eight)
	{
		i = 0;
		while (ft_check_map_chars(cub, line[i]))
		{
			if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			{
				cub->mapval.map_started = 1;
				return (1);
			}
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
				line[i] == 'E')
				ft_error("Starting with the player position will"
							" never result in a valid map", cub);
			i++;
		}
	}
	return (0);
}

void	ft_get_map_dimensions(t_cub *cub, char **map_strings)
{
	int i;
	int tmp;

	i = 0;
	cub->map_w = 0;
	cub->map_h = 0;
	while (map_strings[i] && ft_line_not_empty(map_strings[i]))
	{
		tmp = ft_strlen(map_strings[i]);
		if (tmp > cub->map_w)
			cub->map_w = tmp;
		i++;
	}
	cub->map_h = i;
	if (cub->map_w <= 2 || cub->map_h <= 2)
		ft_error("Map not wide or tall enough. This will not fit", cub);
	if (cub->map_w * cub->map_h >= 30000)
		ft_error("Map too large", cub);
}

int		ft_map_atoi(const char *c, t_cub *cub)
{
	if (c[0] == ' ')
		return (-1);
	if (c[0] == ' ')
		return (-1);
	else if (c[0] == '0')
		return (0);
	else if (c[0] == '1')
		return (1);
	else if (c[0] == '2')
		return (2);
	else if (c[0] == 'N')
		return (6);
	else if (c[0] == 'S')
		return (7);
	else if (c[0] == 'W')
		return (8);
	else if (c[0] == 'E')
		return (9);
	else
		ft_error("Are you trying to put something sneaky in the map?", cub);
	return (-9);
}

void	ft_malloc_map_array(t_cub *cub)
{
	int i;

	cub->map = (int **)malloc(cub->map_h * sizeof(int *));
	if (cub->map == NULL)
		ft_error("Malloc map array failed (height)", cub);
	i = 0;
	while (i < cub->map_h)
	{
		cub->map[i] = (int *)malloc(cub->map_w * sizeof(int *));
		if (cub->map[i] == NULL)
			ft_error("Malloc map array failed (width)", cub);
		i++;
	}
}
