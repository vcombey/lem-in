/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:01:44 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/18 18:31:22 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

typedef struct			s_neightbour
{
	char				*name;
	struct s_neightbour	*next;
}						t_neightbour;

typedef struct			s_room2
{
	char				*name;
	t_neightbour		*neightbour;
	struct s_room		*next;
}						t_room2;

typedef struct			s_room
{
	char				*name;
	int					n;
	struct s_room		*next;
}						t_room;

typedef struct			s_anthill
{
	int					nb_ant;
	int					nb_room;
	t_room				*room;
	int					start;
	int					end;
	int					**mat;
}						t_anthill;

#endif
