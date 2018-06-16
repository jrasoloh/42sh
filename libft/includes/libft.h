/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:16:26 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/12 13:32:42 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <dirent.h>
# include <errno.h>

/*
** List
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstapp(t_list *alst, t_list *new);
t_list			*ft_lstlast(t_list *alst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));

/*
** Stack
*/
typedef struct	s_stack
{
	void			*data;
	struct s_stack	*next;
}				t_stack;

t_stack			*ft_stkpush(t_stack **stack, void *data);
t_stack			*ft_stkpop(t_stack **stack, void (*del)(void **data));
void			ft_stkdel(t_stack **stack, void (*del)(void **data));

/*
** Simplified List
*/
typedef struct	s_slist
{
	void			*data;
	struct s_slist	*next;
}				t_slist;

t_slist			*ft_slistnew(void *data);
t_slist			*ft_slistadd(t_slist **list, void *data);
t_slist			*ft_slistaddn(t_slist **list, void *data);
t_slist			*ft_slistapp(t_slist *list, void *data);
t_slist			*ft_slistappn(t_slist **list, void *data);
t_slist			*ft_slistins_s(t_slist **list, void *data,
		int (*cmp)(void *d, void *d2));
t_slist			*ft_slistinsn_s(t_slist **list, void *data,
		int (*cmp)(void *d, void *d2));
t_slist			*ft_slistlast(t_slist *list);
size_t			ft_slistlen(t_slist *list);
void			ft_slistiter(t_slist *list, void (*f)(void *data));
void			ft_slistdel(t_slist **list, void (*del)(void **data));

/*
** Simplified Integer List
*/
typedef struct	s_silist
{
	int				data;
	struct s_silist	*next;
}				t_silist;

t_silist		*ft_silistnew(int data);
t_silist		*ft_silistadd(t_silist **list, int data);
t_silist		*ft_silistaddn(t_silist **list, int data);
t_silist		*ft_silistins_s(t_silist **list, int data,
		int (*cmp)(int d, int d2));
t_silist		*ft_silistinsn_s(t_silist **list, int data,
		int (*cmp)(int d, int d2));
void			ft_silistdel(t_silist **list);

/*
** Ascii Binary Search Tree
*/
typedef struct	s_abst
{
	char			*data;
	struct s_abst	*left;
	struct s_abst	*right;
}				t_abst;

t_abst			*ft_abstnew(char *data);
t_abst			*ft_abstaddn(t_abst **tree, char *data);
void			ft_abstadd(t_abst *tree, char *data);
t_abst			*ft_abstmax(t_abst *tree);
t_abst			*ft_abstmin(t_abst *tree);
void			ft_abstiter_inorder(t_abst *tree, void (*f)(char *));
void			ft_abstdel(t_abst **tree);

/*
** Binary Search Tree with Key value
*/
typedef struct	s_bstk
{
	void			*key;
	void			*data;
	struct s_bstk	*left;
	struct s_bstk	*right;
}				t_bstk;

t_bstk			*ft_bstknew(void *key, void *data);
t_bstk			*ft_bstkaddn(t_bstk **tree, void *key, void *data,
		int (*cmp)(void *k, void *k2));
t_bstk			*ft_bstkaddnt(t_bstk **tree, t_bstk *to_add,
		int (*cmp)(void *k, void *k2));
void			ft_bstkadd(t_bstk *tree, void *key, void *data,
		int (*cmp)(void *k, void *k2));
void			ft_bstkaddt(t_bstk *tree, t_bstk *to_add,
		int (*cmp)(void *k, void *k2));
t_bstk			*ft_bstkmax(t_bstk *tree);
t_bstk			*ft_bstkmin(t_bstk *tree);
void			ft_bstkiter_inorder(t_bstk *tree, void (*f)(void *key,
			void *data));
void			ft_bstkdel(t_bstk **tree, void (*del)(void **key, void **data));

/*
** Binary Search Tree
*/
typedef struct	s_bst
{
	void			*data;
	struct s_bst	*left;
	struct s_bst	*right;
}				t_bst;

t_bst			*ft_bstnew(void *data);
t_bst			*ft_bstaddn(t_bst **tree, void *data,
		int (*cmp)(void *d, void *d2));
t_bst			*ft_bstaddnt(t_bst **tree, t_bst *to_add,
		int (*cmp)(void *d, void *d2));
void			ft_bstadd(t_bst *tree, void *data,
		int (*cmp)(void *d, void *d2));
void			ft_bstaddt(t_bst *tree, t_bst *to_add,
		int (*cmp)(void *d, void *d2));
t_bst			*ft_bstmax(t_bst *tree);
t_bst			*ft_bstmin(t_bst *tree);
void			ft_bstiter_inorder(t_bst *tree, void (*f)(void *data));
void			ft_bstdel(t_bst **tree, void (*del)(void **data));

/*
** Memory
*/
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			ft_bzero(void *s, size_t n);

/*
** String
*/
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strapp(char *dst, char *src);
char			*ft_strappf(char *dst, char *src);
char			*ft_strappc(char *dst, char src);
char			*ft_strappcf(char *dst, char src);
char			*ft_strchr(const char *s, int c);
int				ft_strchri(const char *s, int c);
int				ft_strnchri(const char *s, int c, int n);
char			*ft_strrchr(const char *s, int c);
int				ft_strrchri(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
int				ft_strext(char **s, size_t size);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strrm(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

char			*ft_itoa(int n);
int				ft_atoi(const char *str);

char			*ft_format_internal(const char *s, va_list *va);
char			*ft_format(const char *s, ...);

int				ft_toupper(int c);
int				ft_tolower(int c);

int				ft_strisblank(const char *s);

/*
** Null Terminated String Array
*/
size_t			ft_ntsarr_len(char **ntsarr);
void			ft_ntsarr_free(char ***ntsarr);
char			**ft_ntsarr_push(char ***ntsarr, char *s);
void			ft_ntsarr_print(char **ntsarr, int newline);

/*
** Math
*/
int				ft_abs(int n);
int				ft_pow(int n, int power);
size_t			ft_numlen(int n);
size_t			ft_numlen_base(int n, int base);

/*
** Misc
*/
# define FT_UNUSED(x) (void)(x)

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isblank(int c);

/*
** Output
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base_fd(int n, char *base, int fd);
void			ft_putmem_fd(void *p, size_t len, int mode, int fd);
void			ft_put_fd(int fd, const char *s, ...);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbr_base(int n, char *base);
void			ft_putdebug(char const *s);
void			ft_putmem(void *p, size_t len, int mode);
void			ft_put(const char *s, ...);

/*
** Array
*/
void			ft_tabsort(int *tab, int len);

/*
** Path
*/
char			*ft_pathjoin(const char *p1, const char *p2);
char			*ft_pathjoinc(const char *p1, const char *p2);
char			*ft_basename(char *path);

/*
** Error Handling
*/
int				ft_throw(const char *name, const char *err_message,
		char *err_value, int err_return);
int				ft_err(int err_return, const char *s);

/*
** File
*/
# define BUFF_SIZE 32

typedef struct	s_vars
{
	int		i;
	int		end;
	int		read_val;
	char	readbuf[BUFF_SIZE + 1];
}				t_vars;

int				ft_gnl(const int fd, char **line);
int				ft_file_exists(const char *path);

#endif
