/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:36 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/10 13:46:39 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//	HEADERS
/******************************************************************************/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>

//	MACROS
/******************************************************************************/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif /*BUFFER_SIZE*/

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif /*OPEN_MAX*/

//	STRUCTS & ENUMS
/******************************************************************************/

typedef struct s_flags
{
	char	cspec;
	int		just_l;
	int		pad_zero;
	int		pref_space;
	int		pref_plus;
	int		alt_print;
	int		min_width;
	int		precision;
}	t_flags;

typedef struct s_data
{
	const char	*src;
	size_t		s_len;
	char		cspec;
	char		*fspec;
	size_t		f_len;
	char		*insert;
	size_t		i_len;
}	t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//	DEFINITIONS
/******************************************************************************/

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*get_next_line(int fd);

	//	ft_printf START
char	*ftpf_apply_precision_s(t_data *d, t_flags f);
void	ftpf_set_i_len(t_data *d);
void	ftpf_set_s_len_and_nullprotect(t_data *d);
void	ftpf_set_lengths(t_data *d);
char	*ftpf_apply_width_others(t_data *d, t_flags f);
char	*ftpf_apply_precision(t_data *d, t_flags f);
char	*ftpf_add_prefix(t_data *d, char *prefix);
char	*ftpf_apply_spaceplus(t_data *d, t_flags f);
char	*ftpf_apply_altprint(t_data *d, t_flags f);
char	*ftpf_get_vptr_base(uintptr_t nbr, t_data *d);
char	*ftpf_get_uint_base(unsigned int nbr, char c);
t_flags	ftpf_initiate_flags(void);
int		ftpf_get_flags(char *fspec, t_flags *flags, va_list args);
int		ftpf_validate_flags(char *s, t_flags *flags);
char	*ftpf_get_char(char c);
char	*ftpf_get_str(char *s);
char	*ftpf_get_insertstr(t_data *d, va_list args);
char	*ftpf_get_empty_str(t_data *d);
char	*ftpf_get_null_str(t_data *d);
void	ftpf_putstr_special(t_data *d);
void	ftpf_free_strs(size_t n, ...);
void	ftpf_free_data(t_data *d);
int		ft_printf(const char *s, ...);
	//	ft_printf END

#endif /*LIBFT_H*/
