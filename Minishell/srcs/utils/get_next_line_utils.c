#include	"../../headers/minishell.h"

char	*ft_strchr(char *s, char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	int				count;
	char			*s;

	i = 0;
	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = malloc(sizeof(char) * count);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	total;
	unsigned int	lenglo;

	lenglo = ft_strlen(s);
	if (start > lenglo)
		return (ft_strdup(""));
	i = 0;
	total = start + len;
	if (len < (lenglo - start))
		dest = (char *)malloc(sizeof(char) * (len + 1));
	else
		dest = (char *)malloc(sizeof(char) * (lenglo - start + 1));
	if (!dest)
		return (NULL);
	while (start < total)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
