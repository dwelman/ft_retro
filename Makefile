NAME = ft_retro

CC = clang++

NCURSES = -lncurses

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.cpp Entity.cpp GameClock.cpp GameManager.cpp MapElement.cpp MapObject.cpp \
		MovingEntity.cpp Vector2.cpp EntityFactory.cpp ShootingEntity.cpp Enemy.cpp \
		Player.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME):
	@echo "Compiling binaries..."
	@$(CC)  $(CFLAGS) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(NCURSES)
	@echo "Compilation was successful!"
clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@echo "Done cleaning!"
fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"
re: fclean all
