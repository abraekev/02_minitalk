# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 20:48:57 by abraekev          #+#    #+#              #
#    Updated: 2024/05/01 09:31:08 by abraekev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# **************************************************************************** #

PROJECT		=	minitalk

SRCSERV		=	server.c
SRCCLNT		=	client.c

DIRSRC		=	./srcs/
DIRLIBFT	=	./srcs/libft/
DIRINC		=	./includes/

LIBFT		=	$(DIRLIBFT)libft.a
SRCSSERV	=	$(addprefix $(DIRSRC), $(SRCSERV)) 
SRCSCLNT	=	$(addprefix $(DIRSRC), $(SRCCLNT))
OBJSSERV	=	$(SRCSSERV:.c=.o)
OBJSCLNT	=	$(SRCSCLNT:.c=.o)

NAMESERV	=	server
NAMECLNT	=	client

AR			=	ar -rcs
RL			=	ranlib
RM			=	rm -f
GCC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror
MAKEFLAGS	+=	--no-print-directory
LINK		=	-L$(DIRLIBFT) -lft

GREEN		=	\033[032m
CYAN		=	\033[036m
NOCLR		=	\033[0m

# RULES
# **************************************************************************** #

all:		$(LIBFT) $(NAMECLNT) $(NAMESERV)

$(NAMECLNT):	$(OBJSCLNT)
					@$(GCC) $(CFLAGS) $(OBJSCLNT) -o $(NAMECLNT) $(LINK)
					@printf "$(GREEN)%-12s%-12s\n$(NOCLR)" "compiled" "$(NAMECLNT)"

$(NAMESERV):	$(OBJSSERV)
					@$(GCC) $(CFLAGS) $(OBJSSERV) -o $(NAMESERV) $(LINK)
					@printf "$(GREEN)%-12s%-12s\n$(NOCLR)" "compiled" "$(NAMESERV)"
$(LIBFT):
				@$(MAKE) -C $(DIRLIBFT)

.c.o:
		@$(GCC) $(CFLAGS) -I$(DIRINC) -c $< -o $(<:.c=.o)

bonus:	all

clean:
		@$(RM) $(OBJSSERV) $(OBJSCLNT)
		@$(MAKE) -C $(DIRLIBFT) clean
		@printf "$(CYAN)%-12s%-12sOBJECTS\n$(NOCLR)" "cleaned" "$(PROJECT)"

fclean:		clean
			@$(RM) $(NAMESERV) $(NAMECLNT)
			@$(MAKE) -C $(DIRLIBFT) QUIET=1 fclean
			@printf "$(CYAN)%-12s%-12sPROGRAMS\n$(NOCLR)" "cleaned" "$(PROJECT)"

re:		fclean all

.PHONY:		all bonus clean fclean re

# **************************************************************************** #
