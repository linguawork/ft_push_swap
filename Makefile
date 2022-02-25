NAME		= 	push_swap

SRCS		=  	main.c validity_check1.c validity_check2.c	\
				cmd_push.c cmd_rotate.c cmd_swap.c 			\
				cmd_rev_rotate.c debug.c sort1.c 			\
				sort2.c sort5moreops.c sortmore.c					\

LIBFT		=	libft/

#BONUS_SRCS	= 	ft_split.c 		\

INCLUDES	=	./*.h \
				

OBJS		= 	${SRCS:.c=.o}

BONUS_OBJS	= 	${BONUS_SRCS:.c=.o}

CC			= 	gcc 
RM			= 	rm -rf

CFLAGS		=  -g -Wall -Werror -Wextra -MMD #-fsanitize=address

#.c.o:
%.o: %.c #./push_swap.h ./libft/libft.h
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				@make -C ${LIBFT}
				gcc -o $(NAME) $(OBJS) $(LIBFT)/libft.a

${LIBFT}:		make -C $(LIBFT)

all:			${NAME}

bonus:			${BONUS_OBJS}
				gcc -o ${NAME} $(BONUS_OBJS)

clean:			
				${RM} ${OBJS} $(BONUS_OBJS) *.d
				make clean -C $(LIBFT) 

fclean:			clean 
				${RM} ${NAME}  
				make clean -C ${LIBFT} fclean

re:				fclean all

.PHONY:			all clean fclean re