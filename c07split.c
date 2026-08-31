/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momellou <momellou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 13:13:24 by momellou          #+#    #+#             */
/*   Updated: 2026/08/31 11:28:08 by momellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_separator(str[i], charset))
			i++;
	}
	return (count);
}

char	*get_word(char *str, char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] && is_separator(str[j], charset))
			j++;
		if (str[j])
		{
			tab[i] = get_word(&str[j], charset);
			if (!tab[i])
				return (NULL);
			i++;
			while (str[j] && !is_separator(str[j], charset))
				j++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("Bonjour comment, allez vous", " ");
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("[%s]\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
