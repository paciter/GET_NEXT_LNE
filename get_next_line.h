/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufaccia <rufaccia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:04:46 by rufaccia          #+#    #+#             */
/*   Updated: 2024/08/02 14:17:30 by rufaccia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int 				ft_strlen(char *str);
char				*get_next_line(int fd);
void				read_and_stash(int fd, t_list **stash, int *readed_ptr);
void				add_to_stash(t_list **stash, char *buf, int readed);
void				extract_line(t_list *stash, char **line);
void				clean_stash(t_list **stash);
int					found_newline(t_list *stash);
t_list		*ft_lst_get_last(t_list *stash);
void				generate_line(char **line, t_list *stash);
void				free_stash(t_list **stash);

#endif