/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufaccia <rufaccia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:05:48 by rufaccia          #+#    #+#             */
/*   Updated: 2024/08/05 18:53:35 by rufaccia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *stash)
{
	t_list	*current;
	int		i;

	current = stash;
	i = 0;
	if (current->content[i] == '\n')
		return (1);
	return (0);
}

// Retourne un pointeur vers le dernier noeud dans la stash
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

// Génère une ligne de la stash
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
void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
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
	t_list	*current;
	int		i;

	current = stash
	i = 0;
	if (current->content[i] == '\n')
		return (1);
	i++;
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
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		return (i);
}*/