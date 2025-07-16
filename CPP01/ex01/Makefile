# Nombre del ejecutable
NAME := zombies

# Compilador y flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Colores ANSI
BLUE := \033[34m
GREEN := \033[32m
YELLOW := \033[33m
CYAN := \033[36m
RESET := \033[0m

# Fuentes para este ejercicio
SRC := main.cpp Zombie.cpp zombieHorde.cpp

# Objetos
OBJ := $(SRC:.cpp=.o)

.DEFAULT_GOAL := all

all: $(NAME)
	@printf "$(GREEN)\n✅ Compilación completa$(RESET)\n"

$(NAME): $(OBJ)
	@printf "$(CYAN)\r🔗 Enlazando: $(NAME)                     $(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@printf "$(BLUE)\r⚙️  Compilando: $<                         $(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "$(YELLOW)\r🧹 Limpiando objetos...                $(RESET)\n"
	@rm -f $(OBJ)

fclean: clean
	@printf "$(YELLOW)\r🗑️  Borrando ejecutable...              $(RESET)\n"
	@rm -f $(NAME)
	@printf "$(GREEN)\r✅  Limpieza completa.                  $(RESET)\n"

re: fclean all

run: $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re run