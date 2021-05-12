/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 18:59:28 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/06 17:42:21 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void		ft_check_argument(t_cub *cub, const char *s)
{
	if (s[0] == '-' && s[1] == '-' && s[2] == 's' && s[3] == 'a' && s[4] == 'v'
	&& s[5] == 'e' && !s[6])
	{
		cub->save = 1;
		return ;
	}
	else
	{
		ft_printf("Error\nOnly accepts --save as 2nd argument\n");
		exit(0);
	}
}

static void	ft_header_bmp(int fd, int width, int height)
{
	int		size;
	int		first_pix;
	int		headersize;
	short	plane;
	short	bpp;

	headersize = 40;
	plane = 1;
	bpp = 32;
	first_pix = 54;
	size = height * width * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	write(fd, &headersize, 4);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, &plane, 2);
	write(fd, &bpp, 2);
	while (plane <= 24)
	{
		write(fd, "\0", 1);
		plane++;
	}
}

static void	ft_put_pixel(int fd, char *addr, int width, int height)
{
	int x;
	int length;

	length = 0;
	if (width % 64 != 0)
		length = 1;
	length = (length + (width / 64)) * 256;
	x = 0;
	height -= 1;
	while (height >= 0)
	{
		while (x < width)
		{
			write(fd, &addr[height * length + x * 4], 4);
			x++;
		}
		x = 0;
		height--;
	}
}

void		ft_bmp(char *name, t_cub *cub)
{
	int		fd;
	char	*addr;
	int		width;
	int		height;

	fd = open(name, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		ft_error("Program open failed (ft_bmp)\n", cub);
	addr = cub->mlx.win_add[1];
	width = (int)cub->screen_w;
	height = (int)cub->screen_h;
	ft_header_bmp(fd, width, height);
	ft_put_pixel(fd, addr, width, height);
	exit(0);
}
