/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:45:37 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/20 15:46:28 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_color(float percent, int flag, int r, int g)
{
	if (flag == 0)
		return (create_trgb(0, 255, 255, 255));
	else if (flag == 1)
		return (create_trgb(0, percent * 255, 0, 0));
	else if (flag == 2)
		return (create_trgb(0, 0, percent * 255, 0));
	else if (flag == 3)
		return (create_trgb(0, 0, 0, percent * 255));
	else if (flag == 4)
		return (create_trgb(0, g, r, 0));
	else if (flag == 5)
		return (create_trgb(0, 0, r, g));
	else if (flag == 6)
		return (create_trgb(0, g, 0, r));
	else if (flag == 7)
		return (create_trgb(0, r, g, g));
	else if (flag == 8)
		return (create_trgb(0, g, r, g));
	else if (flag == 9)
		return (create_trgb(0, g / 3, r / 0.5, r / 1.25));
	return (0);
}

int	percent_to_color(float percent, int flag)
{
	int	r;
	int	g;

	r = 255;
	g = 255;
	if (flag >= 4 && flag <= 9)
	{
		if (percent < 0.5)
			g = (255 * percent / 0.5);
		else
			r = 255 - (255 * (percent - 0.5) / 0.5);
		return (make_color(percent, flag, r, g));
	}
	else
		return (make_color(percent, flag, 0, 0));
}
