# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 13:37:08 by marias-e          #+#    #+#              #
#    Updated: 2022/10/11 16:30:58 by marias-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		ft_write_c.c \
		ft_write_s.c \
		ft_write_p.c \
		ft_write_di.c \
		ft_write_u.c \
		ft_write_x.c \
		ft_write_upx.c \
		ft_strlen.c \

OBJS 	=	${SRCS:.c=.o}

CC	=	gcc -Wall -Wextra -Werror

NAME 	=	libftprintf.a

.c.o:
	${CC} -c $< -o ${<:.c=.o} -I.

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}
	
all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re