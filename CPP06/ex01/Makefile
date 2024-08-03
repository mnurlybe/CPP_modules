NAME = Serializer

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Serializer.cpp
HEADER = Serializer.hpp

all: $(NAME)

$(NAME):	$(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean