SRCS =	Bureaucrat.cpp\
		Form.cpp\
		main.cpp

INCL =	Form.hpp\
		Bureaucrat.hpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = Bureaucrat

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)