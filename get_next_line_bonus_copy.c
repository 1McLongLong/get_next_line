#include "get_next_line_bonus.h"

char	*extract_line(char *reiner, char *line)
{
	int	i;

	i = 0;
	if (reiner[0] == '\0')
		return (NULL);
	if (ft_strchr(reiner, '\n') == NULL)
	{
		line = ft_substr(reiner, 0, ft_strlen(reiner));
	}
	else
	{
		while (reiner[i] && reiner[i] != '\n')
			i++;
		line = ft_substr(reiner, 0, i + 1);
	}
	return (line);
}

char	*rest_of_line(char *reiner)
{
	char	*new_reiner;
	int		i;

	i = 0;
	while (reiner[i] && reiner[i] != '\n')
		i++;
	new_reiner = ft_substr(reiner, i + 1, ft_strlen(reiner) - i);
	free(reiner);
	return (new_reiner);
}

char	*read_line(int fd, char *reiner, char *buffer)
{
	char	*temp;
	int		i;

	i = 1;
	if (!reiner)
		reiner = ft_strdup("");
	while (i > 0 && !ft_strchr(reiner, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(reiner), reiner = NULL, NULL);
		buffer[i] = '\0';
		temp = reiner;
		reiner = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (free(buffer), buffer = NULL, reiner);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*reiner[MAX_FD];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(reiner[fd]), reiner[fd] = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if (reiner[fd])
			free(reiner[fd]); 
		return (reiner[fd] = NULL, NULL);
	}
	reiner[fd] = read_line(fd, reiner[fd], buffer);
	buffer = NULL;
	if (!reiner[fd])
		return (NULL);
	line = extract_line(reiner[fd], line);
	if (!line)
		return (free(reiner[fd]), reiner[fd] = NULL, NULL);
	reiner[fd] = rest_of_line(reiner[fd]);
	return (line);
}
