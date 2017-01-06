/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:00:52 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/06 21:54:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include "math.h"

typedef struct				s_line_param
{
	int						dx;
	int						dy;
	int						incx;
	int						incy;
	int						inc1;
	int						inc2;
	int						e;
}							t_line_param;

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
	int						relief;
	int 					color;
	int 					r;
	int 					g;
	int 					b;
}							t_point;

typedef struct				s_relief
{
	int						max;
	int						min;
}							t_relief;

typedef struct				s_lines
{
	t_point					*point;
	int						len;
} 							t_lines;

typedef struct				s_field
{
	t_lines					*line;
	int						height;
	int 					width;
}							t_field;

typedef struct				s_env
{
	void					*mlx;
	void					*window;
	void					*image;
	char					*data_adress;
	int						xcenter;
	int						ycenter;
	int						bpp;
	int						s_lines;
	int						endian;
	t_field					**field;
	t_field					**field_ori;
	int 					**tab;
	int 					scale;
	int 					scalez;
	int 					dx;
	int 					dy;
	int 					dz;
	int 					xalpha;
	int 					yalpha;
	int 					zalpha;
	float 					alphax;
	float 					alphay;
	float					alphaz;
}							t_env;

#define WIN_WIDTH			2000
#define WIN_HEIGHT			1200
#define WIN_TITLE			"fdf"
#define IMG_WIDTH			2000
#define IMG_HEIGHT			1200
#define XCENTER				(IMG_WIDTH/2)
#define YCENTER				(IMG_HEIGHT/2)
#define	scale_w				((((WIN_WIDTH)/(*env->field)->width))/4)
#define scale_h				((((WIN_HEIGHT)/(*env->field)->height))/4)

#define	KEY_ESC				53
#define KEY_PLUS			69
#define KEY_MINUS			78
#define KEY_UP				126
#define KEY_DOWN			125
#define KEY_RIGHT			124
#define KEY_LEFT			123
#define KEY_RESET			71
#define KEY_1				83
#define KEY_2				84
#define KEY_4				86
#define KEY_5				87
#define KEY_7				89
#define KEY_8				91
#define KEY_PAGEUP			116
#define KEY_PAGEDOWN		121

#define	cosx 				cos(env->alphax)
#define	cosy 				cos(env->alphay)
#define	cosz 				cos(env->alphaz)
#define	sinx 				sin(env->alphax)
#define	siny 				sin(env->alphay)
#define	sinz 				sin(env->alphaz)
#define field(i,j)			(*field)->line[i].point[j]
#define field_ori(i,j)		(*field_ori)->line[i].point[j]


int         				ft_push_line(t_field **field, char **line, int height);
t_field     				**ft_read_file(char *filename);
int         				ft_push_point(int x, int y, char *str, t_field **field);
void        				ft_draw(void *mlx, void *window);
int         				ft_expose_hook(t_env *env);
int         				ft_key_hook(int keycode, t_env *e);
void						ft_createwindow(t_env *env);
void						ft_createimage(t_env *env);
void						ft_destroyimage(t_env *env);
void						ft_destroywindow(t_env *env);
void						ft_plotline (t_env *env,t_point point_ori, t_point point_des);
void						ft_draw_field(t_field **field, t_env *env);
int 						ft_get_color(t_point point_ori, t_point point_des);
void						ft_matrice(t_env *env);
int 						ft_init_mlx(t_env *env);
int							ft_expose_hook(t_env *env);
int 						ft_mouse_hook(int button, int x, int y, t_env *env);
int							ft_key_hook(int keycode, t_env *e);
void 						ft_matrice_rotate(t_env *env);
void 						ft_matrice_scale(t_env *env);
void 						ft_matrice_trans(t_env *env);
void						ft_freememory(t_env *env);
int 						ft_key_hook_trans(int keycode, t_env *e);
int 						ft_key_hook_rot(int keycode, t_env *e);
int 						ft_key_hook_scale(int keycode, t_env *e);
int 						ft_key_hook_z(int keycode, t_env *e);
void						ft_init_param_matrice (t_env *env);
void						ft_freefield(t_field **field);
int 						ft_init_field(t_env *env, t_field **field);
int							ft_linesplit(t_field **field, int height, char **line);
void						ft_penteinf(t_env *env, t_point point_ori, t_point point_des);
void						ft_pentesup(t_env *env, t_point point_ori, t_point point_des);
void						ft_lightpixel(t_point point, t_env *env, int color);
void						ft_init_point(t_field **field, t_point *point, int i, int j);
void						ft_get_line_param(t_line_param *param_line, t_point point_ori,
								t_point point_des);
int 						ft_exist(int i, int j, t_field **field);
int							ft_reliefscale(t_env *env);
void						ft_relief(t_env *env, t_relief *relief);
void						ft_legende(t_env *e);
void						ft_legende_cmd(t_env *e);
void						ft_legende_pos(t_env *e);
void						ft_legende_rot(t_env *e);
void						ft_legende_scale(t_env *e);
void 						ft_getcolor(t_point *point, char *str);
int 						ft_convertcolor(char c, char d);
int 						ft_decimal(char d);
int 						ft_zbuffer(t_point point, t_env *env);
void						ft_lightpoint(t_point point, t_env *env);
int 						ft_init_tab(t_env *env);
void						ft_freetab(t_env *env);
int							ft_init(t_env *env, t_field **field);


#endif
