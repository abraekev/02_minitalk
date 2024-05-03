# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/05/01 09:26:23 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

GCC 	=	cc

CFLAGS +=	-Wall -Wextra -Werror

SRC		=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c	\
			ft_isprint.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c	\
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c 	\
			ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c	\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c	\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
			ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c		\
			ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c 			\
			ft_lstmap.c get_next_line_bonus.c ft_printf.c					\
			ft_printf_apply_prec.c ft_printf_apply_prec_s.c					\
			ft_printf_apply_spaceplusalt.c ft_printf_apply_width_others.c	\
			ft_printf_d_lens.c ft_printf_flags_init.c						\
			ft_printf_flags_validate.c ft_printf_gets.c ft_printf_s_utils.c	\
			ft_printf_uint_base.c ft_printf_vptr.c

DIRSRC	=	./srcs/
SRCS	=	$(addprefix $(DIRSRC), $(SRC))

OBJS	=	$(SRCS:.c=.o)

INCL	=	../../includes/

NAME	=	libft.a

LIBC	=	ar rc

LIBX	=	ranlib

RM		=	rm -f

GREEN	=	\033[032m
CYAN	=	\033[036m
NOCLR	=	\033[0m

# RULES
# **************************************************************************** #

all:		$(NAME)

.c.o:
			@$(GCC) $(CFLAGS) -I$(INCL) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				@$(LIBC) $(NAME) $(OBJS)
				@$(LIBX) $(NAME)
				@printf "$(GREEN)%-12s%-12s\n$(NOCLR)" "compiled" "$(NAME)"

bonus:		all

clean:
			@$(RM) $(OBJS)
			@$(RM) $(BOBJS)
ifndef QUIET
			@printf "$(CYAN)%-12s%-12s%-12s\n$(NOCLR)" "cleaned" "$(NAME)" "OBJECTS"
endif

fclean:		clean
				@$(RM) $(NAME)
			@printf "$(CYAN)%-12s%-12s%-12s\n$(NOCLR)" "cleaned" "$(NAME)" "LIBRARY"

re:			fclean all

.PHONY:		all bonus clean fclean re
# **************************************************************************** #
