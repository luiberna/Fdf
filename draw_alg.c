/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:04:00 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/19 21:39:56 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_fdf **fdf, int x, int y, int color)
{
	char *dst;

	dst = (*fdf)->data_addr + (y * (*fdf)->line_lenght + x * ((*fdf)->bpp / 8));
	*(unsigned int*)dst = color;
}

void	treat_edge(t_fdf *fdf, t_map_3d a, t_map_3d b, float x)
{
	int y;

	y= a.y;
	while (fabs(b.y - y) > 0.5)
	{
		if (x >= 0 && x <= MY_RES_X)
			my_mlx_pixel_put(&fdf, x, y, 0x7FFFD4);
		y += ((b.y - a.y) / (fabs(b.y - a.y)));
	}
	return ;
}

void	init_line(t_fdf *fdf, t_map_3d a, t_map_3d b, float x)
{
	if (fabs(b.x - a.x) <= 0.5 && fabs(b.y - a.y) > 0.5)
		treat_edge(fdf, a, b, x);
	fdf->map->steep = (b.y - a.y) / (b.x - a.x);
	fdf->map->direction = (b.x - a.x) / (fabs(b.x - a.x));
}

void	draw_line(t_fdf *fdf, t_map_3d a, t_map_3d b)
{
	float x;
	float y;
	
	projections(&a.x, &a.y, &a.z, fdf);
	projections(&b.x, &b.y, &b.z, fdf);
	x = a.x;
	init_line(fdf, a, b, x);
	while (fabs(b.x - x) > 0.5)
	{
		y = (fdf->map->steep) * (x - a.x) + a.y;
		if (x >= 0 && x <= MY_RES_X)
			my_mlx_pixel_put(&fdf, round(x), round(y), 0x7FFFD4);
		if ((fabs(y - (fdf->map->steep * ((x + fdf->map->direction) - a.x) + a.y))) > 1)
		{
			while ((int)(y - (fdf->map->steep * ((x + fdf->map->direction) - a.x) + a.y)))
			{
				y = y + ((b.y - a.y) / (fabs(b.y - a.y)));
				if (x >= 0 && x <= MY_RES_X)
					my_mlx_pixel_put(&fdf, x, y, 0x7FFFD4);
			}
		}
		x = x + fdf->map->direction;
	}
}

void draw_baby(t_fdf *fdf) 
{
    int i;
    int j;

    j = 0;
    while (j < fdf->map->height) 
	{
        i = 0;
        while (i < fdf->map->width - 1) 
		{
            draw_line(fdf, fdf->map->map_3d[j][i], fdf->map->map_3d[j][i + 1]);
            i++;
        }
        j++;
    }
    j = 0;
    while (j < fdf->map->height - 1)
	{
        i = 0;
        while (i < fdf->map->width)
		{
            draw_line(fdf, fdf->map->map_3d[j][i], fdf->map->map_3d[j + 1][i]);
            i++;
        }
        j++;
    }
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
