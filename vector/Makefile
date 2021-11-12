# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 12:22:15 by fmehdaou          #+#    #+#              #
#    Updated: 2021/11/11 15:19:53 by fmehdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= containers

HEADERS			=  enable_if.hpp \
				   is_integral.hpp \
				   iterator_traits.hpp \
				   iterator.hpp \
				   reverse_iterator.hpp \
				   vector.hpp \
				   viterator.hpp \
				   
					
SRCS			=  main.cpp  \
		  
OBJS			= $(SRCS:.cpp=.o)

FLAGS			= -Wall -Wextra -Werror 

RM				= rm -rf 

%.o : %.cpp $(HEADERS)
	@clang++ ${FLAGS} -o $@ -c $<

.PHONY: clean bonus fclean all re

all:			$(NAME)

$(NAME):		$(OBJS)
				@clang++ ${FLAGS} ${OBJS} -o ${NAME}

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re