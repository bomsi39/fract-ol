/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frctls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:15:25 by dfranke           #+#    #+#             */
/*   Updated: 2022/06/15 14:32:02 by dfranke          ###   ########.fr       */
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

void	iterate(t_t *t)
{
	if (!ft_strcmp(t->set, "Mandelbrot"))
		mandi(t);
	else
		juli(t);
}
