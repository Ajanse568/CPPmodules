SRCS =	Classes.cpp\
		main.cpp

INCL = Classes.hpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = classes

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)