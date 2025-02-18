NAME	=	Aform
CC		=	c++
SRCS	=	main.cpp	Bureaucrat.cpp	AForm.cpp PresidentialPardonForm.cpp	RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS	=	$(SRCS:.cpp=.o)
RM		=	rm -f
FLAGS	=	-Werror -Wall	-Wextra -std=c++98

all	: $(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)
%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean	:
			$(RM)	$(OBJS)

fclean	:	clean
			$(RM)	$(NAME)

re		:	fclean all
