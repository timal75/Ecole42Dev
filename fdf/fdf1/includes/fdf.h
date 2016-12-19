/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:00:52 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/16 18:40:59 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include "math.h"

typedef struct		s_line_param
{
	int				dx;
	int				dy;
	int				incx;
	int				incy;
	int				inc1;
	int				inc2;
	int				e;
}					t_line_param;

typedef struct		s_point
{
	float				x;
	float				y;
	float				z;
	float				relief;
}					t_point;

typedef struct		s_lines
{
	t_point			*point;
	int				len;
} 					t_lines;

typedef struct		s_field
{
	t_lines			*line;
	int				height;
	int 			width;
}					t_field;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*data_adress;
	int				xcenter;
	int				ycenter;
	int				bpp;
	int				s_lines;
	int				endian;
	t_field			**field;
	t_field			**field_ori;
	int 			scale_w;
	int 			scale_h;
	int 			dx;
	int 			dy;
	int 			dz;
	float 			alphax;
	float 			alphay;
}					t_env;

#define WIN_WIDTH	2000
#define WIN_HEIGHT	1200
#define WIN_TITLE	"fdf"
#define IMG_WIDTH	2000
#define IMG_HEIGHT	1200
#define XCENTER		(IMG_WIDTH/2)
#define YCENTER		(IMG_HEIGHT/2)

#define	KEY_ESC		53
#define KEY_PLUS	69
#define KEY_MINUS	78
#define KEY_UP		126
#define KEY_DOWN	125
#define KEY_RIGHT	124
#define KEY_LEFT	123


int         ft_push_line(t_field **field, char **line, int height);
t_field     **ft_read_file(char *filename);
int         ft_push_point(int x, int y, int relief, t_field **field);
void        draw(void *mlx, void *window);
int         expose_hook(t_env *env);
int         key_hook(int keycode, t_env *e);
void		ft_createwindow (t_env *env);
void		ft_createimage (t_env *env);
void		ft_destroyimage (t_env *env);
void		ft_plotline (t_env *env,t_point point_ori, t_point point_des);
void		ft_draw_field (t_field **field, t_env *env);
int 		ft_get_color (t_point point_ori, t_point point_des);
void		ft_matrice(t_env *env);
int 		ft_init_mlx(t_env *env);
int			ft_expose_hook(t_env *env);
int 		ft_mouse_hook(int button, int x, int y, t_env *env);
int			ft_key_hook(int keycode, t_env *e);
void 		ft_rotate(t_env *env);

#endif
