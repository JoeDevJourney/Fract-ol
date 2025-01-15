/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:47:09 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/15 06:02:30 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	close_window(void *param)
{
	clean_exit(param);
}

void	clean_exit(void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (fract->img)
		mlx_delete_image(fract->mlx_connect, fract->img);
	if (fract->mlx_connect)
		mlx_terminate(fract->mlx_connect);
	exit(0);
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fract->mlx_connect);
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == \
		MLX_KEY_A)
		fract->shift_r -= (0.01 * fract->zoom);
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == \
		MLX_KEY_D)
		fract->shift_r += (0.01 * fract->zoom);
	else if (keydata.key == MLX_KEY_UP || keydata.key == \
		MLX_KEY_W)
		fract->shift_i -= (0.01 * fract->zoom);
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == \
		MLX_KEY_S)
		fract->shift_i += (0.01 * fract->zoom);
	fractol_render(fract);
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fract;
	double		mouse_r;
	double		mouse_i;
	int			x;
	int			y;

	(void)xdelta;
	fract = (t_fractol *)param;
	mlx_get_mouse_pos(fract->mlx_connect, &x, &y);
	mouse_r = (x - WIDTH / 2) / (0.01 * WIDTH * fract->zoom) * fract->shift_r;
	mouse_i = (y - HEIGHT / 2) / (0.01 * HEIGHT * fract->zoom) * \
		fract->shift_i;
	if (ydelta > 0)
		zoom_in(fract, mouse_r, mouse_i);
	else if (ydelta < 0)
		zoom_out(fract, mouse_r, mouse_i);
	fractol_render(fract);
}
