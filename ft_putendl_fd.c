/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:52 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/16 21:36:16 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void
	ft_putendl_fd(char *s, int fd)
{
	char	new_line;

	if (s == NULL)
		return ;
	new_line = '\n';
	while (*s != '\0')
		write(fd, &*s++, 1);
	write(fd, &new_line, 1);
}
