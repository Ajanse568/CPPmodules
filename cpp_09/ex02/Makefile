SRCS =	PmergeMe.cpp \
		PmergeMeV.cpp \
		main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -g

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = PmergeMe

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)