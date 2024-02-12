/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:47:04 by luiberna          #+#    #+#             */
/*   Updated: 2024/02/12 17:07:30 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <errno.h>

# define ESCAPE 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define SPACE 49
# define MOUSE_LEFTCLICK 1
# define MOUSE_RIGHTCLICK 2
# define MY_RES_X 1440
# define MY_RES_Y 800

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		endian;
	int		line_lenght;
}						t_fdf;

static t_fdf *fdf_init(char *path);

#endif