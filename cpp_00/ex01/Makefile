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

SRCS =	PhoneBook.cpp\
		Contact.cpp\
		main.cpp

INCLUDES =	PhoneBook.hpp\
			Contact.hpp
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = phonebook

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)
