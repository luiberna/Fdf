/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:02:07 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/14 00:44:14 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->map_info[i]);
        i++;
    }
    i = 0;
    while (i < map->height)
    {
        free(map->map_3d[i]);
        i++;
    }
    free(map->map_info);
    free(map->map_3d);
    free(map);
}

void free_mlx(t_fdf *fdf)
{
    if (fdf->win_ptr)
        mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
    if (fdf->img_ptr)
        mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
    free(fdf->mlx_ptr);
    free(fdf);
}

void free_fdf(t_fdf *fdf)
{
    free_map(fdf->map);
    free_mlx(fdf);
    exit (1);
}
/* Recieves the split's double pointer, a flag and the struct fdf.
If the flag is 1, the line has a digit and the program should stop */
void    free_split(char **temp, int flag, t_fdf *fdf)
{
    int     i;
    
    if (flag == 1)
    {
        write (2, "Error, non digit in map\n", 25);
        free_fdf (fdf);
    }
    if (flag == 2)
    {
        i = 0;
        while (temp[i])
        {
            free(temp[i]);
            i++;
        }
        free(temp);
    }
}
