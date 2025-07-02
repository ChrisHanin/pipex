/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/23 15:49:49 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_free_matrix(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (NULL);
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
	args = NULL;
	return (NULL);
}

int	ft_verif_pipex(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_printf("Empty argument\n");
			return (0);
		}
		i++;
	}
	if (argc != 5)
	{
		ft_printf("Problem with the arguments\n");
		return (0);
	}
	return (1);
}

int	ft_size_matrix(char **matrix)
{
	int	size;

	size = 0;
	while (matrix[size])
		size++;
	return (size);
}

int	ft_close_assign(int out, int in)
{
	close(out);
	return (in);
}

void	ft_init_int(int *i, int *prev_fd, int *ffd, char **argv)
{
	*i = 2;
	*prev_fd = -1;
	ffd[0] = ft_open_read_perror(argv[1]);
	ffd[1] = ft_open_write_perror(argv[ft_size_matrix(argv) - 1]);
}
