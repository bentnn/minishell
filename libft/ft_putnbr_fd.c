/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:35:32 by aabet             #+#    #+#             */
/*   Updated: 2020/11/11 21:35:34 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

	temp = n;
	if (n < 0)
	{
		temp *= -1;
		ft_putchar_fd('-', fd);
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((char)(temp % 10 + 48), fd);
}
