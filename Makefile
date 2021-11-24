NAME		= ft_containers
CXX 		= clang++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -g
RM 			= rm -rf

SRCS	 	= main.cpp test/test_vector.cpp
OBJS 		= $(SRCS:.cpp=.o)

define run_ft
	$(CXX) $(CXXFLAGS) -D NS=ft -o $@ ${SRCS}
endef

define run_stl
	$(CXX) $(CXXFLAGS) -D NS=std -o $@ ${SRCS}
endef

all:	 	bin_ft bin_stl

bin_stl: 	
			@$(call run_stl)

bin_ft: 	
			@$(call run_ft)

$(OBJS): 	%.o: %.cpp
			$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:	
			$(RM) $(OBJS)


fclean:		clean
			$(RM) ./bin_ft ./bin_stl

re:			fclean all

.PHONY:		all clean fclean re