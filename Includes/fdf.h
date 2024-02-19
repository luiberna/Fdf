/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:47:04 by luiberna          #+#    #+#             */
/*   Updated: 2024/02/19 16:49:09 by luiberna         ###   ########.fr       */
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

typedef struct s_map
{
	char	*map_name;
	int		**map_info;
	int		height;
	int		width;
	int		z_max;
	int 	z_min;
}				t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		endian;
	int		line_lenght;
	t_map	*map;
}						t_fdf;

//init
t_fdf 	*fdf_init(char *path);
t_map   *map_init(char *filename);

//verifiers
int		map_name_veri(char *map_name);
void    empty_line_veri(t_fdf *fdf, char *line);
int     line_digit_veri(t_fdf *fdf, char *line);
int     map_digit_veri(int fd, t_fdf *fdf);
void	map_veri(t_fdf *fdf);

//map
void    get_max_min_z(t_fdf *fdf, int nb);
int     *map_split(t_fdf *fdf, char *line);
void    map_load(t_fdf *fdf, int fd, int i);

//free
void	free_mlx(t_fdf *fdf);
void	free_fdf(t_fdf *fdf);
void    free_split(char **temp, int flag, t_fdf *fdf);

//fdf
void	map_drawing(t_fdf *fdf);



#endif