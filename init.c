/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:15:32 by luiberna          #+#    #+#             */
/*   Updated: 2024/02/19 13:16:48 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf   *fdf_init(char *path)
{
    t_fdf *fdf;
    char *win_name;

    win_name = ft_strjoin("Fdf - ", path);
    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    if (!fdf)
        return (write(2, "Malloc Error FDF\n", 17), 0);
    fdf->mlx_ptr = mlx_init();
    if (!fdf->mlx_ptr)
        return (write(2, "Error connecting to MLX\n", 25), 0);
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, MY_RES_X, MY_RES_Y, win_name);
    if (!fdf->win_ptr)
        return (write(2, "Error init window\n", 19), 0);
    fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, MY_RES_X, MY_RES_Y);
    if (!fdf->img_ptr)
        return (write(2, "Error init image\n", 18), 0);
    fdf->data_addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->line_lenght, &fdf->endian);
    fdf->map = NULL;
    return (fdf);
}

t_map   *map_init(char *filename)
{
    t_map   *map;
    
    map = (t_map *)malloc(sizeof(t_map));
    if(!map)
        return (write(2, "Error init map\n", 16), 0);
    map->height = 0;
    map->width = 0;
    map->z_max = 0;
    map->z_min = 0;
    map->map_name = filename;
    return (map);
}
