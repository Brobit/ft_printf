/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:27:22 by almarico          #+#    #+#             */
/*   Updated: 2023/12/06 13:20:02 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static size_t	ft_write_middlescore_integer(long int integer, t_width *length)
{
	size_t			char_counter;

	char_counter = 0;
	if (integer < 0)
	{
		char_counter += write(1, "-", 1);
		integer *= -1;
		length->precision++;
	}
	char_counter += ft_write_zero(length->precision, 0);
	char_counter += ft_size(integer);
	ft_putnbr_base(integer, TABLEAU_DEC);
	char_counter += ft_write_space(length->width, 0);
	return (char_counter);
}

static size_t	ft_write_zero_integer(long int integer, t_width *length)
{
	size_t			char_counter;

	char_counter = 0;
	if (integer < 0)
	{
		char_counter += write(1, "-", 1);
		integer *= -1;
	}
	char_counter += ft_write_zero(length->width, 0);
	char_counter += ft_size(integer);
	ft_putnbr_base(integer, TABLEAU_DEC);
	return (char_counter);
}

static size_t	ft_write_normal_integer(long int integer, t_width *length)
{
	size_t			char_counter;

	char_counter = 0;
	char_counter += ft_write_space(length->width, 0);
	if (integer < 0)
	{
		char_counter += write(1, "-", 1);
		integer *= -1;
		length->precision++;
	}
	char_counter += ft_write_zero(length->precision, 0);
	char_counter += ft_size(integer);
	ft_putnbr_base(integer, TABLEAU_DEC);
	return (char_counter);
}

void	ft_w_integer(int integer, size_t *char_c, t_width *len, t_flag *flag)
{
	len->width -= (len->precision + ft_size(integer));
	len->precision -= ft_size(integer);
	if (flag->space == 1 && integer >= 0)
	{
		*char_c += write(1, " ", 1);
		len->width--;
		len->precision--;
	}
	if (flag->plus == 1 && integer >= 0)
	{
		*char_c += write(1, "+", 1);
		len->width--;
		len->precision--;
	}
	if (flag->middlescore == 1)
		*char_c += ft_write_middlescore_integer(integer, len);
	else if (flag->zero == 1)
		*char_c += ft_write_zero_integer(integer, len);
	else
		*char_c += ft_write_normal_integer(integer, len);
}

void	ft_w_uint(unsigned int integer, size_t *cc, t_width *len, t_flag *f)
{
	len->width -= (len->precision + ft_size(integer));
	len->precision -= ft_size(integer);
	if (f->space == 1)
	{
		*cc += write(1, " ", 1);
		len->width--;
		len->precision--;
	}
	if (f->plus == 1)
	{
		*cc += write(1, "+", 1);
		len->width--;
		len->precision--;
	}
	if (f->middlescore == 1)
		*cc += ft_write_middlescore_integer(integer, len);
	else if (f->zero == 1)
		*cc += ft_write_zero_integer(integer, len);
	else
		*cc += ft_write_normal_integer(integer, len);
}
