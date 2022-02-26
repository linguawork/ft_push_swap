PUSH_SWAP	= push_swap
CHECKER		= checker



PS_SRCS = 	main.c validity_check1.c validity_check2.c	\
			cmd_push.c cmd_rotate.c cmd_swap.c 			\
			cmd_rev_rotate.c debug.c sort1.c 			\
			sort2.c sort5moreops.c sortmore.c					
PS_OBJS = $(PS_SRCS:.c=.o)


LIBFT		=	libft/


INCLUDES	=	./*.h 


C_SRCS	= checker.c validity_check1.c validity_check2.c	\
			cmd_push.c cmd_rotate.c cmd_swap.c 			\
			cmd_rev_rotate.c debug.c sort1.c 			\
			sort2.c sort5moreops.c sortmore.c		
C_OBJS = $(C_SRCS:.c=.o)

PS_HEADER		= push_swap.h


CC = gcc

RM = rm -rf

CFLAGS = -MMD -Wall -Wextra -Werror -g

%.o:%.c	#$(PS_HEADER) 
	@$(CC) $(CFLAGS) -c $< -o $@

# ${LIBFT}:		make -C $(LIBFT)

all: $(PUSH_SWAP)

$(PUSH_SWAP) : $(PS_OBJS)
	make -C ${LIBFT}
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $(PS_OBJS) -o $(PUSH_SWAP) 
	@echo "push_swap is done"

bonus: $(CHECKER)

$(CHECKER) : $(C_OBJS)
	@make -C ${LIBFT}
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $(C_OBJS) -o $(CHECKER) 
	@echo "checker is done"


clean:
		@$(RM) $(PS_OBJS) $(C_OBJS) *.d
		make clean -C $(LIBFT) 
		@echo "clean is done"

fclean: clean
		@$(RM) $(PUSH_SWAP) $(CHECKER)
		make clean -C ${LIBFT} fclean
		@echo "fclean is done"

re: fclean all

.PHONY : all clean fclean re bonus