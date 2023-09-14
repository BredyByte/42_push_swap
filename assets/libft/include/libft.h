/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:12:49 by dbredykh          #+#    #+#             */
/*   Updated: 2023/09/14 11:45:45 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				n;
	int				fin_ind;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_is_valid_number(char *str);
int			ft_isdigit(char *str);
int			ft_isprint(int c);
void		*ft_memcpy(void *dest, const void *src, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const void *s, char type);
size_t		ft_strlcpy(char *dest, const char *src, size_t len);
size_t		ft_strlcat(char *dest, const char *src, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strndup(const char *s, size_t n);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_printf(const char *str, ...);
size_t		ft_putstr(char *str);
size_t		ft_putchar(int c);
size_t		ft_putdec(int n);
size_t		ft_putdeclong(unsigned int n);
char		*ft_itoalong(long n);
int			ft_putvoid(void *p);
int			ft_puthexa(unsigned long long nb, char ch);
char		*ft_free(char *buffer, char *buf);
char		*get_next_line(int fd);
double		ft_atof(char *str);
int			ft_isspace(int c);
int			ft_dstrlen(char **str);
long		ft_abs(int n);
int			ft_strcmp(char *s1, char *s2);

// Nodes controls

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int num);
int			ft_lstsize(t_list *lst);

#endif
