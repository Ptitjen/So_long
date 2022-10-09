/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicorn_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:40 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 15:09:45 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNICORN_GAME_H
# define UNICORN_GAME_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# define TILE_SIZE 32

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_list_item {
	int		nb;
	t_coord	*coord;
}	t_list_item;

typedef struct s_unicorn {
	void	*image;
	void	*image_up;
	void	*image_down;
	void	*image_left;
	void	*image_right;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_unicorn;

typedef struct s_enemy {
	void		*image;
	void		**anim;
	int			nb_image;
	int			width;
	int			height;
	t_list_item	list_i;
}	t_enemy;

typedef struct s_food {
	void		*image;
	void		**anim;
	int			nb_image;
	int			width;
	int			height;
	t_list_item	list_i;
}	t_food;

typedef struct s_exit {
	void		*image;
	void		**anim;
	int			nb_image;
	int			width;
	int			height;
	t_list_item	list_i;
}	t_exit;

typedef struct s_background {
	void		*image;
	int			width;
	int			height;
	t_list_item	list_i;
}	t_background;

typedef struct s_wall {
	void		*image;
	int			width;
	int			height;
	t_list_item	list_i;
}	t_wall;

typedef struct s_win_size {
	int	height;
	int	width;
}	t_win_size;

typedef struct s_game {
	void			*mlx;
	void			*win;
	char			*lst;
	char			**map;
	int				score;
	int				game_over;
	int				all_food_eaten;
	t_unicorn		unicorn;
	t_enemy			enemy;
	t_food			food;
	t_exit			exit;
	t_wall			wall;
	t_background	background;
	t_win_size		win_size;
}	t_game;

//t_game		*ft_anim_unicorn(t_game *game, int key);
t_game		ft_anim_exit(t_game game);
t_game		ft_anim_enemy(t_game game);
t_game		ft_anim_food(t_game game);
t_game		*ft_change_coord_enemy(t_game *game, int n, int key);
t_game		ft_change_direction(t_game game, int key);
t_game		ft_check_size(t_game game, int fd);
t_game		*ft_eat_food(t_game *game);
t_game		ft_game_init(t_game game, int fd);
t_game		*ft_game_over(t_game *game);
t_game		*ft_game_won(t_game *game);
t_game		ft_init_unicorn(t_game game);
t_game		ft_init_enemy(t_game game);
t_game		ft_init_food(t_game game, int choice);
t_game		ft_init_exit(t_game game);
t_game		ft_init_wall(t_game game);
t_game		ft_init_background(t_game game);
t_game		ft_load_unicorn_images(t_game game);
t_game		*ft_move_unicorn(t_game *game, int key);
t_game		*ft_move_enemy(t_game *game);
t_game		*ft_update_enemy_up(t_game *game, int n);
t_game		*ft_update_enemy_left(t_game *game, int n);
t_game		*ft_update_enemy_right(t_game *game, int n);
t_game		*ft_update_enemy_down(t_game *game, int n);
t_coord		*ft_add_to_list(t_coord *coord, int x, int y);
t_coord		ft_search_spot(char **str, char c);
t_list_item	ft_search_multi(char **str, char c);
int			ft_animate_enemy(t_game *game);
int			ft_animate_food(t_game *game);
int			ft_animate_exit(t_game *game);
int			ft_animate_all(t_game *game);
int			ft_random(void);
int			ft_check_around(int x, int y, t_game *game, char dir);
int			ft_check_if_move_ok(t_game game, int key);
int			ft_check_arg_error(int argc, char **argv);
int			ft_check_collision(t_game game, int key);
int			ft_check_collision_exit(t_game game, int key);
int			ft_check_collision_enemy(t_game *game, t_coord coord, int key);
int			ft_close_game(t_game *game);
int			ft_deal_key(int key, t_game *game);
int			ft_is_line_of_1(char *str);
int			ft_random(void);
int			ft_strlen_map(char *str);
int			ft_verify_nb_unicorn(char **str, char c);
int			ft_wrong_char(char *str);
void		ft_check_game_end(t_game *game);
void		ft_check_map_error(int ref_width, char *str, int check, \
t_game game);
void		ft_clean_close(t_game *game);
void		ft_destroy_anim(t_game *game);
void		ft_draw_window(t_game *game, int i);
void		ft_free_all(t_game *game);
void		ft_free_and_close(t_game game);
void		ft_init_wall_under_string(t_game *game, int choice);
void		ft_load_food(t_game *game);
void		ft_load_wall(t_game *game);
void		ft_load_exit(t_game *game);
void		ft_load_enemy(t_game *game);
void		ft_load_background(t_game *game);
void		ft_map_not_closed(t_game game);
void		ft_no_exit(t_game game);
void		ft_no_food(t_game game, int choice);
char		**ft_split(const char *str, char c);
char		*ft_itoa(int n);
#endif