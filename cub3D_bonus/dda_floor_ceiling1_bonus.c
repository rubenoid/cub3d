/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_floor_ceiling1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 21:43:29 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 21:43:49 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_calc_steps_fc(t_cub *cub, t_dda_fc *fc)
{
	fc->fl_step_x = fc->row_dist * (fc->raydx1 - fc->raydx0) / cub->screen_w;
	fc->fl_step_y = fc->row_dist * (fc->raydy1 - fc->raydy0) / cub->screen_w;
	fc->fl_x = cub->player.px + fc->row_dist * fc->raydx0;
	fc->fl_y = cub->player.py + fc->row_dist * fc->raydy0;
}
