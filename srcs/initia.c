/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:41:47 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/13 19:03:51 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	events_initia(t_fractol *fract)
{
	mlx_key_hook(fract->mlx_connect, handle_key, &fract);
	mlx_key_hook(fract->mlx_connect, handle_mouse, &fract);
	mlx_key_hook(fract->mlx_connect, clean_exit, &fract);
}

static void	data_init(t_fractol *fract)
{
	fract->hypotenuse = 4;
	fract->iterations = 100;
	fract->shift_r = 0.0;
	fract->shift_i = 0.0;
	fract->zoom = 1.0;
}

static void	create_window(t_fractol *fract)
{
	fract->mlx_connect = mlx_init(WIDTH, HEIGHT, fract->title, true);
	if (!fract->window)
	{
		mlx_close_window(fract ->mlx_connect);
		free(fract->mlx_connect);
		malloc_error();
	}
}

static void	create_image(t_fractol *fract)
{
	fract->img = mlx_new_image(fract->mlx_connect, WIDTH, HEIGHT);
	if (!fract->img)
	{
		mlx_terminate(fract->mlx_connect);
		free(fract->mlx_connect);
		malloc_error();
	}
	fract->img_addr = mlx_new_image(fract->mlx_connect, WIDTH, HEIGHT);
}

void	fractol_init(t_fractol *fract)
{
	fract->mlx_connect = mlx_init(WIDTH, HEIGHT, fract->title, true);
	if (!fract->mlx_connect)
		malloc_error();
	create_window(fract);
	create_image(fract);
	events_initia(fract);
	data_init(fract);
	fract->current_color = BRIGHT_CYAN;
}
