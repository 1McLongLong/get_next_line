# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str); 
int		ft_clean(char *str);

# endif 
