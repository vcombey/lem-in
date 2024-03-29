/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:19:42 by vcombey           #+#    #+#             */
/*   Updated: 2017/03/08 14:48:13 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "lem_in.h"
#include "ft_printf.h"

void	ft_exit_err(char *msg, t_file *data)
{
	int	save_errno;

	save_errno = errno;
	if (data == NULL)
		ft_printf("error: %s\n", msg);
	else if (errno == 0)
	{
		ft_printf("syntax error: %s at line %d\n", msg, data->line);
	}
	else
	{
		ft_printf("system error: %s. Error message: %s\n", msg,
				strerror(save_errno));
	}
	exit(1);
}
