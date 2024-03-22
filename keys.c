/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:04:34 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/22 02:45:22 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int     movement_keys(int keysym , t_fdf *fdf)
{
    if (keysym == 0) //left(A)
		fdf->camera.offset_x -= 15;
	if (keysym == 2) //right(D)
		fdf->camera.offset_x += 15;
	if (keysym == 13) //up(W)
		fdf->camera.offset_y -= 15;
	if (keysym == 1) //down(S)
		fdf->camera.offset_y += 15;
    return(0);
}
int     rotation_keys(int keysym, t_fdf *fdf)
{
    if (keysym == 14) //rotate(E)
		fdf->iso.delta += 0.03;
	if (keysym == 12) //rotate(Q)
		fdf->iso.delta -= 0.03;
	if (keysym == 5) //rotate(G)
		fdf->iso.angle_y += 0.03;
	if (keysym == 4) //rotate(H)
		fdf->iso.angle_y -= 0.03;
    return(0);
}
int     camera_keys(int keysym, t_fdf *fdf)
{
    if (keysym == 24) //z(+)
		fdf->iso.format_z -= 1;
	if (keysym == 27) //z(-)
		fdf->iso.format_z += 1;
	if (keysym == 37) //projections(L)
		fdf->camera.projection += 1;
	if (fdf->camera.projection > 3)
		fdf->camera.projection = 1;
    if (keysym == 126) //arrowup
		fdf->camera.size_grid += 1;
	if (keysym == 125) //arrowdown
	{
		fdf->camera.size_grid -= 1;
		if (fdf->camera.size_grid < 1)
			fdf->camera.size_grid = 1;
	}
	if (keysym == 8) //Color (C)
	{
		fdf->flag++;
		if (fdf->flag == 8)
			fdf->flag = 0;
	}
    return(0);
}

int     handle_keys(int keysym, t_fdf *fdf)
{
	if (keysym == ESCAPE)
		free_fdf(fdf);
    if (keysym == 0 || keysym == 2 || keysym == 13 || keysym == 1)
        movement_keys(keysym, fdf);
    if (keysym == 14 || keysym == 12 || keysym == 5 || keysym == 4)
        rotation_keys(keysym, fdf);
    if (keysym == 24 || keysym == 27 || keysym == 37 || keysym == 125 \
	|| keysym == 126 || keysym == 8)
        camera_keys(keysym, fdf);
    // printf("key: %d\n", keysym);
	clean_image(fdf);
	return (0);
}
