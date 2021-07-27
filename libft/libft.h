/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:16:31 by aabet             #+#    #+#             */
/*   Updated: 2020/11/01 19:54:46 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
int					ft_isalnum(int ch);
int					ft_isprint(int ch);
int					ft_isascii(int ch);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
char				*ft_strrchr(const char *s, int pos);
char				*ft_strchr(const char *s, int pos);
char				*ft_strrchr(const char *s, int pos);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
char				*ft_strnstr(char *str1, char *str2, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void *dst, int c, size_t n);
void				ft_bzero(void *dst, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int ch, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
char				*ft_strdup(const char *str);
void				*ft_calloc(size_t num, size_t size);
char				*ft_substr(const char *s, size_t st, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_putchar(char c);
void				ft_putstr(const char *str);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

#endif
