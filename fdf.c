/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:23 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/20 15:30:25 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_image(t_fdf *fdf)
{
	int x = 0;
	int y;
	
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	while (x < 1440)
	{
		y = 0;
		while (y < 800)
		{
			my_mlx_pixel_put(&fdf, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	draw_baby(fdf);
}

int handle_keys(int keysym, t_fdf *fdf)
{
	if (keysym == ESCAPE)
		free_fdf(fdf);
	if (keysym == 126)
		fdf->camera.size_grid += 1;
	if (keysym == 125)
	{
		fdf->camera.size_grid -= 1;
		if (fdf->camera.size_grid < 1)
			fdf->camera.size_grid = 1;
	}
	if (keysym == 0) //left(A)
		fdf->camera.offset_x -= 15;
	if (keysym == 2) //right(D)
		fdf->camera.offset_x += 15;
	if (keysym == 13) //up(W)
		fdf->camera.offset_y -= 15;
	if (keysym == 1) //down(S)
		fdf->camera.offset_y += 15;
	if (keysym == 14) //rotate(E)
		fdf->iso.angle_y += 0.03;
	if (keysym == 12) //rotate(Q)
		fdf->iso.angle_y -= 0.03;
	if (keysym == 5) //rotate(G)
		fdf->iso.delta += 0.03;
	if (keysym == 4) //rotate(H)
		fdf->iso.delta -= 0.03;
	if (keysym == 24)
		fdf->iso.format_z -= 1;
	if (keysym == 27)
		fdf->iso.format_z += 1;
	if (keysym == 37)
		fdf->camera.projection += 1;
	if (fdf->camera.projection > 3)
		fdf->camera.projection = 1;
	clean_image(fdf);
	return (0);
}

void	make_fdf(t_fdf *fdf)
{
	int		fd;
	
	map_veri(fdf);
	fd = open(fdf->map->map_name, O_RDONLY);
	map_load(fdf, fd, 0);
	// print_map_info(fdf);
	fill_map_3d(fdf);
	// print_map_3d(fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, handle_keys, fdf);
	//mlx_mouse_hook(fdf->win_ptr, handle_mouse, fdf);
	draw_baby(fdf);

}

int		main(int argc, char **argv)
{
	t_fdf *fdf;

	if (argc != 2)
		return (write(2, "Error, use: ./fdf <file>\n", 26), 0);
	fdf = fdf_init(argv[1]);
	fdf->map = map_init(argv[1]);
	make_fdf(fdf);
	//free_fdf(fdf);
	mlx_loop(fdf->mlx_ptr);
}
