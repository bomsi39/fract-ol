/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:21:30 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 22:13:00 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_color(t_t *t)
{
	t->col[0] = encode_rgb(0, 204, 65);
	t->col[1] = encode_rgb(25, 197, 73);
	t->col[2] = encode_rgb(51, 191, 82);
	t->col[3] = encode_rgb(76, 185, 91);
	t->col[4] = encode_rgb(102, 179, 99);
	t->col[5] = encode_rgb(127, 173, 108);
	t->col[6] = encode_rgb(153, 167, 117);
	t->col[7] = encode_rgb(178, 161, 125);
	t->col[8] = encode_rgb(204, 155, 134);
	t->col[9] = encode_rgb(229, 149, 143);
	t->col[10] = encode_rgb(255, 143, 152);
	t->col[11] = encode_rgb(249, 145, 126);
	t->col[12] = encode_rgb(244, 163, 109);
	t->col[13] = encode_rgb(239, 187, 94);
	t->col[14] = encode_rgb(234, 215, 78);
	t->col[15] = encode_rgb(209, 229, 64);
	t->col[16] = encode_rgb(161, 224, 50);
	t->col[17] = encode_rgb(110, 219, 36);
	t->col[18] = encode_rgb(54, 214, 24);
	t->col[19] = encode_rgb(11, 209, 27);
}

void	init_fract(t_t *data, char *str)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x_min = -2;
	data->y_min = -2;
	data->zoom = 4;
	data->set = str;
	data->stop = 0;
	init_color(data);
}
