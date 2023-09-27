NAME		=	test

SRC			=	main.cpp\
				Serializer.cpp

HDS			=	Data.hpp\
				Serializer.hpp

OBJ			=	$(SRC:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -Wno-unused-parameter -std=c++98

%.o:	%.cpp
		$(CC) ${CFLAGS} -o $@ -c $<

$(NAME)		:	$(OBJ) $(HDS)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf

fclean		:	clean
		@rm -rf $(NAME) $(OBJ) prueba

re			:	fclean	all

.PHONY		:	all clean fclean re