NAME		= ft_containers
CXX 		= clang++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -g
RM 			= rm -rf

SRCS	 	= test/main.cpp test/test_vector.cpp test/test_stack.cpp test/test_map.cpp \
				test/test_pair.cpp test/test_algorithm.cpp test/test_reverse_iterator.cpp
OBJS 		= $(SRCS:.cpp=.o)

define run_ft
	$(CXX) $(CXXFLAGS) -D NS=ft -o $@ ${SRCS}
endef

define run_stl
	$(CXX) $(CXXFLAGS) -D NS=std -o $@ ${SRCS}
endef

define run_time_ok
	sed -i 's/std::cin.get()/\/\/std::cin.get()/g' ./test/test_vector.cpp
endef

define run_time_ko
	sed -i 's/\/\/std::cin.get()/std::cin.get()/g' ./test/test_vector.cpp
endef

define run_diff
	./script.sh
endef

all:	 	bin_ft bin_stl

bin_stl: 	
			@$(call run_stl)

bin_ft: 	
			@$(call run_ft)

$(OBJS): 	%.o: %.cpp
			$(CXX) $(CXXFLAGS) -o $@ -c $<

diff:
		@$(call run_diff)

clean:	
			$(RM) $(OBJS)


fclean:		clean
			$(RM) ./bin_ft ./bin_stl

re:			fclean  all

.PHONY:		all clean fclean re