/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:23 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/11 15:03:41 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int handle_input(int keysym, t_fdf *data)
// {
// 	if (keysym == ESCAPE)
// 	{
// 		ft_printf("The %d key (ESC) was presssed\n", keysym);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	ft_printf("The %d key was pressed\n", keysym);
// 	return (0);
// }

void my_mlx_pixel_put(t_fdf **data, int x, int y, int color)
{
	char *dst;

	dst = (*data)->data_addr + (y * (*data)->line_lenght + x * ((*data)->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init_line(t_fdf *fdf, t_map_3d a, t_map_3d b, float x)
{
	fdf->map->steep = (b.y - a.y) / (b.x - a.x);
	fdf->map->steep = (b.x - a.x) / (fabs(b.x - a.x));
}

void	draw_line(t_fdf *fdf, t_map_3d a, t_map_3d b)
{
	float x;
	float y;

	x = a.x;
	init_line(fdf, a, b, x);
	while (fabs(b.x - x) > 0.5)
	{
		y = fdf->map->steep * (x - a.x) + a.y;
		my_mlx_pixel_put(&fdf, x, y, 0x00FF0000);
		if ((fabs(y - (fdf->map->steep * ((x + fdf->map->direction) - a.x) + a.y))) > 1)
		{
			while ((int)(y - (fdf->map->steep * ((x + fdf->map->direction) - a.x) + a.y)))
			{
				y = y + ((b.y - a.y) / (fabs(b.y - a.y)));
				my_mlx_pixel_put(&fdf, x, y, 0x00FF0000);
			}
		}
		x = x + fdf->map->direction;
	}
}
void	draw_baby(t_fdf *fdf)
{
	int x;
	int y;
	int temp_y;
	
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{	
			isometric_projection(&fdf->map->map_3d[y][x].x, &fdf->map->map_3d[y][x].y, &fdf->map->map_3d[y][x].z, fdf);
			temp_y = fdf->map->height - y;
			if (x < fdf->map->width)
				draw_line(fdf, (fdf->map->map_3d)[temp_y][x], (fdf->map->map_3d)[temp_y][x + 1]);
			if (y < fdf->map->height)
				draw_line(fdf, (fdf->map->map_3d)[temp_y][x], (fdf->map->map_3d)[temp_y - 1][x]);
			x++;
		}
		y++;
	}
			//isometric_projection(&fdf->map->map_3d[i][j].x, &fdf->map->map_3d[i][j].y, &fdf->map->map_3d[i][j].z, fdf);
			//my_mlx_pixel_put(&fdf, fdf->map->map_3d[i][j].x, fdf->map->map_3d[i][j].y, 0x00FF0000);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	map_drawing(t_fdf *fdf)
{
	int		fd;
	
	map_veri(fdf);
	fd = open(fdf->map->map_name, O_RDONLY);
	map_load(fdf, fd, 0);
	//print_map_info(fdf);
	fill_map_3d(fdf);
	//print_map_3d(fdf);
	draw_baby(fdf);
	
}

int		main(int argc, char **argv)
{
	t_fdf *fdf;

	if (argc != 2)
		return (write(2, "Error, use: ./fdf <file>\n", 26), 0);
	fdf = fdf_init(argv[1]);
	fdf->map = map_init(argv[1]);
	map_drawing(fdf);
	//free_fdf(fdf);
	mlx_loop(fdf->mlx_ptr);
}

// int main(void)
// {
// 	t_fdf *fdf;

// 	fdf->mlx_ptr = mlx_init();
// 	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, MY_RES_X, MY_RES_Y, "Fdf");
// 	mlx_loop(fdf->mlx_ptr);
// }
