SRCS =	Serializer.cpp\
		main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror 

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = serialize

all: $(NAME)

$(NAME): $(SRCS)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)