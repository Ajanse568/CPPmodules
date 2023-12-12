SRCS =	Bureaucrat.cpp\
		PresidentialPardonForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		AForm.cpp\
		main.cpp

INCL =	Bureaucrat.hpp\
		PresidentialPardonForm.hpp\
		ShrubberyCreationForm.hpp\
		RobotomyRequestForm.hpp\
		AForm.hpp

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