SRCS =	Serializer.cpp\
		main.cpp

INCL = Serializer.hpp
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = serialize

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)