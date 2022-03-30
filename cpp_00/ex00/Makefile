SRCS = megaphone.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = megaphone

all: $(NAME)

$(NAME):
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)
