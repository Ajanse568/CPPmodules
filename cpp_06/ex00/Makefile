SRCS =	ScalarConverter.cpp\
		main.cpp

INCL = ScalarConverter.hpp
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = convert

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)