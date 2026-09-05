/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:02:52 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/05 18:47:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char *key, char **env)
{
	int		idx;
	size_t	key_len;

	idx = 0;
	key_len = ft_strlen(key);
	while (env[idx])
	{
		if (!ft_strncmp(env[idx], key, key_len) && env[idx][key_len] == '=')
			return (&env[idx][key_len + 1]);
		idx++;
	}
	return (NULL);
}

char	*join_path(char *possible_path, char *cmd_path)
{
	int		i;
	int		len;
	char	*path;

	len = ft_strlen(possible_path) + 1 + ft_strlen(cmd_path);
	path = malloc(sizeof(char) * (len + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (*possible_path)
		path[i++] = *possible_path++;
	path[i++] = '/';
	while (*cmd_path && *cmd_path != ' ')
		path[i++] = *cmd_path++;
	path[i] = '\0';
	return (path);
}

char	*find_cmd_path(char *cmd, char **env)
{
	int		idx;
	char	*value;
	char	*path;
	char	**all_paths;

	idx = -1;
	path = NULL;
	value = get_env("PATH", env);
	if (!value)
		return (NULL);
	all_paths = ft_split(value, ':');
	while (all_paths[++idx])
	{
		path = join_path(all_paths[idx], cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free_2d((void **)all_paths), path);
		free(path);
	}
	return (ft_free_2d((void **)all_paths), NULL);
}

void	pipex(char *infile, char *cmd[2], char *outfile, char **env)
{
	int		status;
	int		pid[2];
	int		new_fd[2];
	int		pipe_fd[2];
	char	*path;
	char	**argv;

	printf("%s < %s | %s > %s\n", infile, cmd[0], cmd[1], outfile);

	status = 0;

	if (access(infile, F_OK | R_OK) == -1)
		perror("access infile");

	if (pipe(pipe_fd) == -1)
		perror("pipe");
	
	pid[0] = fork();
	if (pid[0] == -1)
		perror("fork");

	if (pid[0] == 0)
	{
		new_fd[0] = open(infile, O_RDONLY);
		if (new_fd[0] < 0)
			perror("open infile");

		dup2(new_fd[0], STDIN_FILENO);	
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(new_fd[0]);
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		path = find_cmd_path(cmd[0], env);
		argv = ft_split(cmd[0], ' ');
		if (!path || execve(path, argv, env) == -1)
			perror("pipex");
		ft_free(path);
		ft_free_2d((void **)argv);
		if (WIFEXITED(status))
			WEXITSTATUS(status);
		exit(status);
	}

	pid[1] = fork();
	if (pid[1] == -1)
		perror("fork");
	if (pid[1] == 0)
	{
		new_fd[1] = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (new_fd[1] < 0)
			perror("access outfile");
		
		dup2(new_fd[1], STDOUT_FILENO);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(new_fd[1]);
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		path = find_cmd_path(cmd[1], env);
		argv = ft_split(cmd[1], ' ');
		if (!path || execve(path, argv, env) == -1)
			perror("execve");
		ft_free(path);
		ft_free_2d((void **)argv);
		if (WIFEXITED(status))
			WEXITSTATUS(status);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	else
	{
		pipex(argv[1], (char *[2]){argv[2], argv[3]}, argv[4], env);
		return (0);
	}
}