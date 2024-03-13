/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:57:42 by luiberna          #+#    #+#             */
/*   Updated: 2024/03/13 18:54:28 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    isometric_projection(float *x, float *y, float *z, t_fdf *fdf)
{   
    float   temp_x = *x;
    float   temp_y = *y;
    float   temp_z = *z;
    *x = (temp_x - temp_y) * cos(fdf->iso.angle_x) * fdf->camera.size_grid + fdf->camera.offset_x;
    *y = -temp_z + (temp_x + temp_y) * sin(fdf->iso.angle_y) * fdf->camera.size_grid + fdf->camera.offset_y;
}
void    rotation_x(t_fdf *fdf, float *x, float *y, float *z)
{
    float temp_y;
    float temp_z;

    temp_y = *y;
    temp_z = *z;
    *y = temp_y * cos(fdf->iso.alpha) + temp_z * sin(fdf->iso.alpha);
    *z = -temp_y * sin(fdf->iso.alpha) + temp_z * cos(fdf->iso.alpha);
}

void    rotation_y(t_fdf *fdf, float *x, float *y, float *z)
{
    float temp_x;
    float temp_z;

    temp_x = *x;
    temp_z = *z;
    *x = temp_x * cos(fdf->iso.beta) + temp_z * sin(fdf->iso.beta);
    *z = -temp_x * sin(fdf->iso.beta) + temp_z * cos(fdf->iso.beta);
}
void    rotation_z(t_fdf *fdf, float *x, float *y, float *z)
{
    float temp_x;
    float temp_y;

    temp_x = *x;
    temp_y = *y;
    *x = temp_x * cos(fdf->iso.phi) - temp_y * sin(fdf->iso.phi);
    *y = -temp_x * sin(fdf->iso.phi) + temp_y * cos(fdf->iso.phi);
}

void	projections(float *x, float *y, float *z, t_fdf *fdf)
{
	rotation_x(fdf, x, y, z);
    rotation_y(fdf, x, y, z);
    rotation_z(fdf, x, y, z);
    if (fdf->camera.projection == 1)
        isometric_projection(x, y, z, fdf);
}
