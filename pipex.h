/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/24 18:22:05 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_array_fd
{
	int			*pipefd;
	int			*file_fd;
}		t_afd;

void	ft_dup2_close(int oldfd, int newfd, int fd, int ok);
void	ft_execute_cmd(char *command, char **envp);
void	ft_free_execute(char **a, char **b);
void	ft_init_int(int *i, int *prev_fd, int *ffd, char **argv);
void	ft_perror_exit(char *message);
int		ft_close_assign(int out, int in);
int		ft_close_parent(int i, int argc, int prev_fd, int *pipefd);
int		ft_open_read_perror(char *argv);
int		ft_open_write_perror(char *argv);
int		ft_size_matrix(char **matrix);
int		ft_verif_pipex(int argc, char **argv);
void	*ft_free_matrix(char **args);
char	**ft_build_cmd(char *str);

#endif
