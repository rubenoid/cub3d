/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_movement.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 22:42:12 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:44:15 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_movement(t_player *player, t_cub *cub)
{
	if (player->w)
		ft_move_forward(player, cub);
	if (player->s)
		ft_move_backwards(player, cub);
	if (player->a)
		ft_strafe_left(player, cub);
	if (player->d)
		ft_strafe_right(player, cub);
	if (player->left)
		ft_rot_left(player);
	if (player->right)
		ft_rot_right(player);
}
