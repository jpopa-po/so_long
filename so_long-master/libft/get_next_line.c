/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:54:21 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/03/22 19:57:18 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rd(t_var *variable, char **line, int fd)
{
	while (variable->rd > 0)
	{
		variable->chk = ft_strchr(variable->buff, '\n');
		variable->aux = ft_strjoin(*line, variable->buff);
		free(*line);
		*line = ft_strdup(variable->aux);
		free(variable->aux);
		if (variable->chk != NULL)
			break ;
		variable->rd = read(fd, variable->buff, BUFFER_SIZE);
		variable->buff[variable->rd] = '\0';
	}
	return (*line);
}

static char	*ft_line(t_var *variable, char **line)
{
	variable->len = 0;
	while (line[0][variable->len] != '\n' && line[0][variable->len] != '\0')
		variable->len++;
	variable->aux = ft_substr(*line, 0, (variable->len + 1));
	free(*line);
	*line = NULL;
	*line = ft_strdup(variable->temp);
	free(variable->temp);
	variable->temp = NULL;
	return (variable->aux);
}

static char	*ft_last(t_var *variable, char **line)
{
	variable->aux = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (variable->aux);
}

static char	*ft_isempty(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	t_var		variable;

	variable.temp = NULL;
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, variable.buff, 0) == -1)
		return (NULL);
	variable.rd = read(fd, variable.buff, BUFFER_SIZE);
	if (variable.rd == -1 && !line)
		return (NULL);
	variable.buff[variable.rd] = '\0';
	if (!line)
		line = ft_strdup("");
	line = ft_rd(&variable, &line, fd);
	variable.chk = ft_strchr(line, '\n');
	if (variable.chk && variable.chk[0] != '\0')
		variable.temp = ft_strdup(variable.chk + 1);
	if (line == NULL || line[0] == '\0')
		return (ft_isempty(&line));
	if (variable.temp)
		return (ft_line(&variable, &line));
	else
		return (ft_last(&variable, &line));
	return (NULL);
}
