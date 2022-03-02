PUSH_SWAP	= push_swap
CHECKER		= checker


SRCS = 		main.c main2.c validity_check1.c validity_check2.c validity_check3.c	\
			cmd_push.c cmd_rotate.c cmd_swap.c 			\
			cmd_rev_rotate.c debug.c sort1.c 			\
			sort2.c sort5moreops.c sortmore.c					
OBJS = $(SRCS:.c=.o)

LIBFT		=	libft/

INCLUDES	=	./*.h 


BONUS_SRCS	= 	bonus_main.c validity_check1.c validity_check2.c validity_check3.c	\
				cmd_push.c cmd_rotate.c cmd_swap.c 			\
				cmd_rev_rotate.c debug.c sort1.c 			\
				sort2.c sort5moreops.c sortmore.c		
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

PS_HEADER		= push_swap.h

CC = gcc

RM = rm -rf

CFLAGS = -MMD -Wall -Wextra -Werror -g

%.o:%.c	$(PS_HEADER) 
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(PUSH_SWAP)

$(PUSH_SWAP) : $(OBJS)
	make -C ${LIBFT}
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $(PUSH_SWAP) 
	@echo "make OK, push_swap ready to run"

bonus: $(CHECKER)

$(CHECKER) : $(BONUS_OBJS)
	@make -C ${LIBFT}
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $(BONUS_OBJS) -o $(CHECKER) 
	@echo "make bonus OK: checker ready to run"


clean:
		@$(RM) $(OBJS) $(BONUS_OBJS) *.d
		make clean -C $(LIBFT) 
		@echo "make clean OK"

fclean: clean
		@$(RM) $(PUSH_SWAP) $(CHECKER)
		make clean -C ${LIBFT} fclean
		@echo "make fclean OK"

re: fclean all

.PHONY : all clean fclean re bonus