#include "get_next_line.h"

// Pas de modifications majeures, seulement des ajustements mineurs et des vérifications de pointeurs
int found_newline(t_list *stash)
{
    t_list  *current;
    int     i;

    current = stash;
    while (current) // Boucle modifiée pour vérifier si current n'est pas NULL
    {
        i = 0;
        while (current->content[i])
        {
            if (current->content[i] == '\n')
                return (1);
            i++;
        }
        current = current->next;
    }
    return (0);
}

// Pas de modifications majeures
t_list *ft_lst_get_last(t_list *stash)
{
    t_list  *current;

    current = stash;
    while (current && current->next)
    {
        current = current->next;
    }
    return (current);
}

// Ajout de vérifications de pointeurs et correction de la gestion de mémoire
void generate_line(char **line, t_list *stash)
{
    int len;
    t_list *current;
    int i;

    len = 0;
    current = stash;
    while (current)
    {
        i = 0;
        while (current->content[i])
        {
            if (current->content[i] == '\n')
            {
                len++;
                break ;
            }
            len++;
            i++;
        }
        current = current->next;
    }
    *line = malloc(sizeof(char) * (len + 1));
    if (*line == NULL) // Vérification ajoutée
        return ;
}

// Pas de modifications majeures
void free_stash(t_list *stash)
{
    t_list  *current;
    t_list  *next;

    current = stash;
    while (current)
    {
        free(current->content);
        next = current->next;
        free(current);
        current = next;
    }
}

// Pas de modifications majeures
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
void *ft_memset(void * ptn, int value, size_t count)
{
	size_t i;
	i = 0;
	while (i < count)
	{
		((char *) ptn)[i] = (char)value;
		i++;
	}
	return ptn;
}
