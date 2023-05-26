/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:05:55 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/26 17:34:29 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# if !BUFFER_SIZE || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# if !MAX_FD || MAX_FD <= 0 || MAX_FD > INT_MAX
#  undef MAX_FD
#  define MAX_FD 24576
# endif

char	*get_next_line(int fd);
int		concat_line(char **line, char *buffer, char **rest);
void	handle_error(char **line, ssize_t n, int flag);
int		is_eof(char **line, ssize_t n);
size_t	find_chr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n1, size_t n2);
char	*ft_strdup(const char *s1);

#endif