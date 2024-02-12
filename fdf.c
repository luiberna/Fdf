/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:23 by luiberna          #+#    #+#             */
/*   Updated: 2024/02/12 17:03:57 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int handle_input(int keysym, t_fdf *data)
{
	if (keysym == ESCAPE)
	{
		ft_printf("The %d key (ESC) was presssed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	ft_printf("The %d key was pressed\n", keysym);
	return (0);
}

void my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char *dst;

	dst = data->data_addr + (y * data->line_lenght + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	t_fdf *fdf;

	fdf = fdf_init(argv[1]);
	mlx_loop(fdf->mlx_ptr);
}

// int main(void)
// {
// 	t_fdf *fdf;

// 	fdf->mlx_ptr = mlx_init();
// 	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, MY_RES_X, MY_RES_Y, "Fdf");
// 	mlx_loop(fdf->mlx_ptr);
// }
