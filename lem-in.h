/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:01:44 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/14 22:03:03 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

typedef struct			s_neightbour
{
	char				*name;
	struct s_neightbour	*next;
}						t_neightbour;

typedef struct			s_room
{
	char				*name;
	t_neightbour		*neightbour;
	struct s_room		*next;
}						t_room;

typedef struct			s_ant
{
	int					nb;
	t_room				*room;
}						t_ant;

#endif
