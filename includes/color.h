/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:42:45 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 20:49:18 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

# define BLACK 0x000000u
# define RED 0xFF0000u
# define GREEN 0x00FF00u
# define BLUE 0x0000FFu
# define WHITE 0xFFFFFFu
# define BG_COLOR 0xA3C6C0u

typedef struct	s_rgb
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	color;
}				t_rgb;

uint8_t			int_to_char(uint32_t in);
t_rgb			get_black_color(void);
t_rgb			get_red_color(void);
t_rgb			get_green_color(void);
t_rgb			get_blue_color(void);
t_rgb			get_white_color(void);
void			set_color(t_rgb *color, uint8_t r, uint8_t g, uint8_t b);
void			set_rgb_to_int(t_rgb *src);
void			set_int_to_rgb(t_rgb *src);
t_rgb			clr_add_clr(t_rgb one, t_rgb two);
t_rgb			colort_mult_f(t_rgb one, double_t f);
int32_t			colort_int_add_colort_int(int32_t one, int32_t two);
t_rgb			colort_mult_vec(t_rgb one, t_v3d v);
uint8_t			add_8_bit(uint16_t a, uint16_t b);
uint8_t			mult_8_bit(double_t a, double_t f);
uint8_t			inter_8_bit(uint16_t a, uint16_t b);

#endif
