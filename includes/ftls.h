/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <stdlib.h>

# include "libft.h"

typedef struct		s_cam
{
	double			x_cam;
	double			y_cam;
	double			z_cam;
	double			angle_x_cam;
	double			angle_y_cam;
	double			angle_z_cam;
	double			vect_x;
	double			vect_y;
	double			vect_z;
}					t_cam;

typedef struct		s_coord
{
	double			sphere_one;
	double			sphere_two;
	double			sphere_point_x;
	double			sphere_point_y;
	double			sphere_point_z;
	double			sphere_normal_x;
	double			sphere_normal_y;
	double			sphere_normal_z;
	double			plane;
	double			plane_point_x;
	double			plane_point_y;
	double			plane_point_z;
	double			plane_normal_x;
	double			plane_normal_y;
	double			plane_normal_z;
	double			cone_one;
	double			cone_two;
	double			cone_point_x;
	double			cone_point_y;
	double			cone_point_z;
	double			cone_normal_x;
	double			cone_normal_y;
	double			cone_normal_z;
	double			cylinder_one;
	double			cylinder_two;
	double			cylinder_point_x;
	double			cylinder_point_y;
	double			cylinder_point_z;
	double			cylinder_normal_x;
	double			cylinder_normal_y;
	double			cylinder_normal_z;
	double			sphere2_one;
	double			sphere2_two;
	double			sphere2_point_x;
	double			sphere2_point_y;
	double			sphere2_point_z;
	double			sphere2_normal_x;
	double			sphere2_normal_y;
	double			sphere2_normal_z;
	double			cone2_one;
	double			cone2_two;
	double			cone2_point_x;
	double			cone2_point_y;
	double			cone2_point_z;
	double			cone2_normal_x;
	double			cone2_normal_y;
	double			cone2_normal_z;
	double			cylinder2_one;
	double			cylinder2_two;
	double			cylinder2_point_x;
	double			cylinder2_point_y;
	double			cylinder2_point_z;
	double			cylinder2_normal_x;
	double			cylinder2_normal_y;
	double			cylinder2_normal_z;
}					t_coord;

typedef struct		s_vars
{
	int				x;
	int				y;
	double			color;
}					t_vars;

typedef struct		s_rt
{
	int				reset;
	char			*map;
	char			*addr;
	void			*mlx;
	void			*win;
	void			*img;
	int				bits;
	int				s_line;
	int				endian;
	void			*xpm;
	int				*xpm_addr;
	int				xpm_s;
	int				xpm_e;
	int				xpm_b;
	int				xpm_x;
	int				xpm_y;
	double			x_cam;
	double			y_cam;
	double			z_cam;
	double			angle_x_cam;
	double			angle_y_cam;
	double			angle_z_cam;
	double			vect_x;
	double			vect_y;
	double			vect_z;
	double			x_sphere;
	double			y_sphere;
	double			z_sphere;
	double			angle_x_sphere;
	double			angle_y_sphere;
	double			angle_z_sphere;
	double			radius_sphere;
	double			shine_sphere;
	unsigned int	color_sphere;
	double			x_plane;
	double			y_plane;
	double			z_plane;
	double			angle_x_plane;
	double			angle_y_plane;
	double			angle_z_plane;
	double			shine_plane;
	unsigned int	color_plane;
	double			x_cone;
	double			y_cone;
	double			z_cone;
	double			angle_x_cone;
	double			angle_y_cone;
	double			angle_z_cone;
	double			angle_cone;
	double			shine_cone;
	unsigned int	color_cone;
	double			x_cylinder;
	double			y_cylinder;
	double			z_cylinder;
	double			angle_x_cylinder;
	double			angle_y_cylinder;
	double			angle_z_cylinder;
	double			rayon_cylinder;
	double			shine_cylinder;
	unsigned int	color_cylinder;
	double			x_sphere2;
	double			y_sphere2;
	double			z_sphere2;
	double			angle_x_sphere2;
	double			angle_y_sphere2;
	double			angle_z_sphere2;
	double			radius_sphere2;
	double			shine_sphere2;
	unsigned int	color_sphere2;
	double			x_cone2;
	double			y_cone2;
	double			z_cone2;
	double			angle_x_cone2;
	double			angle_y_cone2;
	double			angle_z_cone2;
	double			angle_cone2;
	double			shine_cone2;
	unsigned int	color_cone2;
	double			x_cylinder2;
	double			y_cylinder2;
	double			z_cylinder2;
	double			angle_x_cylinder2;
	double			angle_y_cylinder2;
	double			angle_z_cylinder2;
	double			rayon_cylinder2;
	double			shine_cylinder2;
	unsigned int	color_cylinder2;
	double			x_spot;
	double			y_spot;
	double			z_spot;
	double			vect_l_x;
	double			vect_l_y;
	double			vect_l_z;
	double			norme_l;
	double			norme_obj;
	double			prod_scal;
	unsigned int	color_spot;
}					t_rt;

