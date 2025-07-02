/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/24 18:21:01 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

int	ft_build_path(int j, char **paths, char **cmd)
{
	char	*tmp;

	tmp = paths[j];
	paths[j] = ft_strjoin(tmp, "/");
	free(tmp);
	if (!paths[j])
	{
		ft_free_execute(paths, cmd);
		return (-1);
	}
	tmp = paths[j];
	paths[j] = ft_strjoin(tmp, cmd[0]);
	free(tmp);
	if (!paths[j])
	{
		ft_free_execute(paths, cmd);
		return (-1);
	}
	j++;
	return (j);
}

int	ft_check_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_execute_cmd_bis(int j, char **paths, char **cmd, char **useless)
{
	if (j == -1)
	{
		ft_free_execute(paths, cmd);
		return (ft_perror_exit("pipex : execute_cmd"));
	}
	execve(paths[j], cmd, NULL);
	if (paths == cmd)
	{
		ft_free_execute(paths, useless);
	}
	else
		ft_free_execute(paths, cmd);
	ft_perror_exit("pipex : execute_cmd");
}

void	ft_execute_cmd(char *command, char **envp)
{
	int		j;
	char	*allpaths;
	char	**paths;
	char	**cmd;

	j = 0;
	allpaths = ft_find_path(envp);
	paths = ft_split(allpaths, ':');
	if (!paths)
		return ;
	cmd = ft_build_cmd(command);
	if (!cmd)
		return (ft_free_execute(paths, NULL));
	if (access(cmd[0], X_OK) == 0)
		ft_execute_cmd_bis(0, cmd, cmd, paths);
	while (paths[j])
	{
		j = ft_build_path(j, paths, cmd);
		if (j == -1)
			return (ft_free_execute(paths, cmd));
	}
	j = ft_check_path(paths);
	ft_execute_cmd_bis(j, paths, cmd, NULL);
}
