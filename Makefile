# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 21:33:28 by jolopez-          #+#    #+#              #
#    Updated: 2022/10/19 18:56:34 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

BONUS_NAME	= checker

SRCS 		= srcs/a_distances.c \
			srcs/find_better_option_aux.c \
			srcs/find_better_option.c \
			srcs/managing_cases_aux.c \
			srcs/managing_cases.c \
			srcs/method.c \
			srcs/push_movements.c \
			srcs/push_swap.c \
			srcs/returning_from_b.c \
			srcs/reverse_rotate.c \
			srcs/rotate.c \
			srcs/swap_movements.c \
			srcs/three_elements.c \
			srcs/utils_2.c \
			srcs/utils.c \

BONUS		= srcs/checker/checker.c

OBJS		= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

INC 		= includes/

LIBS		= -lftprintf -L./includes/42_ft_printf -lft -L./includes/42_libft

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra -I $(INC) -g3

all: $(NAME)

$(NAME):	$(OBJS)
			make -C includes/42_libft
			make -C includes/42_ft_printf
			@echo "$(YELLOW) Creating push_swap... $(WHITE)"
			${CC} $(CFLAGS) ${OBJS} $(LIBS) -o ${NAME}
			@echo "$(GREEN) Done..."			
			
bonus:		$(NAME)
			@echo "$(YELLOW) Creating checker... $(WHITE)"
			${CC} -o ${BONUS_NAME} ${BONUS_OBJS} $(LIBS)
			@echo "$(GREEN) Done..."			

clean:		
			@echo "$(LIGHT_RED) Cleaning objects... $(WHITE)"
			/bin/rm -rf $(OBJS) $(BONUS_OBJS)

fclean: 	clean
			make fclean -C includes/42_libft
			make fclean -C includes/42_ft_printf
			@echo "$(LIGHT_RED) Cleaning all... $(WHITE)"
			/bin/rm -rf $(NAME) $(BONUS_NAME)

re: 		fclean all

.PHONY: 	all clean fclean re bonus

# COLORS
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
LIGHT_GRAY	= \033[0;37m
DARK_GRAY	= \033[0;90m
LIGHT_RED	= \033[0;91m
WHITE		= \033[0;97m

#SETS
BOLD		= \e[0;1m
UNDERLINED	= \e[0;4m
BLINK		= \e[0;5m
