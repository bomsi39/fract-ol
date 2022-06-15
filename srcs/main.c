/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:55:06 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 14:30:13 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_t	t;

	if (argc == 2 && (!ft_strcmp(argv[1], "Mandelbrot")
			|| !ft_strcmp(argv[1], "Julia")))
	{
		init_fract(&t, argv[1]);
		draw_img(&t);
		mlx_put_image_to_window(t.mlx, t.win, t.img, 0, 0);
		mlx_hook(t.win, 2, 1, keys, &t);
		if (!ft_strcmp(argv[1], "Julia"))
			mlx_hook(t.win, 6, 0, julia_move, &t);
		mlx_mouse_hook(t.win, &scroll, &t);
		mlx_loop(t.mlx);
	}
	else
	{
		ft_putendl_fd("fractol needs the prefered fractal set as an \
argument", 1);
		ft_putendl_fd("possible arguments are Mandelbrot or Julia", 1);
	}
}
