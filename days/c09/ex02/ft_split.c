/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:47:42 by yoelansa          #+#    #+#             */
/*   Updated: 2022/08/10 16:09:35 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strs_size(char *str, char *sep)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		while (str[i] && ft_separator(str[i], sep))
			i++;
		if (str[i])
			s++;
		while (str[i] && !ft_separator(str[i], sep))
			i++;
	}
	return (s);
}

int	ft_strlen(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_separator(str[i], sep))
		i++;
	return (i);
}

char	*ft_strdup(char *str, char *sep)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = ft_strlen(str, sep);
	string = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char *str, char *charset)
{
	char	**string;
	int		i;
	int		size;

	i = 0;
	size = ft_strs_size(str, charset);
	string = malloc(sizeof(char *) * (size + 1));
	while (*str)
	{
		while (*str && ft_separator(*str, charset))
			str++;
		if (*str)
		{
			string[i] = ft_strdup(str, charset);
			i++;
		}
		while (*str && !ft_separator(*str, charset))
			str++;
	}
	string[i] = 0;
	return (string);
}
