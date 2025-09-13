#include "tiny_shell.h"

static char	*substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > strlen(s) || !len)
		return (strdup(""));
	if (len > strlen(s + start))
		len = strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	while (*str)
	{
		in_word = 0;
		while (*str && *str == c)
			++str;
		while (*str && *str != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
			++str;
		}
	}
	return (count);
}

char	**split_string(char const *s, char c)
{
	const char	*new_s;
	char		**arr;
	int			words_count;
	int			i;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	arr = (char **)malloc((words_count + 1) * (sizeof(char *)));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < words_count)
	{
		while (*s == c)
			s++;
		new_s = s;
		while (*s && *s != c)
			s++;
		arr[i] = substr(new_s, 0, s - new_s);
		if (!arr[i])
			return (free_array(arr), NULL);
	}
	arr[i] = NULL;
	return (arr);
}
