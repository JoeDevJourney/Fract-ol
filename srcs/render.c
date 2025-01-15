/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:44:13 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/15 05:29:23 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot_calc(t_fractol *fract, double c_r, double c_i)
{
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	z_r = 0.0;
	z_i = 0.0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4.0 && i < fract->iterations)
	{
		tmp = z_r * z_r - z_i * z_i + c_r;
		z_i = 2.0 * z_r * z_i + c_i;
		z_r = tmp;
		i++;
	}
	if (i < fract->iterations)
		return (blend_colors(NEON_BLUE, fract->current_color, (double)i \
			/ fract->iterations));
	else
		return (NEON_BLUE);
}

static void	mandelbrot_set(t_fractol *fract, int x, int y)
{
	double	c_r;
	double	c_i;
	int		rgb;

	c_r = (x - WIDTH / 2.0) * 4.0 / WIDTH * fract->zoom + fract->shift_r;
	c_i = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * fract->zoom + fract->shift_i;
	rgb = mandelbrot_calc(fract, c_r, c_i);
	// printf("mandelbrot calc\n");
	mlx_put_pixel(fract->img, x, y, rgb);
}

static int	julia_calc(t_fractol *fract, double z_r, double z_i)
{
	double	tmp;
	int		i;

	i = 0;
	while (z_r * z_r + z_i * z_i < 4.0 && i < fract->iterations)
	{
		tmp = z_r * z_r - z_i * z_i + fract->julia_r;
		z_i = 2.0 * z_r * z_i + fract->julia_i;
		z_r = tmp;
		i++;
	}
	if (i < fract->iterations)
		return (blend_colors(NEON_BLUE, fract->current_color, (double)i \
			/ fract->iterations));
	else
		return (NEON_BLUE);
}

static void	julia_set(t_fractol *fract, int x, int y)
{
	double	z_r;
	double	z_i;
	int		rgb;

	z_r = (x - WIDTH / 2.0) * 4.0 / WIDTH * fract->zoom + fract->shift_r;
	z_i = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * fract->zoom + fract->shift_i;
	rgb = julia_calc(fract, z_r, z_i);
	// printf("julia calc\n");
	mlx_put_pixel(fract->img, x, y, rgb);
}

void	fractol_render(t_fractol *fract)
{
	int	x;
	int	y;

	// printf("render startet...\n");
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (!ft_strncmp(fract->title, "Mandelbrot", 10))
				mandelbrot_set(fract, x, y);
			else if (!ft_strncmp(fract->title, "Julia", 5))
				julia_set(fract, x, y);
		}
	}
	mlx_image_to_window(fract->mlx_connect, fract->img, 0, 0);
	// printf("render abgeschlossen\n");
}
