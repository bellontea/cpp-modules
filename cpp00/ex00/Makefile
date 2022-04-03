NAME		=	megaphone

SRC 		=	$(shell ls *cpp)
OBJ			=	$(SRC:.cpp=.o)
OBJS_DIR 	= 	objects/
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))



CC			=	c++ -std=c++98
CFLAGS		=	-Wall -Wextra -Werror



all 				: $(NAME)

$(NAME) 			: $(OBJS)
					$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(OBJS_DIR)%.o		:	%.cpp
					mkdir -p $(OBJS_DIR)
					c++ $(CFLAGS) -c $< -o $@

clean				:
					rm -rf $(OBJS_DIR)

fclean				:	clean
					rm -rf $(NAME)
re : clean all