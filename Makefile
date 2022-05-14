NAME	=   cub3d
#LIBRARIES = -lmlx -lm  -L$(MINILIBX_DIRECTORY)
LIBRARIES = -lmlx -framework OpenGL -framework Appkit
LIBFT = libft/libft.a
LIBPATH = libft/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.dylib
MINILIBX_DIRECTORY = ./minilibx_mms_202002199/

SRCS	= main.c parsing.c erroren.c keys.c inits.c raycasting.c movements.c rotate.c draw_and_dist.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
FLAGS	= #-Wall -Wextra -Werror
INCS	= .

%.o : %.c 
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
$(NAME): $(OBJS)
		@$(MAKE) -C $(LIBPATH)
		@$(CC) $(FLAGS) -o $(NAME)  $(OBJS) $(LIBRARIES) $(LIBFT)
		#$(MAKE) -sC $(MINILIBX_DIRECTORY)
		#$(CC) $(FLAGS) -o $(NAME)  $(OBJS) $(LIBRARIES)
		#mv minilibx_mms_202002199/libmlx.dylib .

all: $(NAME)

bonus: all
fclean: clean
	$(RM) $(NAME)
	$(RM) libmlx.dylib

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all bonus clean fclean re .c.o%