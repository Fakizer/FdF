/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:43:18 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:43:19 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_error(int ac)
{
	if (ac != 2)
	{
		ft_putendl(USAGE);
		exit(ERROR_EXIT);
	}
}

void	init_error(char *pref)
{
	ft_putstr_fd(PROG_NAME, 2);
	ft_putstr_fd(": ", 2);
	perror(pref);
	exit(ERROR_EXIT);
}
