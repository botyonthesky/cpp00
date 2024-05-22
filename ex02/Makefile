NAME 		:= myAccount

CCPP		:= c++
CXXFLAGS 	:= -std=c++98 -g -Wall -Wextra -Werror
CPPFLAGS	+= -I./include

SRC_DIR		:= ./src
OBJ_DIR		:= ./obj

ROOT_SRC	:= tests.cpp \
				Account.cpp 

ROOT_DIR	:= $(SRC_DIR)
ROOT_OBJ	:= $(addprefix $(OBJ_DIR)/, $(ROOT_SRC:.cpp=.o))

SRC			:= $(ROOT_SRC)

OBJ			:= $(ROOT_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CCPP) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

all:		$(NAME) result fclean

$(NAME):	$(OBJ)
	@echo "$(YELLOW) Compiling Account $(CPPFLAGS) ...$(END)"
	@echo "$(GREEN) Account compiled successfully.$(END)"
	@echo "$(YELLOW) Building Account ...$(END)" 
	@$(CCPP) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Account built successfully. $(END)"

result:
	@echo "$(YELLOW) Creating and transfert the output of $(NAME) into result.txt..$(END)"
	@./$(NAME) > result.txt
	@echo "$(GREEN) result.txt created successfully. $(END)"

clean:
	@echo "$(YELLOW) Cleaning object files and dependencies...$(END)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN) Clean complete.$(END)"

fclean: clean
	@echo "$(YELLOW) Cleaning object files, dependencies and removing $(NAME)...$(END)"
	@rm -rf $(NAME)
	@echo "$(GREEN) Full clean complete.$(END)"
	
fullclean: fclean
	@echo "$(YELLOW) Cleaning object files and dependencies...$(END)"
	@rm -rf result.txt
	@echo "$(GREEN) Full clean complete, and deleting file result.txt.$(END)"

re: fclean
	@$(MAKE) --no-print-directory all


YELLOW=\033[0;33m
GREEN=\033[0;32m
END=\033[0m

.PHONY:	all clean fclean fullclean re result

-include $(OBJ:.o=.d)