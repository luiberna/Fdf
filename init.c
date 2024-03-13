/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:15:32 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/13 19:17:45 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    init_vari(t_fdf *fdf)
{
    fdf->iso.angle_x = 0.523599; //30
    fdf->iso.angle_y = 0.523599;
    fdf->iso.alpha = 0;
    fdf->iso.beta = 0;
    fdf->iso.phi = 0;
    fdf->camera.offset_x = 100;
    fdf->camera.offset_y = 100;
    fdf->camera.size_grid = 10;
    fdf->camera.projection = 1;
}

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
    init_vari(fdf);
    free(win_name);
    return (fdf);
}

t_map   *map_init(char *filename)
{
    t_map   *map;
    
    map = (t_map *)malloc(sizeof(t_map));
    if(!map)
        return (write(2, "Error init map\n", 16), 0);
    map->map_name = filename;
    return (map);
}
