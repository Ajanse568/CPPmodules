# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ajanse <ajanse@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/23 15:15:30 by ajanse        #+#    #+#                  #
#    Updated: 2022/11/23 15:22:37 by ajanse        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =	Account.cpp\
		tests.cpp

INCLUDES =	Account.hpp
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = account

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)
