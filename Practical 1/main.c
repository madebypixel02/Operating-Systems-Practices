/* ************************************************************************** */
/*                                                                            */
/*                                           =@@*   +@@+                      */
/*                                           =@@*   +@@+ :*%@@@%*:            */
/*                                           =@@*   =@@+.@@@=--%@@-           */
/*                                           :@@%. .#@@--@@*   +@@* .+%@@@    */
/*   main.c                                   =%@@@@@@+ =@@*   =@@+.@@@+-=    */
/*                                              .---:   -@@#.  *@@--@@*       */
/*   By: aperez-b <aperez-b@uoc.edu>                     +@@@@@@@* +@@+       */
/*                                                         :-==:.  -@@#       */
/*   Created: 2022/11/05 16:34:31 by aperez-b                       +@@@%@    */
/*   Updated: 2022/11/08 10:30:27 by aperez-b                                 */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 80

/* Linked list struct definition */
struct s_list
{
	void			*content;
	struct s_list	*next;
};

/* Creates new linked list node */
static struct s_list	*ft_lstnew(void *content)
{
	struct s_list	*new;

	new = malloc(sizeof(struct s_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* Adds node of a linked list to the end of another linked list */
static void	ft_lstadd_back(struct s_list **lst, struct s_list *new_node)
{
	struct s_list	*start;

	if (!lst)
		return ;
	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = new_node;
	}
	else
		*lst = new_node;
}

/* Deletes every element of a linked list from the given list node */
static void	ft_lstclear(struct s_list *lst)
{
	struct s_list	*aux;

	aux = lst;
	while (lst)
	{
		aux = lst->next;
		free(lst->content);
		free(lst);
		lst = aux;
	}
}

/* Reads input and checks for duplicate strings */
static int	get_input(struct s_list *lst, char **input)
{
	int	i;

	*input = malloc(STR_SIZE + 1);
	if (!*input)
	{
		ft_lstclear(lst);
		fprintf(stderr, "Device out of memory\n");
		exit(1);
	}
	bzero(*input, STR_SIZE + 1);
	scanf("%s", *input);
	i = 1;
	while (lst)
	{
		if (!strcmp(lst->content, *input))
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

/* Main program */
int	main(void)
{
	char			*input;
	struct s_list	*list;
	int				i;
	int				pos;

	i = 1;
	list = NULL;
	while (1)
	{
		input = NULL;
		fprintf(stdout, "%d: ", i);
		pos = get_input(list, &input);
		ft_lstadd_back(&list, ft_lstnew(input));
		if (pos != -1)
		{
			fprintf(stdout, "%s repeated (%d)\n", input, pos);
			break ;
		}
		i++;
	}
	ft_lstclear(list);
}
