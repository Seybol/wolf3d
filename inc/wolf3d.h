/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 21:44:54 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 18:05:39 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include <sys/time.h>
# include "mlx.h"
# include "keys.h"
# include <pthread.h>
# include <time.h>
# define WIDTH 1400
# define HEIGHT 900

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_eye
{
	t_vector		*pos;
	t_vector		*dir;
	t_vector		*screen;
	t_vector		*array;
}					t_eye;

typedef struct		s_ray
{
	t_vector		*pos;
	t_vector		*dir;
	double			step;
}					t_ray;

typedef struct		s_c_data
{
	int				x;
	int				y;
	t_vector		*step;
	t_vector		*dist;
	t_vector		*next_dist;
	char			wall;
	char			dir;
	double			range;
	int				objects;
	double			precise_hit;
}					t_c_data;

typedef struct		s_event
{
	char			first_image;
	char			forward;
	char			backward;
	char			turn;
	char			strafe_right;
	char			strafe_left;
	double			move_forward_speed;
	double			turn_speed;
	double			move_backward_speed;
	int				bounce;
}					t_event;

typedef struct		s_modifiers
{
	int				shift;
}					t_modifiers;

typedef struct		s_draw
{
	double			line_height;
	int				start;
	int				end;
	int				color;
}					t_draw;

typedef struct		s_img
{
	char			*data;
	int				sl;
	int				endian;
	int				bpp;
	void			*img;
	int				x;
	int				y;
	char			*name;
}					t_img;

typedef struct		s_thread
{
	int				threads;
	pthread_t		t;
	void			*i;
	t_ray			*ray;
	t_vector		*array;
	t_c_data		*c;
}					t_thread;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_thread		th[8];
	t_eye			*eye;
	t_event			*e;
	int				mx;
	int				my;
	char			**map;
	struct timeval	actual_time;
	struct timeval	actual_time2;
	t_img			*textures[12];
	t_img			*weapon;
	t_img			*pointer;
	t_img			*hud;
	t_img			*hud2;
	t_img			*commands;
	t_img			*gameover;
	char			**gif1;
	int				mouse;
	int				keys;
	int				text_gun;
	int				fire;
	int				sizex;
	int				sizey;
	t_modifiers		*m;
	int				run;
	int				mouseon;
}					t_data;
void				ft_close(t_data *i, char error);
void				putpixel(int x, int y, unsigned int color, t_img *img);
t_img				*ft_data_img(t_data *i, int length, int heigth);
t_data				*ft_data_window(char **map);
t_vector			*init_vector(double x, double y);
t_eye				*init_eye();
t_ray				*init_ray(t_eye *eye, int x);
t_event				*init_event(void);
void				test_forward(t_data *d);
void				test_backward(t_data *d);
void				test_turn(t_data *d);
void				test_strafe_right(t_data *d);
void				test_strafe_left(t_data *d);
char				**ft_parse(int fd);
t_event				*init_event(void);
t_vector			*init_vector(double x, double y);
t_eye				*init_eye();
t_ray				*init_ray(t_eye *eye, int x);
t_c_data			*init_c_data(int x, t_ray *ray);
int					getpixel(int x, int y, t_img *img);
int					draw_image_textures(t_thread *t);
int					set_data(t_ray *ray, t_c_data *c, t_vector *array);
void				free_all(t_thread *t);
void				display(t_data *init);
int					draw_image_no_textures(t_thread *t);
int					ft_mouse_julia(int x, int y, void *param);
int					dda_algorithm(t_ray *ray, t_c_data *c, t_vector *array,
		t_data *d);
t_img				*ft_init_img(t_data *d, char *dir, char *name);
int					set_data(t_ray *ray, t_c_data *c, t_vector *array);
void				fill_borders(char **s);
int					noevent(void *p);
int					check_param(char *s1, char *s2, char *s3, char *s4);
void				remove_transparency(t_img *img);
void				black_transparency(t_img *img);
void				copy_image(t_img *img, t_img *source);
int					there_is_place(char **s);
int					tab_length(char **s);
int					tab_height(char **s);
int					ft_key_up(int keycode, t_data *d);
int					ft_key_press(int keycode, t_data *d);
int					ft_close_cross(void *data);
int					is_between(char x, char a, char b);
void				fire_forward(t_data *d);
void				fire_backward(t_data *d);
void				fire_strafe_left(t_data *d);
void				fire_strafe_right(t_data *d);
void				handle_bounce(t_data *d);
int					tab_length(char **s);
int					check_tab(char **s);
#endif
