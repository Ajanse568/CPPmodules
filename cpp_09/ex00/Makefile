SRCS =	BitcoinExchange.cpp \
		main.cpp

INCL = BitcoinExchange.hpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++20 -g

COMPILE = $(CPP) $(CFLAGS)
RM = rm -f

NAME = btc

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	$(COMPILE) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean $(NAME)