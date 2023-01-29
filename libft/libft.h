/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:38:28 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/29 08:32:04 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define BUFFER_SIZE 42

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}			t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *trim);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoinchar(char const *s1, char s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strcmp(char *s1, char *s2);
void	ft_swapjoinchar(char **s1, char s2);
void	ft_swapjoin(char **s1, char *s2);

//GNL
char	*get_next_line(int fd);
char	*ft_gnlsubstr(char *s, unsigned int start, size_t len);
char	*ft_substr2(char *s, unsigned int start, size_t len);
char	*ft_gnlstrjoin(char *s1, char *s2);
int		lf_count(char *str);
char	*create(char *sbuffer, int fd);
char	*beautiful(char **sbuffer);

//PRINTF
int		ft_printf(const char *str, ...);
int		ft_treatchar(char str, va_list list);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putnbru(unsigned int nb);
int		ft_puthex(unsigned int i, char *base);
int		ft_putp(void *i);
int		nbsize(long nb);
int		nbsize16(unsigned int nb);
int		nbsizeptr(unsigned long nb);
char	*ft_hex16base(unsigned int i, char *base);
char	*ft_hexptr(unsigned long nb, char *base);
char	*ft_utoa(unsigned int i);
char	*ft_itoa(int n);

//ADDONS
int		ft_isspace(char c);

#endif
