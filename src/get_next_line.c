/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:58:38 by fayfang           #+#    #+#             */
/*   Updated: 2025/12/15 10:03:57 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	line = get_buffer(fd, line, buffer);
	if (!line)
		return (NULL);
	temp = ft_strchr(buffer, '\0');
	if (ft_strchr(buffer, '\n'))
		temp = ft_strchr(buffer, '\n') + 1;
	while (temp[i])
	{
		buffer[i] = temp[i];
		i++;
	}
	buffer[i] = '\0';
	return (line);
}

char	*get_buffer(int fd, char *line, char *buffer)
{
	ssize_t	n;

	n = 1;
	if (buffer[0])
		line = join_line(line, buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 1)
			break ;
		buffer[n] = '\0';
		line = join_line(line, buffer);
	}
	if ((n == 0 && !buffer[0]) || n < 0)
		return (free(line), NULL);
	return (line);
}

char	*join_line(char *line, char *buffer)
{
	size_t	len;
	char	*new;

	new = ft_strchr(buffer, '\n');
	if (new)
		len = new - buffer + 1;
	else
		len = ft_strlen(buffer);
	line = ft_strnjoin(line, buffer, len);
	return (line);
}
