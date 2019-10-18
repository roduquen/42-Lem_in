/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:17:26 by roduquen          #+#    #+#             */
/*   Updated: 2019/10/09 19:21:24 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** INCLUDES
*/

# include <string.h>

/*
** STRUCTURES + TYPEDEF
*/

# define BUFF 1025

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

typedef struct	s_queue
{
	void			*ptr;
	struct s_queue	*prev;
	struct s_queue	*next;
}				t_queue;

/*
** PARTIE OBLIGATOIRE NUMERO 1
*/

int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strdup(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle
	, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);

/*
** PARTIE OBLIGATOIRE NUMERO 2
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** PARTIE BONUS DEMANDE
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** PARTIE BONUS NON DEMANDE
*/

int				ft_isspace(int c);
int				ft_iswhitespace(int c);
void			*ft_memrchr(const void *s, int c, size_t n);
char			*ft_realloc(char *str, int size);
void			ft_strrev(char *str);
void			ft_swapchar(char *a, char *b);
void			cocktail_sort_int(int *tab, size_t size);
void			cocktail_sort_string(char **tab, size_t size);
void			quick_sort_int(int *tab, size_t size);
void			quick_sort_string(char **tab, size_t size);
int				ft_strlendl(char *str);
void			ft_lstadd_back(t_list **alst, t_list *new);
t_queue			*queue_new(void *ptr);
void			queue_add(t_queue **last, t_queue *new);
void			queue_forward(t_queue **begin);
t_btree			*btree_create_node(void *item);
void			btree_apply_infix(t_btree *root, void (*applyf)(void*));
void			btree_apply_prefix(t_btree *root, void (*applyf)(void*));
void			btree_apply_suffix(t_btree *root, void (*applyf)(void*));
void			btree_insert_data(t_btree **root, void *item
	, int (*cmpf)(void*, void*));
void			*btree_search_item(t_btree *root, void *data_ref
	, int	(*cmpf)(void*, void*));
int				btree_level_count(t_btree *root);
int				btree_leaf_count(t_btree *root);
void			btree_apply_by_level(t_btree *root, void (*applyf)(void *item
		, int current_level, int is_first));
int				free_ptr(void *ptr);
char			*infinity_add_plus(char *nbr1, char *nbr2);
char			*infinity_mult(char *nbr1, char *nbr2);
long			ft_strtol(char *str, char **endptr, int base);

int				get_next_line(const int fd, char **line);
char			*ft_strndup(const char *str, int n);

#endif
