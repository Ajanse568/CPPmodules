SRCS =	ClapTrap.cpp\
		ScavTrap.cpp\
		main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = ClapTrap

all: $(NAME)

$(NAME): $(SRCS)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)