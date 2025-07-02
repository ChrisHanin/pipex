/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/24 15:51:35 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

void	ft_perror_exit_b(char *message)
{
	perror(message);
	exit(127);
}

void	ft_dup2_child_b(int i, int *ffd, int *pipefd, char **argv)
{
	if (i == 2)
		ft_dup2_close_b(ffd[0], STDIN_FILENO, 0, 1);
	else
		ft_dup2_close_b(ffd[2], STDIN_FILENO, 0, 1);
	if (i == ft_size_matrix_b(argv) - 2)
		ft_dup2_close_b(ffd[1], STDOUT_FILENO, 0, 1);
	else
		ft_dup2_close_b(pipefd[1], STDOUT_FILENO, pipefd[0], 1);
}

void	ft_pipe_perror_b(int *pipefd)
{
	if (pipe(pipefd) == -1)
		ft_perror_exit_b("pipe");
}

void	ft_pipex_b(int argc, char **argv, char **envp)
{
	int		i;
	int		ffd[3];
	int		pipefd[2];
	pid_t	pid;

	ft_init_int_b(&i, &ffd[2], ffd, argv);
	while (i < argc -1)
	{
		if (i < argc - 2)
			ft_pipe_perror_b(pipefd);
		pid = fork();
		if (pid == 0)
		{
			ft_dup2_child_b(i, ffd, pipefd, argv);
			ft_execute_cmd_b(argv[i], envp);
		}
		else if (pid > 0)
			ffd[2] = ft_close_parent_b(i, argc, ffd[2], pipefd);
		else
			ft_perror_exit_b("fork");
		i++;
	}
	while (wait(NULL) > 0)
		;
	ft_dup2_close_b(ffd[0], 0, ffd[1], 0);
}

int	main(int argc, char **argv, char **env)
{
	if (ft_verif_pipex_b(argc, argv) == 0)
		return (1);
	else
	{
		if (argc < 5)
		{
			return (1);
		}
		else
		{
			ft_pipex_b(argc, argv, env);
		}
	}
	return (0);
}
