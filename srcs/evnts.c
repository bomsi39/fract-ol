/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evnts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:43 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 14:31:50 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys(int keycode, t_t *t)
{
	if (keycode == 53)
	{
		mlx_destroy_image(t->mlx, t->img);
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	if (keycode == 123)
		t->x_min -= (0.25) * t->zoom;
	else if (keycode == 124)
		t->x_min += (0.25) * t->zoom;
	else if (keycode == 125)
		t->y_min += (0.25) * t->zoom;
	else if (keycode == 126)
		t->y_min -= (0.25) * t->zoom;
	draw_img(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	return (0);
}

int	scroll(int keycode, int x, int y, t_t *t)
{
	double	x_coord;
	double	y_coord;

	x_coord = t->zoom * (double)x / WIDTH + t->x_min;
	y_coord = t->zoom * (double)y / HEIGHT + t->y_min;
	t->x_min = x_coord - (t->zoom / 2);
	t->y_min = y_coord - (t->zoom / 2);
	if (keycode == 4)
		t->zoom *= 0.65;
	else if (keycode == 5)
		t->zoom /= 0.65;
	draw_img(t);
	return (0);
}

int	julia_move(int x, int y, t_t *t)
{
	t->jul_cre = t->zoom * (double)x / WIDTH + t->x_min;
	t->jul_cim = t->zoom * (double)y / HEIGHT + t->y_min;
	draw_img(t);
	return (0);
}
