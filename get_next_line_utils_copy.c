/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:20:43 by touahman          #+#    #+#             */
/*   Updated: 2023/11/16 12:20:45 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_copy.h"

size_t	ft_strlen(const char *s)
{
  size_t	i;

  if (!s)
    return (0);
  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

char	*ft_strdup(const char *s1)
{
  int		i;
  int		size;
  char	*copy;

  size = ft_strlen(s1);
  copy = malloc(sizeof(char) * size + 1);
  if (copy == 0)
    return (NULL);
  i = 0;
  while (s1[i])
  {
    copy[i] = s1[i];
    i++;
  }
  copy[i] = '\0';
  return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
  char	*str;
  size_t	t_len;
  int i;
  int j;
  if (!s1 && !s2)
    return (NULL);
  if (!s1)
    return (s2);
  if (!s2)
    return (s1);
  t_len = ft_strlen(s1) + ft_strlen(s2) + 1;
  str = (char *)malloc(t_len * sizeof(char));
  if (!str)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i] != '\0')
    str[i++] = s1[j++];
  j = 0;
  while (s2[j] != '\0')
    str[i++] = s2[j++];
  str[i] = '\0';
  return (str);
}

char	*ft_strchr(const char *s, int c)
{
  int	i;

  i = 0;
  while (s[i] != '\0')
  {
    if (s[i] == (unsigned char)c)
      return ((char *)(&s[i]));
    i++;
  }
  if (s[i] == (unsigned char)c)
    return ((char *)(&s[i]));
  return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
  size_t  i;
  char	*str;

  if (s == NULL)
    return (NULL);
  if (ft_strlen(s) < start)
  {
    str = malloc(1);
    if (!str)
      return (NULL);
    str [0] = '\0';
    return (str);
  }
  if (ft_strlen(s) - start < len)
    str = malloc((ft_strlen(s) - start) + 1);
  else
    str = malloc(len + 1);
  if (!str)
    return (NULL);
  i = -1;
  while (++i < len && s[start + i])
    str[i] = s[start + i];
  str[i] = '\0';  
  return (str);
}
