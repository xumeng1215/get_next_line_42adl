/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie|mexu <charlie_xumeng@hotmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:16:51 by charlie|mexu      #+#    #+#             */
/*   Updated: 2024/04/15 11:43:55 by charlie||        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// find the '\n' in a str
// -1 means not found or str is NULL
int	ft_find_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// read from fd and add to the end of str
// until str got another new line mark or to the end of file
// BUFFER_SIZE limited
char	*ft_read_line(int fd, char *str)
{
	int		i;
	char	*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = -1;
	while (ft_find_line(str) == -1 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		str = ft_alloc_extra(str, i);
		if (!str)
			return (NULL);
		ft_strcat(str, buff);
	}
	free(buff);
	return (str);
}

// main part
char	*get_next_line(int fd)
{
	static char		*str = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_read_line(fd, str);
	line = ft_copy_str(str);
	str = ft_trim(str);
	if (!line || !str)
		return (NULL);
	if (*line == '\0')
	{
		free(str);
		free(line);
		str = NULL;
		return (NULL);
	}
	return (line);
}

// test main function
int	main(void)
{
	int i;
	int fd;

	fd = open("1.txt", O_RDONLY);
	printf("fd is %d\n", fd);
	for(i = 0; i < 5; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return 0;
}
