/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:38:51 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/23 13:05:55 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_spec_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_join_str(char *s1, char *s2)
{
	char	*comb;
	int		i;
	size_t	j;
	size_t	new_lgth;

	if (!s2)
		return (NULL);
	new_lgth = ft_spec_strlen(s1);
	new_lgth += ft_strlen(s2);
	comb = (char *)malloc(new_lgth + 1);
	if (!comb)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		comb[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
		comb[i + j] = s2[j];
	comb[i + j] = '\0';
	free (s1);
	return (comb);
}

char	*ft_read(int fd)
{
	char	*buffer;
	char	*str;
	int		read_bytes;

	buffer = malloc(sizeof(char) * 2);
	str = malloc(sizeof(char));
	str[0] = '\0';
	if (!buffer || fd < 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, 1);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_join_str(str, buffer);
	}
	free (buffer);
	return (str);
}
