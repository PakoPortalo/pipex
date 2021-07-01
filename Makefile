# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 15:36:42 by fportalo          #+#    #+#              #
#    Updated: 2021/07/01 13:52:49 by fportalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex


all: $(NAME) libft

$(NAME):
	@$(CC) $(FLAGS) pipex.c manage_paths.c handle_errors.c -L libft/ -l ft -g -o$(NAME)

clean: 
	@rm pipex

fclean:
	@rm pipex

re: fclean all

try:
	./pipex infile "ls -la" "wc" outfile