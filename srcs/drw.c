/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:17:27 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 14:31:26 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_t *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x
			*(data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	set_color(t_t *t)
{
	if (t->iter < ITER_MAX)
		pixel_put(t, t->x_pix, t->y_pix, t->col[t->iter % 20]);
	else
		pixel_put(t, t->x_pix, t->y_pix, 0x000000);
}

void	draw_img(t_t *t)
{
	double	ax;
	double	ay;

	ax = t->zoom / WIDTH;
	ay = t->zoom / HEIGHT;
	t->c_im = t->y_min;
	t->y_pix = 0;
	while (t->y_pix < HEIGHT)
	{
		t->x_pix = 0;
		t->c_re = t->x_min;
		while (t->x_pix < WIDTH)
		{
			iterate(t);
			set_color(t);
			t->x_pix++;
			t->c_re += ax;
		}
		t->c_im += ay;
		t->y_pix++;
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}
