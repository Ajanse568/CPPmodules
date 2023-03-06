SRCS =	ScalarCaster.cpp\
		main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -v
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = scalarcaster

all: $(NAME)

$(NAME): $(SRCS)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)