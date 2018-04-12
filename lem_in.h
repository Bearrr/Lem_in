/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:23:12 by ireva             #+#    #+#             */
/*   Updated: 2017/10/25 19:23:36 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "./libft/libft.h"

typedef struct		s_listz
{
	char			*name;
	int				start;
	int				end;
	int				ants;
	int				w_name;
	struct s_listz	*next;
}					t_listz;

typedef struct		s_lem
{
	int				ants;
	int				start;
	int				end;
	char			*temp_name;
	char			*temp_sname;
	char			**net;
	char			**names;
	int				*way;
	int				w_size;
	int				w_start;
	int				w_end;
	int				flag;
	int				f;
	t_listz			*best_way;
	int				links;
	int				nod_count;
	char			**temp_way_arr;
	char			**best_way_arr;
	int				free_start;
	int				free_end;
	int				k;
	int				best_arr_size;
}					t_lem;

t_lem				g_lem;

void				time_to_exit(void);
char				*ft_wordslenz(char *s, char c);
void				validation(char *line, int fd, t_listz **room_list);
void				if_link(char *line, t_listz **room_list);
void				check_link_name(char *line, t_listz **rooom_list);
void				check_link_sname(char *line, t_listz **rooom_list);
void				create_net_names(t_listz **room_list);
void				wr_names(t_listz **room_list);
void				create_net(t_listz **room_list);
void				create_nod(char *line, t_listz **room_list);
void				create_net(t_listz **room_list);
void				create_net_names(t_listz **room_list);
int					count_spaces(char *line);
int					count_defis(char *line);
int					if_alpha(char *line);
void				wr_names(t_listz **room_list);
void				if_room(char *line, t_listz **room_list);
void				is_valid_room(char *line);
void				is_valid_room(char *line);
void				way_s_e(t_listz **room_list);
void				init(void);
void				init_ints(void);
void				check_way(int j);
void				delete_last_room(void);
void				cr_temp_arr(int j);
void				create_b_way_arr(void);
void				create_best_arr(void);
void				check_duplic(char *line, t_listz **room_list);
void				norm(t_listz **current);
void				norma(t_listz **room_list, t_listz **end, int i);
void				writter(t_listz *next);

#endif
