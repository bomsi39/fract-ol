/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:55:06 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 22:50:31 by dfranke          ###   ########.fr       */
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
		mlx_hook(t.win, 17, 0, destroy, &t);
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

/* In this Project fractals should be created. A fractal is a representation
of a mathematical sequence, it shows geometrical shapes even in arbitrary 
small scales. The representation takes place in tha coordinate system of the
Real and Imaginary Numbers.

 In this project we used the minilibx for the first time. It is a c library 
 used for rendering graphics it is built on top of the X Window system API.
 X-Window is a network-oriented graphical system for unix. 
 
 init_mlx
 creates the structure to use the minilibx

 
 In minilibx it makes sense to push the pixels first to an image and afterwards 
 the image to the window. The reason for this is that the integrated 
 mlx_put_pixel function works slow ad tries to push every pixel directly to 
 the window instead to wait for the image completely rendered and put it then 
 all at once.

 mlx_get_data_addr
 gives us the adress of the image so that we are able to change the pixels of it directly

 */