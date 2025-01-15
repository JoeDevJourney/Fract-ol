/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:44:13 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/15 03:44:34 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	fractol_set(t_fractol *z, t_fractol *c, t_fractol *fract)
{
	if (!ft_strncmp(fract->title, "Julia", 5))
	{
		c->cmplx_r = fract->julia_r;
		c->cmplx_i = fract->julia_i;
	}
	else
	{
		c->cmplx_r = z->cmplx_r;
		c->cmplx_i = z->cmplx_i;
	}
}

static void	get_complex_map(int x, int y, t_fractol *fract)
{
	t_fractol	z;
	t_fractol	c;
	int			i;
	int			rgb;

	i = 0;
	z.cmplx_r = (map((t_map_coords){x, -2, +2, 0, WIDTH}) * fract->zoom) + \
		fract->shift_r;
	c.cmplx_i = (map((t_map_coords){y, +2, -2, 0, HEIGHT}) * fract->zoom) + \
		fract->shift_i;
	fractol_set(&z, &c, fract);
	while (i < fract->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.cmplx_r * z.cmplx_r) + (z.cmplx_i * z.cmplx_i) > \
			fract->hypotenuse)
		{
			rgb = blend_colors(NEON_BLUE, fract->current_color,
					(double)i / fract->iterations);
			mlx_put_pixel(fract->img, x, y, rgb);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fract->img, x, y, NEON_BLUE);
}

void	fractol_render(t_fractol *fract)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			get_complex_map(x, y, fract);
	}
	mlx_image_to_window(fract->mlx_connect, fract->img, 0, 0);
}
