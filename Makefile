NAME		= ft_containers
CXX 		= clang++
CXXFLAGS	= -g -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf

SRCS	 	= test/main.cpp test/test_vector.cpp test/test_stack.cpp test/test_map.cpp \
				test/test_pair.cpp test/test_algorithm.cpp test/test_reverse_iterator.cpp \
				test/test_set.cpp test/test_subject.cpp

OBJS 		= $(SRCS:.cpp=.o)

define run_ft
	$(CXX) $(CXXFLAGS) -D NS=ft -o $@ ${SRCS}
endef

define run_stl
	$(CXX) $(CXXFLAGS) -D NS=std -o $@ ${SRCS}
endef

define run_diff
	\time -o time_stl.txt -f "Program: %C\nTotal time: %E\nUser Mode (s) %U\nKernel Mode (s) %S\nCPU: %P" ./bin_stl 2> /dev/null 1> stl.log
	\time -o time_ft.txt -f "Program: %C\nTotal time: %E\nUser Mode (s) %U\nKernel Mode (s) %S\nCPU: %P" ./bin_ft 2> /dev/null 1> ft.log
	diff stl.log ft.log >diff.log || [ $$? -eq 1 ]
endef

all:	 	bin_ft bin_stl diff

bin_stl: 	
			@$(call run_stl)

bin_ft: 	
			@$(call run_ft)

diff:
			@$(run_diff)

clean:	

fclean:		clean
			$(RM) ./bin_ft ./bin_stl
			${RM} ft.log stl.log diff.log
			${RM} time_ft.txt time_stl.txt

re:			fclean  all

.PHONY:		all clean fclean re diff bin_stl bin_ft