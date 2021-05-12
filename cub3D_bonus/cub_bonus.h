/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_bonus.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/23 20:05:05 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/23 20:08:07 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define NORTH		0
# define SOUTH		1
# define WEST		2
# define EAST		3
# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define ESC		53
# define BLACK		0x00000000
# define WHITE		0x00FFFFFF
# define UP_KEY		126
# define DOWN_KEY	125
# define JUMP_KEY	49
# define UDIV		1
# define VDIV		1
# define VMOVE		0.0

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
}					t_sprite;

typedef struct		s_player
{
	double			move_speed;
	double			rot_speed;
	double			px;
	double			py;
	double			dx;
	double			dy;
	double			plane_x;
	double			plane_y;
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
	int				up;
	int				down;
	int				shoot;
}					t_player;

typedef struct		s_mlx
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p[2];
	char			*win_add[2];
	int				win_bpp;
	int				win_ll;
	int				win_end;
	void			*tex_p[7];
	char			*tex_add[7];
	int				tex_width[7];
	int				tex_height[7];
	int				tex_bpp[7];
	int				tex_ll[7];
	int				tex_end[7];
	char			*tex_path[7];
	int				index_img;
}					t_mlx;

typedef struct		s_mapval
{
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				f;
	int				c;
	int				map_started;
	int				hatefull_eight;
	int				player_pos_found;
}					t_mapval;

typedef struct		s_dda_wall
{
	double			ray_dx;
	double			ray_dy;
	int				map_box_x;
	int				map_box_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				box_num;
	double			wall_hit_x;
	int				tex_width;
	int				tex_height;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}					t_dda_wall;

typedef struct		s_dda_sprites
{
	double			sprite_x;
	double			sprite_y;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				v_move_screen;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_width;
	int				tex_height;
	int				tex_x;
}					t_dda_sprites;

typedef struct		s_dda_fc
{
	int				is_floor;
	float			raydx0;
	float			raydy0;
	float			raydx1;
	float			raydy1;
	int				p;
	float			cam_z;
	float			row_dist;
	float			fl_step_x;
	float			fl_step_y;
	float			fl_x;
	float			fl_y;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
}					t_dda_fc;

typedef struct		s_cub
{
	int				**map;
	int				map_w;
	int				map_h;
	unsigned int	screen_w;
	unsigned int	screen_h;
	int				pitch;
	int				pos_z;
	double			*z_buffer;
	int				amount_sprites;
	int				save;
	t_sprite		*sprite;
	t_mlx			mlx;
	t_player		player;
	t_mapval		mapval;
	t_dda_wall		dda_wall;
	t_dda_sprites	dda_sprites;
	t_dda_fc		fc;
}					t_cub;

int					ft_check_eight(t_mapval *mapval);
int					ft_check_map_chars(t_cub *cub, char c);
int					ft_check_map_started(t_cub *cub, const char *line);
int					ft_exit(t_cub *cub);
int					ft_key_release(int keycode, t_player *player);
int					ft_keypress(int keycode, t_cub *cub);
int					ft_map_atoi(const char *c, t_cub *cub);
int					ft_put_map_in_array(t_cub *cub, const char *s);
int					render_frames(t_cub *cub);
unsigned int		my_mlx_pixel_read(t_mlx *mlx, int x, int y, int n);
void				ft_bmp(char *name, t_cub *cub);
void				ft_calc_delta(t_dda_wall *dw);
void				ft_calc_draw_start_end_spr(t_cub *cub, t_dda_sprites *ds);
void				ft_calc_steps_side_dist(t_dda_wall *dw, t_player *player);
void				ft_calc_x_coord_tex(t_dda_wall *dw);
void				ft_check_argument(t_cub *cub, const char *s);
void				ft_check_bounds_map(t_cub *cub);
void				ft_check_map_line(t_cub *cub, const char *line);
void				ft_count_sprites(t_cub *cub);
void				ft_error(char *s, t_cub *cub);
void				ft_get_map_dimensions(t_cub *cub, char **map_strings);
void				ft_init_map(t_cub *cub, char *av);
void				ft_init_mapval(t_mapval *mapval);
void				ft_jump_next_square(t_dda_wall *dw);
void				ft_look_down(t_cub *cub);
void				ft_look_up(t_cub *cub);
void				ft_malloc_map_array(t_cub *cub);
void				ft_move_backwards(t_player *player, t_cub *cub);
void				ft_move_forward(t_player *player, t_cub *cub);
void				ft_movement(t_player *player, t_cub *cub);
void				ft_parse_map(t_cub *cub, const char *map_string);
void				ft_parse_resolution(t_cub *cub, char *line);
void				ft_parse_texture(t_cub *cub, char *line, int index_text);
void				ft_relative_pos(t_cub *cub, t_dda_sprites *ds,
									t_player *player, const int *i);
void				ft_rot_left(t_player *player);
void				ft_rot_right(t_player *player);
void				ft_set_player_position(t_cub *cub);
void				ft_sprite_order(int amount_sprites, t_sprite *sprite,
									t_player *player);
void				ft_sprites(t_cub *cub, t_dda_sprites *ds);
void				ft_strafe_left(t_player *player, t_cub *cub);
void				ft_strafe_right(t_player *player, t_cub *cub);
void				ft_test_extension(char *av, t_cub *cub);
void				ft_transform_sprite(t_cub *cub, t_dda_sprites *ds);
void				ft_walls(t_cub *cub, t_dda_wall *dw);
void				my_mlx_pixel_put(t_mlx *mlx, int x, int y,
									unsigned int color);
void				ft_reset_keys(t_player *player);
void				ft_calc_dist_projection (t_dda_wall *dw, t_player *player);
void				ft_calc_draw_start_end(t_cub *cub, t_dda_wall *dw);
void				ft_calc_ray(t_cub *cub, int x);
void				ft_calc_tex_width_height(t_dda_wall *dw, t_player *player,
									t_mlx *mlx);
void				ft_calc_wall_x(t_dda_wall *dw, t_player *player);
void				ft_floor_and_ceiling(t_cub *cub, t_dda_fc *fc);
void				ft_parse_line(t_cub *cub, char *line);
void				ft_which_box_player(t_dda_wall *dw, t_player *player);
void				ft_calc_steps_fc(t_cub *cub, t_dda_fc *fc);

#endif
