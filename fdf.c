/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:23 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/13 22:56:19 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int handle_input(int keysym, t_fdf *fdf)
// {
// 	if (keysym == ESCAPE)
// 	{
// 		ft_printf("The %d key (ESC) was presssed\n", keysym);
// 		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
// 		free_fdf(fdf);
// 	}
// 	return (0);
// }
// int key_press(int keysym, t_fdf *fdf)
// {
// 	if(keysym == SPACE)
// 	{
// 		ft_printf("The %d key SPACE was presssed\n", keysym);
// 		fdf->camera.projection = 0;
// 		ft_printf("Projection value: %d\n", fdf->camera.projection);
// 	}
// 	ft_printf("The %d key was pressed\n", keysym);
// 	return(0);
// }

void	make_fdf(t_fdf *fdf)
{
	int		fd;
	
	map_veri(fdf);
	fd = open(fdf->map->map_name, O_RDONLY);
	map_load(fdf, fd, 0);
	// print_map_info(fdf);
	fill_map_3d(fdf);
	// print_map_3d(fdf);
	//mlx_key_hook(fdf->win_ptr, handle_input, &fdf);
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
