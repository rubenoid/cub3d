/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress_functions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 22:44:42 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:52:28 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_reset_keys(t_player *player)
{
	player->w = 0;
	player->a = 0;
	player->s = 0;
	player->d = 0;
	player->left = 0;
	player->right = 0;
	player->up = 0;
	player->down = 0;
	player->shoot = 0;
}

int		ft_key_release(int keycode, t_player *player)
{
	if (keycode == W_KEY)
		player->w = 0;
	if (keycode == A_KEY)
		player->a = 0;
	if (keycode == S_KEY)
		player->s = 0;
	if (keycode == D_KEY)
		player->d = 0;
	if (keycode == LEFT_KEY)
		player->left = 0;
	if (keycode == RIGHT_KEY)
		player->right = 0;
	if (keycode == UP_KEY)
		player->up = 0;
	if (keycode == DOWN_KEY)
		player->down = 0;
	if (keycode == JUMP_KEY)
		player->shoot = 0;
	return (0);
}

int		ft_keypress(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->player.w = 1;
	if (keycode == A_KEY)
		cub->player.a = 1;
	if (keycode == S_KEY)
		cub->player.s = 1;
	if (keycode == D_KEY)
		cub->player.d = 1;
	if (keycode == LEFT_KEY)
		cub->player.left = 1;
	if (keycode == RIGHT_KEY)
		cub->player.right = 1;
	if (keycode == UP_KEY)
		cub->player.up = 1;
	if (keycode == DOWN_KEY)
		cub->player.down = 1;
	if (keycode == JUMP_KEY)
		cub->player.shoot = 1;
	if (keycode == ESC)
		ft_exit(cub);
	return (0);
}
