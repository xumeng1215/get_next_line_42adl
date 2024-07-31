/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie|| <charlie_xumeng@hotmail.co>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:23:45 by charlie||         #+#    #+#             */
/*   Updated: 2024/04/15 12:23:46 by charlie||        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// add n byte of memory to the end of str
// create another area of memory, which is n bytes larger
// then copy the original str to the new area
char	*ft_alloc_extra(char *str, int nb)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	temp = (char *)malloc(len + nb + 1);
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

// copy the begining from the str to the first new line mark
char	*ft_copy_str(char *str)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	temp = (char *)malloc(len + 1);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

// save the str from first new line mark to the end of str
// return new str, free old str
char	*ft_trim(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i + j])
		j++;
	new_str = (char *)malloc(j + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		new_str[j] = str[i + j];
		j++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

// add buff to the end of str
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
