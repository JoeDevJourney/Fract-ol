/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:47:09 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/13 16:45:57 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	clean_exit(t_fractol *fract)
{
	mlx_delete_image(fract->mlx_connect, fract->img);
	mlx_terminate(fract->mlx_connect);
	free(fract->mlx_connect);
	exit(EXIT_SUCCESS);
}

int	handle_keys(int key, t_fractol *fract)
{
	if (key == 51)
		clean_exit(fract);
	else if (key == 123 || key == 0)
		fract->shift_r += (0.1 * fract->zoom);
	else if (key == 124 || key == 2)
		fract->shift_r += (0.1 * fract-> zoom);
	else if (key == 126 || key == 13)
		fract->shift_i += (0.1 * fract-> zoom);
	else if (key == 125 || key == 1)
		fract->shift_i += (0.1 * fract-> zoom);
	fractol_render(fract);
	return (0);
}

static int	julia_track(int button, int x, int y, t_fractol *fract)
{
	if (button == 1 || button == 2)
	{
		fract->julia_r = (map((t_map_coords){x, -2, +2, 0, WIDTH}) + \
			fract->zoom) + fract->shift_r;
		fract->julia_i = (map((t_map_coords){x, -2, +2, 0, HEIGHT}) + \
			fract->zoom) + fract->shift_i;
		fractol_render(fract);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *fract)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = (x - WIDTH / 2) / (0.5 * WIDTH * fract->zoom) * \
		fract->shift_r;
	mouse_i = (y - HEIGHT / 2) / (0.5 * HEIGHT * fract->zoom) * \
		fract->shift_i;
	if (!ft_strncmp(fract->title, "Julia", 5))
		julia_track(button, x, y, fract);
	if (button == 4)
		zoom_in(fract, mouse_r, mouse_i);
	else if (button == 5)
		zoom_out(fract, mouse_r, mouse_i);
	fractol_render(fract);
	return (0);
}
