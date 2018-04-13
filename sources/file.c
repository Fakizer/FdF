/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:58:00 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:58:02 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split_line(char **split_line)
{
	int				i;

	i = 0;
	while (split_line[i] != '\0')
	{
		free(split_line[i]);
		i++;
	}
	free(split_line);
}

size_t	line_len(char **split_line)
{
	size_t			len;

	len = 0;
	while (split_line[len] != '\0')
		len++;
	return (len);
}
