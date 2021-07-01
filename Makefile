# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 15:36:42 by fportalo          #+#    #+#              #
#    Updated: 2021/07/01 14:15:12 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex


all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) pipex.c manage_paths.c handle_errors.c pipex_utils1.c pipex_utils2.c pipex_utils3.c -o $(NAME)

clean: 
	@rm pipex

fclean:
	@rm pipex

re: fclean all

try:
	./pipex infile "ls -la" "wc" outfile