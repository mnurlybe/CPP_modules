NAME = Base

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Base.cpp
HEADER = Base.hpp A.hpp B.hpp C.hpp

all: $(NAME)

$(NAME):	$(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean