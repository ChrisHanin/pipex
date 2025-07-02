/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/22 20:02:42 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror_exit(char *message)
{
	message = NULL;
	perror(message);
	exit(127);
}

void	ft_dup2_child(int i, int *ffd, int *pipefd, char **argv)
{
	if (i == 2)
		ft_dup2_close(ffd[0], STDIN_FILENO, 0, 1);
	else
		ft_dup2_close(ffd[2], STDIN_FILENO, 0, 1);
	if (i == ft_size_matrix(argv) - 2)
		ft_dup2_close(ffd[1], STDOUT_FILENO, 0, 1);
	else
		ft_dup2_close(pipefd[1], STDOUT_FILENO, pipefd[0], 1);
}

void	ft_pipe_perror(int *pipefd)
{
	if (pipe(pipefd) == -1)
		ft_perror_exit("pipe");
}

void	ft_pipex(int argc, char **argv, char **envp)
{
	int		i;
	int		ffd[3];
	int		pipefd[2];
	pid_t	pid;

	ft_init_int(&i, &ffd[2], ffd, argv);
	while (i < argc -1)
	{
		if (i < argc - 2)
			ft_pipe_perror(pipefd);
		pid = fork();
		if (pid == 0)
		{
			ft_dup2_child(i, ffd, pipefd, argv);
			ft_execute_cmd(argv[i], envp);
		}
		else if (pid > 0)
			ffd[2] = ft_close_parent(i, argc, ffd[2], pipefd);
		else
			ft_perror_exit("fork");
		i++;
	}
	while (wait(NULL) > 0)
		;
	ft_dup2_close(ffd[0], 0, ffd[1], 0);
}

int	main(int argc, char **argv, char **env)
{
	if (ft_verif_pipex(argc, argv) == 0)
		return (1);
	else
		ft_pipex(argc, argv, env);
	return (0);
}
