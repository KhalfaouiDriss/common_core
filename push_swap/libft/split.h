#ifndef FT_SPLIT
# define FT_SPLIT

# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);

#endif