/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:41:47 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/12 18:13:59 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	create_windows(t_fractol *fract)
{
	fract->window = mlx_init(WIDTH, HEIGHT, fract->title, fract->mlx_connect);
	if (!fract->window)
	{
		mlx_close_window(fract ->mlx_connect);
		free(fract->mlx_connect);
		malloc_error();
	}
}
