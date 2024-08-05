/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufaccia <rufaccia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:05:57 by rufaccia          #+#    #+#             */
/*   Updated: 2024/08/05 18:10:10 by rufaccia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;

	char	*line;
	int		readed;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		// derniere cond pour si fichier  pas lisible ,
		//utile pour tester si le ficher et lisible ou non sans avancer la lecture return (NULL);
	readed = 1;
	line = 0;
	// 1. read de fd and add to list
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	// 2. extract de la stash to line
	extract_line(stash, &line);
	// 3. clean la stash
	clean_stash(&stash);
	return (line);
}
// uses read pour add chars a la stash

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buf;

	while (!found_newline(*stash) && *readed_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		*readed_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buf);
			return ;
		}
		buf[*readed_ptr] = '\0';
		add_to_stash(stash, buf, *readed_ptr);
		free(buf);
	}
}
// adds le  contenue de  notre buffer a la fin de notre stash

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL) return ;
		new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1)); 
	if (new_node->content == NULL) 
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}

// extraire all chars de la stash et les mettres dans line( se coupe apres le first \n)
void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash) ;
	if (*line == NULL)
	return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;


	if (stash == NULL)
		return ;
	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i)
				+ 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	i;

	i = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	// if(test)
	// {
	// 	printf("%s", test);
	// 	free(test);
	// }
	return (0);
}
