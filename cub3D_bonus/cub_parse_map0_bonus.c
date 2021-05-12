/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_parse_map0.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:45:49 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/24 18:44:03 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	ft_flood_fill_map(int x, int y, t_cub *cub)
{
	static int stack_overflow;

	stack_overflow++;
	if (stack_overflow > 30000)
		ft_error("Floodfill algorithm has a stackoverflow", cub);
	if (x < 0 || y < 0 || x >= cub->map_h || y >= cub->map_w)
		return ;
	if (cub->map[x][y] == 0 || cub->map[x][y] == 2 || cub->map[x][y] == 6 ||
		cub->map[x][y] == 7 || cub->map[x][y] == 8 || cub->map[x][y] == 9)
	{
		cub->map[x][y] = 3;
		ft_flood_fill_map(x + 1, y, cub);
		ft_flood_fill_map(x, y + 1, cub);
		ft_flood_fill_map(x - 1, y, cub);
		ft_flood_fill_map(x, y - 1, cub);
		ft_flood_fill_map(x - 1, y - 1, cub);
		ft_flood_fill_map(x - 1, y + 1, cub);
		ft_flood_fill_map(x + 1, y - 1, cub);
		ft_flood_fill_map(x + 1, y + 1, cub);
	}
	if (cub->map[x][y] == -1)
		ft_error("Space char in the map and/or map not enclosed by walls", cub);
	if (cub->map[x][y] == -99)
		ft_error("Map not enclosed by walls", cub);
	ft_check_bounds_map(cub);
}

/*
**  read cub file and free line
*/

static void	ft_read_cub_file(t_cub *cub, char **map_string, char **line)
{
	ft_check_eight(&cub->mapval);
	ft_check_map_started(cub, *line);
	if (cub->mapval.map_started)
	{
		ft_check_map_line(cub, *line);
		*map_string = ft_strjoin_freefirst(*map_string, *line);
		*map_string = ft_strjoin_freefirst(*map_string, "\n");
		if (*map_string == NULL)
			ft_error("Malloc failed: map_string, ft_init_map", cub);
	}
	else
		ft_parse_line(cub, *line);
	free(*line);
	*line = NULL;
}

void		ft_init_map(t_cub *cub, char *av)
{
	char	*line;
	char	*map_string;
	int		fd;
	int		ret;

	ft_init_mapval(&cub->mapval);
	ft_test_extension(av, cub);
	fd = open(av, O_RDONLY);
	map_string = ft_strdup("");
	if (map_string == NULL)
		ft_error("Malloc failed: map_string, ft_init_map", cub);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		ft_read_cub_file(cub, &map_string, &line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	if (ret == -1)
		ft_error("Error while reading cub file", cub);
	ft_parse_map(cub, map_string);
	ft_flood_fill_map((int)cub->player.px, (int)cub->player.py, cub);
	free(map_string);
	map_string = NULL;
}
