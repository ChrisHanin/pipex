/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/24 15:48:45 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h" 

void	*ft_free_matrix_b(char **args)
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
	return (NULL);
}

int	ft_verif_pipex_b(int argc, char **argv)
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
	if (argc < 5)
	{
		ft_printf("Problem with the arguments\n");
		return (0);
	}
	return (1);
}

int	ft_size_matrix_b(char **matrix)
{
	int	size;

	size = 0;
	while (matrix[size])
		size++;
	return (size);
}

int	ft_close_assign_b(int out, int in)
{
	close(out);
	return (in);
}

void	ft_init_int_b(int *i, int *prev_fd, int *ffd, char **argv)
{
	*i = 2;
	*prev_fd = -1;
	ffd[0] = ft_open_read_perror_b(argv[1]);
	ffd[1] = ft_open_write_perror_b(argv[ft_size_matrix_b(argv) - 1]);
}
