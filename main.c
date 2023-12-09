/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:56:59 by almarico          #+#    #+#             */
/*   Updated: 2023/12/09 16:05:27 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	n;

	n = printf("%20.5d", -1024);
	printf(":%d\n", n);
	n = ft_printf("%20.5d", -1024);
	printf(":%d\n", n);
	return (0);
}
