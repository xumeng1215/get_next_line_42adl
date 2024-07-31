/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie|| <charlie_xumeng@hotmail.co>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:23:18 by charlie||         #+#    #+#             */
/*   Updated: 2024/04/15 12:23:19 by charlie||        ###   ########.fr       */
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
	static char		*str[10];
	char			*line;

	line = NULL;
	if (read(fd, 0, 0) == -1 || fd < 0)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_read_line(fd, str[fd]);
	line = ft_copy_str(str[fd]);
	str[fd] = ft_trim(str[fd]);
	if (!line || !(str[fd]))
		return (NULL);
	if (*line == '\0')
	{
		free(str[fd]);
		free(line);
		str[fd] = NULL;
		return (NULL);
	}
	return (line);
}

/*
// test main function
int	main(void)
{
	int i;
	int fd1, fd2;

	fd1 = open("text", O_RDONLY);
	fd2 = open("text2", O_RDONLY);

    printf ("fd1: %d\nfd2: %d\n", fd1, fd2);
 	for(i = 0; i < 5; i++)
	{
		printf("%s", get_next_line(fd1));
        printf("%s", get_next_line(fd2));

	}
	close(fd1);
	close(fd2);
	return 0;
}
*/
