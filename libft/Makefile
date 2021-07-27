# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabet <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 17:26:12 by aabet             #+#    #+#              #
#    Updated: 2020/11/16 22:54:36 by aabet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

SRCS	=	ft_atoi.c\
		  	ft_bzero.c\
		  	ft_isalnum.c\
		  	ft_isalpha.c\
		  	ft_isascii.c\
		  	ft_isdigit.c\
		  	ft_isprint.c\
			ft_memcpy.c\
			ft_memset.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memmove.c\
		  	ft_strchr.c\
			ft_strlcat.c\
			ft_strlcpy.c\
		  	ft_strlen.c\
		  	ft_strncmp.c\
			ft_strnstr.c\
		  	ft_strrchr.c\
		  	ft_tolower.c\
		  	ft_toupper.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_substr.c\
			ft_strtrim.c\
			ft_itoa.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putnbr_fd.c\
			ft_putendl_fd.c\
			ft_strmapi.c\
			ft_split.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_min.c\
			ft_max.c

SRCS_B	=	ft_lstnew.c\
            ft_lstadd_front.c\
            ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJS_B	=	$(SRCS_B:.c=.o)

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:
			@gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

all:		$(NAME)

bonus:		$(OBJS) $(OBJS_B)
			@ ar rc $(NAME) $(OBJS) $(OBJS_B)

clean:
			@rm -rf $(OBJS) $(OBJS_B)

fclean:		clean
			@rm -rf  $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