/*
** main.c
*/
void				init_scene(t_rt *rt);

/*
** raytrace.c
*/
void				draw_reload(t_rt *rt);
void				background(t_rt *rt);
int					make_graph(t_rt *rt);
void				draw_shape(int x, int y, unsigned int color, t_rt *rt);

/*
** initialize.c
*/
void				init_camera(int x, int y, t_rt *rt);
void				init_sphere(t_rt *rt);
void				init_plane(t_rt *rt);
void				init_cone(t_rt *rt);
void				init_cylinder(t_rt *rt);

/*
** initialize2.c
*/
void				init_sphere2(t_rt *rt);
void				init_cone2(t_rt *rt);
void				init_cylinder2(t_rt *rt);
void				init_sphere3(t_rt *rt);
void				init_sphere4(t_rt *rt);

/*
** initialize3.c
*/
void				init_sphere5(t_rt *rt);
void				init_plane2(t_rt *rt);
void				init_cone3(t_rt *rt);
void				init_cylinder3(t_rt *rt);
void				init_cylinder4(t_rt *rt);

/*
** trig.c
*/
double				trig_sphere(t_rt *rt, t_coord *coord);
double				trig_plane(t_rt *rt, t_coord *coord);
double				trig_cone(t_rt *rt, t_coord *coord);
double				trig_cylinder(t_rt *rt, t_coord *coord);

/*
** trig2.c
*/
double				trig_sphere2(t_rt *rt, t_coord *coord);
double				trig_plane2(t_rt *rt, t_coord *coord);
double				trig_cone2(t_rt *rt, t_coord *coord);
double				trig_cylinder2(t_rt *rt, t_coord *coord);

/*
** color.c
*/
unsigned int		color_shape(t_coord *coord, t_rt *rt);
unsigned int		lighting(t_rt *rt, t_coord *coord, int obj);

/*
** rotate.c
*/
void				rotate_x(double *x, double *y, double *z, double degree);
void				rotate_y(double *x, double *y, double *z, double degree);
void				rotate_z(double *x, double *y, double *z, double degree);

/*
** switch.c
*/
unsigned int		object_color(t_rt *rt, int obj);
int					shadow(t_rt *rt, t_coord *coord, int obj);
double				trig_shape(t_rt *rt, t_coord *coord, int obj);

/*
** all shapes being parsed, each has own source file
*/
double				sphere(t_rt *rt, t_coord *coord, t_cam *cam, double delta);
double				cylinder(t_rt *rt, t_coord *coord, t_cam *cam);
double				cone(t_rt *rt, t_coord *coord, t_cam *cam);
double				plane(t_rt *rt, t_coord *coord, t_cam *cam);
double				sphere2(t_rt *rt, t_coord *coord, t_cam *cam, double delta);
double				cylinder2(t_rt *rt, t_coord *coord, t_cam *cam);
double				cone2(t_rt *rt, t_coord *coord, t_cam *cam);

/*
** shadow.c
*/
int					shadow_sphere(t_rt *rt, t_rt *shadow);
int					shadow_cone(t_rt *rt, t_rt *shadow);
int					shadow_cylinder(t_rt *rt, t_rt *shadow);

/*
** hook.c
*/
int					hook_event(int key, t_rt *rt);

/*
** shadow2.c
*/
int					shadow_sphere2(t_rt *rt, t_rt *shadow);
int					shadow_cone2(t_rt *rt, t_rt *shadow);
int					shadow_cylinder2(t_rt *rt, t_rt *shadow);

/*
** tracing.c
*/
int					trace_cylinder(t_rt *rt, t_coord *coord);
int					trace_plane(t_rt *rt, t_coord *coord);
int					trace_cone(t_rt *rt, t_coord *coord);
int					trace_sphere(t_rt *rt, t_coord *coord);

/*
** tracing2.c
*/
int					trace_cylinder2(t_rt *rt, t_coord *coord);
int					trace_sphere2(t_rt *rt, t_coord *coord);
int					trace_plane2(t_rt *rt, t_coord *coord);
int					trace_cone2(t_rt *rt, t_coord *coord);

/*
** scenario.c
*/
void				scenario_one(t_rt *rt);
void				scenario_hub(t_rt *rt);

#endif
