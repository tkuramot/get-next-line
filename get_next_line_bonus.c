/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:05:52 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/26 17:33:09y tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			flag;
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	*line = '\0';
	flag = 0;
	if (rest[fd])
		flag = concat_line(&line, rest[fd], &rest[fd]);
	if (flag)
		return (line);
	return (read_new_line(fd, line, rest));
}

char	*read_new_line(int fd, char *line, char **rest)
{
	int		flag;
	ssize_t	n;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	flag = 0;
	while (!flag)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		flag = concat_line(&line, buffer, &rest[fd]);
	}
	if ((!ft_strlen(line) && !n) || n < 0)
	{
		free(line);
		line = NULL;
	}
	free(buffer);
	return (line);
}

int	concat_line(char **line, char *buffer, char **rest)
{
	int		flag;
	char	*tmp;
	size_t	n;

	flag = 0;
	n = find_chr(buffer, '\n');
	tmp = ft_strnjoin(*line, buffer, ft_strlen(*line), n + 1);
	if (!tmp)
		return (1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	if (buffer[n] == '\n')
	{
		flag = 1;
		tmp = ft_strdup(buffer + n + 1);
		if (!tmp)
			return (1);
	}
	free(*rest);
	*rest = tmp;
	return (flag);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	int		n;
// 	char	*s;

// 	fd = open("sample0.txt", O_RDONLY);
// 	n = 20;
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("============%d\n", i);
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);
// 	}
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }