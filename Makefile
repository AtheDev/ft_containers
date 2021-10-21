NAME = containers

SRCS = main.cpp test/test_algorithm.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp
			$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
