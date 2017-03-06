/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:01:44 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/06 21:46:07 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#define LINES			10000

typedef struct			s_room
{
	char				*name;
	int					n;
	struct s_room		*next;
}						t_room;

typedef struct			s_ways
{
	t_room				*solus;
	int					nb_ant;
	struct s_ways		*next;
}						t_ways;

typedef struct			s_anthill
{
	int					nb_ant;
	int					nb_room;
	t_room				*room;
	int					start;
	int					end;
	int					**mat;
}						t_anthill;

typedef struct			s_file
{
	char				**data;
	int					line;
	int					column;
}						t_file;

typedef struct			s_bfs
{
	t_room				*already_seen;
	t_room				*to_see;
	int					*way;
}						t_bfs;

void					get_rooms(t_anthill *a, t_file *f);
void					init_mat(t_anthill *a);
int						name_to_number(char *name, t_room *r);
char					*number_to_name(int n, t_room *r);
int						get_links(char *line, t_anthill *a);
int						is_a_number(char *line);
void					room_add(char *name, t_anthill *a);
t_room					*find_best_way(t_anthill a);
void					display_solus(t_room *solus, t_anthill a);
t_ways					*find_best_ways(t_anthill a);
void					display_multi_solus(t_ways *ways, t_anthill a);
void					free_all_the_shit(t_ways *ways, t_anthill a, t_file f);
void					free_room(t_room *r);

/*
**utils
*/

void					ft_exit_err(char *msg, t_file *data);
int						room_len(t_room *r);

/*
**debug
*/

void					display_room(t_room *r);
void					display_mat(t_anthill a);

#endif
