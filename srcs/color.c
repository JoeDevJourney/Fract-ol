/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:04:52 by jbrandt           #+#    #+#             */
/*   Updated: 2025/01/13 14:40:27 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	blend_colors(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t * \
			((color2 >> 16) & 0xFF) * 5);
	g = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t * \
			((color2 >> 8) & 0xFF) * 5);
	b = (int)((1 - t) * (color1 & 0xFF) + t * \
			(color2 & 0xFF) * 5);
	r = (int)(r + (255 - r) * t * 1.5);
	g = (int)(g + (255 - g) * t * 0,2);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

void	color_shift(t_fractol *fract)
{
	static int	colors[] = {NEON_PINK, ELECTRIC_BLUE, LIME_GREEN,
		VIVID_PURPLE, BURNT_ORANGE, NEON_YELLOW, TURQUOISE,
		HOT_MAGENTA, IRIDESCENT_TEAL, PSYCHEDELIC_RED,
		ELECTRIC_LIME, NEON_BLUE, BRIGHT_CYAN,
		FLUORESCENT_GREEN, HOT_ORANGE, BLAZING_PURPLE};
	static int	color_index;

	color_index = (color_index + 1) % (sizeof(colors) / sizeof(colors[0]));
	fract->current_color = colors[color_index];
	fractol_render(fract);
}
