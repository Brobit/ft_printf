/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:42:07 by almarico          #+#    #+#             */
/*   Updated: 2023/12/06 16:14:04 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stddef.h>

static void	ft_wmid_str(char *str, size_t *char_c, t_flag *flag, t_width *len)
{
	ssize_t	size;

	size = 0;
	if (flag->precision == 0)
	{
		*char_c += write(1, str, ft_strlen(str));
		*char_c += ft_write_space(len->width, ft_strlen(str));
	}
	if (flag->precision == 1)
	{
		size = len->precision;
		while (len->precision-- > 0 && *str)
			*char_c += write(1, str++, 1);
		if (len->width > size)
			*char_c += ft_write_space(len->width, size);
	}
}

static void	ft_wnormalstr(char *str, size_t *char_c, t_flag *flag, t_width *len)
{
	if (flag->precision == 1 && len->precision > 0)
	{
		if (len->width > len->precision)
			*char_c += ft_write_space(len->width, len->precision);
		while (len->precision-- > 0 && *str)
			*char_c += write(1, str++, 1);
	}
	if (flag->precision == 0)
	{
		*char_c += ft_write_space(len->width, ft_strlen(str));
		*char_c += write(1, str, ft_strlen(str));
	}
}

static void	ft_write_nstr(size_t *char_c, t_flag *flag, t_width *len)
{
	if (flag->precision == 0)
	{
		if (flag->middlescore == 1)
		{
			*char_c += write(1, "(null)", 6);
			*char_c += ft_write_space(len->width, 6);
		}
		else
		{
			*char_c += ft_write_space(len->width, 6);
			*char_c += write(1, "(null)", 6);
		}
	}
	if (flag->precision == 1)
	{
		if (flag->middlescore == 1)
		{
			if (len->precision >= 6)
				*char_c += write(1, "(null)", 6);
			if (len->width > 6)
				*char_c += ft_write_space(len->width, len->precision);
		}
		else
		{
			if (len->width > 6)
				*char_c += ft_write_space(len->width, len->precision);
			if (len->precision >= 6)
				*char_c += write(1, "(null)", 6);
		}
	}
}

void	ft_write_str(char *str, size_t *char_c, t_flag *flag, t_width *length)
{
	if ((size_t)length->precision > ft_strlen(str) && str)
		length->precision = ft_strlen(str);
	else if (!str && length->precision > 6)
		length->precision = 6;
	if (str == NULL)
		ft_write_nstr(char_c, flag, length);
	else
	{
		if (flag->middlescore == 1)
			ft_wmid_str(str, char_c, flag, length);
		else
			ft_wnormalstr(str, char_c, flag, length);
	}
}
