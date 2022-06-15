/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:06 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 14:26:24 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "math.h"

# define WIDTH 720
# define HEIGHT 720
# define ITER_MAX 40

typedef struct s_t
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x_min;				//SMALLEST X COORDINATE
	double	y_min;				//SMALLEST Y COORDINATE
	double	zoom;				//SECTOR VIEWED AT
	int		iter;				//ITERATIONS
	char	*set;				//SELECTED SET
	int		x_pix;				//X POSITION OF PIXEL
	int		y_pix;				//Y POSITION OF PIXEL
	int		col[20];			//COLOR ARRAY
	double	c_re;				//RE NUMBERS THAT ARE BEING ITERATED
	double	c_im;				//IM NUMBERS THAT ARE BEING ITERATED
	double	jul_cre;			//CONSTANT REAL FOR JULIA SET
	double	jul_cim;			//CONSTANT IMAGINARY FOR JULIA SET
}			t_t;

/* ESSENTIAL */
void	init_fract(t_t *data, char *str);
void	draw_img(t_t *t);
void	iterate(t_t *t);

/* EVENTS */
int		keys(int keycode, t_t *t);
int		scroll(int keycode, int x, int y, t_t *t);
int		julia_move(int x, int y, t_t *t);

#endif