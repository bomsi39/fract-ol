/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frctls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:15:25 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 16:46:10 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juli(t_t *t)
{
	double	re;
	double	im;
	double	re_temp;

	re = t->c_re;
	im = t->c_im;
	t->iter = 0;
	while (t->iter < ITER_MAX && pow(re, 2) + pow(im, 2) <= 4)
	{
		re_temp = pow(re, 2) - pow(im, 2) + t->jul_cre;
		im = 2 * re * im + t->jul_cim;
		re = re_temp;
		t->iter++;
	}
}

/* Julia Set Z = Z^2 + C --> C = Position of the Cursor, Z = Position of Pixel
*/

void	mandi(t_t *t)
{
	double	re;
	double	im;
	double	re_temp;

	re = 0;
	im = 0;
	t->iter = 0;
	while (t->iter < ITER_MAX && pow(re, 2) + pow(im, 2) <= 4)
	{
		re_temp = pow(re, 2) - pow(im, 2) + t->c_re;
		im = 2 * re * im + t->c_im;
		re = re_temp;
		t->iter++;
	}
}

/* Mandelbrot Set Z = Z^2 + C --> C = Position of Pixel, Z = 0
*/

void	iterate(t_t *t)
{
	if (!ft_strcmp(t->set, "Mandelbrot"))
		mandi(t);
	else
		juli(t);
}
