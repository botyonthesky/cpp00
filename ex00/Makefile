NAME 		:= megaphone

CCPP		:= c++
CXXFLAGS 	:= -std=c++98 -g -Wall -Wextra -Werror
CPPFLAGS	+= -I./include
CPPFLAGS	+= -MMD -MP -MF $(@:.o=.d)

SRC_DIR		:= ./src
OBJ_DIR		:= ./obj

ROOT_SRC	:= megaphone.cpp

ROOT_DIR	:= $(SRC_DIR)
ROOT_OBJ	:= $(addprefix $(OBJ_DIR)/, $(ROOT_SRC:.cpp=.o))

SRC			:= $(ROOT_SRC)

OBJ			:= $(ROOT_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CCPP) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo "$(YELLOW) Compiling Megaphone $(CXXFLAGS) ...$(END)"
	@echo "$(GREEN) Megaphone compiled successfully.$(END)"
	@echo "$(YELLOW) Building Megaphone ...$(END)" 
	@$(CCPP) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Megaphone built successfully. $(END)"

clean:
	@echo "$(YELLOW) Cleaning object files and dependencies...$(END)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN) Clean complete.$(END)"

fclean: clean
	@echo "$(YELLOW) Cleaning object files, dependencies and removing $(NAME)...$(END)"
	@rm -rf $(NAME)
	@echo "$(GREEN) Full clean complete.$(END)"
	
re: fclean
	@$(MAKE) --no-print-directory all


YELLOW=\033[0;33m
GREEN=\033[0;32m
END=\033[0m

.PHONY:	all clean fclean re

-include $(OBJ:.o=.d)