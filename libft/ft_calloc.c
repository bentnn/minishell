/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:56:30 by aabet             #+#    #+#             */
/*   Updated: 2020/11/11 15:56:32 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned int	bites;
	void			*address;

	bites = (unsigned)num * (unsigned)size;
	address = malloc(bites);
	if (address)
		ft_memset(address, 0, bites);
	return (address);
}
