/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:31:21 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/12 16:08:10 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_aux_hex(unsigned long long num, char *base);

int	ft_write_p(void *pointer)
{
	int					count;
	unsigned long long	temp;

	count = 3;
	temp = (unsigned long long)pointer;
	write(1, "0x", 2);
	if (temp == 0)
		write(1, "0", 1);
	else
		count += ft_aux_hex(temp, "0123456789abcdef");
	return (count);
}

static int	ft_aux_hex(unsigned long long num, char *base)
{
	int	count;

	count = 0;	
	if (num >= 16)
	{
		count += ft_aux_hex(num / 16, "0123456789abcdef");
		write(1, &base[num % 16], 1);
		count++;
	}
	if (num < 16)
		write(1, &base[num % 16], 1);
	return (count);
}
