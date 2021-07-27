/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:57 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/16 21:41:07 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int
	ft_get_digit_count(long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits++;
	if (n < 0)
	{
		n *= -1;
		digits++;
	}
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static long
	ft_pow(int base, int exponent)
{
	long	pow;

	pow = 1;
	while (exponent > 0)
	{
		pow *= (long)base;
		exponent--;
	}
	return (pow);
}

void
	ft_putnbr_fd(int n, int fd)
{
	char	num;
	long	copy_n;
	long	div;
	int		digits;

	if (n < 0)
		write(fd, "-", 1);
	if (n == -2147483648)
		copy_n = 2147483648;
	else if (n < 0)
	{
		n *= -1;
		copy_n = (long)n;
	}
	else
		copy_n = (long)n;
	digits = ft_get_digit_count(copy_n);
	while (digits > 0)
	{
		div = ft_pow(10, digits - 1);
		num = (copy_n / div) + '0';
		write(fd, &num, 1);
		copy_n %= div;
		digits--;
	}
}
