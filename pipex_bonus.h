/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/24 18:24:25 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_array_fd
{
	int			*pipefd;
	int			*file_fd;
}		t_afd;

void	ft_dup2_close_b(int oldfd, int newfd, int fd, int ok);
void	ft_execute_cmd_b(char *command, char **envp);
void	ft_free_execute_b(char **a, char **b);
void	ft_init_int_b(int *i, int *prev_fd, int *ffd, char **argv);
void	ft_init_int_b_hd(int *i, int *prev_fd, int *ffd, char **argv);
void	ft_perror_exit_b(char *message);
int		ft_close_assign_b(int out, int in);
int		ft_close_parent_b(int i, int argc, int prev_fd, int *pipefd);
int		ft_open_read_perror_b(char *argv);
int		ft_open_write_perror_b(char *argv);
int		ft_size_matrix_b(char **matrix);
int		ft_verif_pipex_b(int argc, char **argv);
void	*ft_free_matrix_b(char **args);
char	**ft_build_cmd_b(char *str);

#endif
