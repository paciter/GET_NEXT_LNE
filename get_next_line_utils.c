/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufaccia <rufaccia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:05:48 by rufaccia          #+#    #+#             */
/*   Updated: 2024/08/02 15:33:37 by rufaccia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

// Vérifie si un saut de ligne existe dans la stash
int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
	{
		return (0);
	}
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Retourne un pointeur vers le dernier nœud dans notre stash
t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

// Calcule la taille de la ligne de caractères
void	generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

// Libère toute la stash
void	free_stash(t_list **stash)
{
	t_list *current;
	t_list *next;

	current = *stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*stash = NULL;
}

// Calcule la longueur d'une chaîne de caractères
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}



/*
int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
	{
		return (0);
	}
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// return un pointeur au dernier noeud dans notre stash
void t_list	*ft_lst_get_last(include)
{
	t_list	*current;                   

	current = stash;
	while (current && current->next)
	{
	    current = current->next
    }
	return (current);
}

// calcul la taille de chars sur la ligne
void	generate_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

// free toute la stash
void	free_stash(void)
{
	t_list *current;
	t_list *next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int ft_strlen(char *str)
{
	int	i;
	i=0;
	while(str[i])
	return(i);
}
*/