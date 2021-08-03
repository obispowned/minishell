#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t size);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t size);
char	*ft_strdup(char *s1);


#endif
