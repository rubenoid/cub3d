/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_color0.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:40:51 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/03 20:43:12 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		ft_check_color_line_digit(const char *line, int *i, int *num)
{
	int old_i;

	old_i = *i;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		(*i)++;
	}
	if (*i > old_i)
		*num += 1;
}

static void		ft_check_color_line_comma(const char *line, int *i, int *comma)
{
	if (line[*i] == ',')
	{
		*comma += 1;
		(*i)++;
	}
}

static void		ft_check_color_line(t_cub *cub, const char *line)
{
	int comma;
	int num;
	int i;

	comma = 0;
	num = 0;
	i = 0;
	ft_check_color_line_space(line, &i);
	ft_check_color_line_digit(line, &i, &num);
	ft_check_color_line_space(line, &i);
	ft_check_color_line_comma(line, &i, &comma);
	ft_check_color_line_space(line, &i);
	ft_check_color_line_digit(line, &i, &num);
	ft_check_color_line_space(line, &i);
	ft_check_color_line_comma(line, &i, &comma);
	ft_check_color_line_space(line, &i);
	ft_check_color_line_digit(line, &i, &num);
	ft_check_color_line_space(line, &i);
	if (line[i] > 0 && ft_isascii(line[i]))
		ft_error("Too much values and/or invalid characters\n", cub);
	if (num != 3 || comma != 2)
		ft_error("num not 3 and/or comma not 2\n", cub);
}

static void		ft_get_color(int *r, int *g, int *b, const char *line)
{
	*r = ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	*g = ft_atoi(line);
	while (*line != ',')
		line++;
	line++;
	*b = ft_atoi(line);
}

void			ft_parse_color(t_cub *cub, const char *line, char c)
{
	int t;
	int r;
	int g;
	int b;

	ft_check_color_line(cub, line);
	ft_get_color(&r, &g, &b, line);
	t = 0;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("Color value incorrect", cub);
	if (c == 'F')
	{
		cub->mapval.f += 1;
		cub->floor = (t << 24 | r << 16 | g << 8 | b);
	}
	else
	{
		cub->mapval.c += 1;
		cub->ceiling = (t << 24 | r << 16 | g << 8 | b);
	}
}
