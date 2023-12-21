SRCS =	main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror 

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = RPN

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)