#include <stdio.h>
#include <stdlib.h>

void *ft_malloc(size_t size);

/* For __GNUC__ */
/* for other env: https://stackoverflow.com/questions/1113409/attribute-constructor-equivalent-in-vc */
#define malloc(size) ft_malloc(size)
#define INITIALIZER(f) \
	static void f(void) __attribute__((constructor)); \
	static void f(void)

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *g_allocs;

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_allocate(void *ptr)
{
	t_list *new;

	if (!ptr)
		return ;
	if (!g_allocs)
	{
		g_allocs = ft_lstnew(ptr);
		if (!g_allocs)
			exit(1);
	}
	else
	{
		if (!(new = ft_lstnew(ptr)))
			exit(1);
		ft_lstadd_front(&g_allocs, new);
	}
}

void	*ft_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	ft_allocate(ptr);
	return (ptr);
}

void	cleanup(void)
{
	ft_lstclear(&g_allocs, free);
}

INITIALIZER(initialize)
{
	atexit(cleanup);
}

int main(void)
{
	int *tab;

	tab = malloc(sizeof(int) * 10000);
	printf("%p\n", tab);
	tab = malloc(sizeof(int) * 10000);
	printf("%p\n", tab);
	tab = malloc(sizeof(int) * 10000);
	printf("%p\n", tab);
	return (0);
}
