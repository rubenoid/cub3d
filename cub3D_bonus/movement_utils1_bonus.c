/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_utils1.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 22:55:37 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/24 18:45:22 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_look_up(t_cub *cub)
{
	cub->pitch += 400 * cub->player.move_speed;
	if (cub->pitch > 200)
		cub->pitch = 200;
}

void	ft_look_down(t_cub *cub)
{
	cub->pitch -= 400 * cub->player.move_speed;
	if (cub->pitch < -200)
		cub->pitch = -200;
}
