/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:52:12 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/21 15:52:13 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					min_xy(int x, int y)
{
	return ((x < y) ? x : y);
}

int					max_xy(int x, int y)
{
	return ((x > y) ? x : y);
}
