/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:16:18 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/15 04:03:42 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 1000
# define WIDTH 1000

# define NEON_PINK 			0xFF6EC7
# define ELECTRIC_BLUE		0x7DF9FF
# define LIME_GREEN 		0x32CD32
# define VIVID_PURPLE 		0x9D00FF
# define BURNT_ORANGE 		0xCC5500
# define NEON_YELLOW 		0xFFFF33
# define TURQUOISE 			0x30D5C8
# define HOT_MAGENTA 		0xFF1DCE
# define IRIDESCENT_TEAL 	0x00FFCC
# define PSYCHEDELIC_RED 	0xFF496C
# define ELECTRIC_LIME 		0xCCFF00
# define NEON_BLUE 			0x1B03A3
# define BRIGHT_CYAN 		0x00FFFF
# define FLUORESCENT_GREEN 	0x00FF00
# define HOT_ORANGE 		0xFF4500
# define BLAZING_PURPLE 	0x9900FF

typedef struct s_fractol
{
	void			*mlx;
	const char		*title;
	mlx_t			*mlx_connect;
	void			*window;
	mlx_image_t		*img;
	char			*img_addr;
	int				img_bpp;
	int				img_line;
	int				img_endian;
	char			*img_buffer;
	double			cmplx_r;
	double			cmplx_i;
	double			hypotenuse;
	int				iterations;
	double			shift_r;
	double			shift_i;
	double			zoom;
	int				current_color;
	double			julia_r;
	double			julia_i;
}	t_fractol;

typedef struct s_map_coords
{
	double		unscaled_num;
	double		new_min;
	double		new_max;
	double		old_min;
	double		old_max;
}	t_map_coords;

int				main(int argc, char **argv);
double			map(t_map_coords coords);
t_fractol		square_complex(t_fractol z);
t_fractol		sum_complex(t_fractol z1, t_fractol z2);
double			atod(char *s);
void			malloc_error(void);
void			zoom_in(t_fractol *fract, double mouse_r, double mouse_i);
void			zoom_out(t_fractol *fract, double mouse_r, double mouse_i);
int				blend_colors(int color1, int color2, double t);
void			color_shift(t_fractol *fract);
void			handle_keys(mlx_key_data_t keydata, void *param);
void			handle_scroll(double xdelta, double ydelta, void *param);
void			close_window(void *param);
void			clean_exit(void *param);
void			fractol_init(t_fractol *fract);
void			fractol_render(t_fractol *fract);
#endif