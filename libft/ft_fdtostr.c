/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:16:55 by mlu               #+#    #+#             */
/*   Updated: 2017/04/11 18:15:48 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUF_SIZE 500000

char	*ft_fdtostr(int fd)
{
	char			*temp;
	char			*output;
	char			input[BUF_SIZE + 1];
	unsigned int	memory;

	memory = 0;
	temp = (char*)malloc(sizeof(*output) * (memory + 1));
	output = (char*)malloc(sizeof(*output) * (memory + 1));
	while ((read(fd, input, BUF_SIZE)) > 0)
	{
		memory += BUF_SIZE;
		ft_strcpy(temp, output);
		free(output);
		output = (char*)malloc(sizeof(*output) * (memory + 1));
		ft_strcpy(output, temp);
		ft_strmcat(output, input, &memory, BUF_SIZE);
		output[memory] = '\0';
		free(temp);
		temp = (char*)malloc(sizeof(*temp) * (memory + 1));
	}
	free(temp);
	return (output);
}
