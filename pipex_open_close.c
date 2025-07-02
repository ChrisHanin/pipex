/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/22 19:09:00 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2_close(int oldfd, int newfd, int fd, int ok)
{
	if (ok == 1)
	{
		if (oldfd < 0)
			ft_perror_exit("dup2: invalid fd");
		if (dup2(oldfd, newfd) == -1)
			ft_perror_exit("dup2");
	}
	if (oldfd > 2)
		close(oldfd);
	if (fd > 2)
		close(fd);
}

int	ft_close_parent(int i, int argc, int prev_fd, int *pipefd)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (i < argc - 2)
		prev_fd = ft_close_assign(pipefd[1], pipefd[0]);
	return (prev_fd);
}

int	ft_open_read_perror(char *argv)
{
	int	file_fd;

	file_fd = open(argv, O_RDONLY);
	if (file_fd < 0)
		ft_perror_exit("file_in_fd");
	return (file_fd);
}

int	ft_open_write_perror(char *argv)
{
	int	file_fd;

	file_fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd < 0)
		ft_perror_exit("file_out_fd");
	return (file_fd);
}

void	ft_free_execute(char **a, char **b)
{
	ft_free_matrix(b);
	ft_free_matrix(a);
}
