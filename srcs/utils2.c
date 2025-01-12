/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:40:47 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/12 17:37:29 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	malloc_error(void)
{
	perror("MALLOC ERROR: ");
	exit(EXIT_FAILURE);
}

void	zoom_in(t_fractol *fract, double mouse_r, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 0.95;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoom_factor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}

void	zoom_out(t_fractol *fract, double mouse_r, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 1.01;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoom_factor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}
