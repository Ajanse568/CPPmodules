# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ajanse <ajanse@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/23 15:15:13 by ajanse        #+#    #+#                  #
#    Updated: 2022/11/23 15:20:07 by ajanse        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = megaphone

all: $(NAME)

$(NAME): $(SRCS)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)
