/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:34:17 by dkhalfao          #+#    #+#             */
/*   Updated: 2024/11/13 18:34:49 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Count the number of words separated by delimiter `c`
static int	count_words(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

// Free memory allocated for the split array
static void	free_split(char **lst)
{
	int	i;

	i = 0;
	if (!lst)
		return;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

// Fill the split array with words
static void	fill(char const *s, char c, char **lst)
{
	size_t	word_len;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			word_len = ft_strlen(s);
			if (ft_strchr(s, c)) // Find the next occurrence of the delimiter
				word_len = ft_strchr(s, c) - s;
			lst[i] = ft_substr(s, 0, word_len); // Create substring
			if (!lst[i]) // Free memory in case of allocation failure
			{
				free_split(lst);
				return;
			}
			i++;
			s += word_len;
		}
		else
			s++;
	}
	lst[i] = NULL; // Null-terminate the array
}

// Split the string into an array of words separated by `c`
char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
		return (NULL);
	lst = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	fill(s, c, lst);
	return (lst);
}