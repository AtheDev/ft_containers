#include <iostream>
#include <string>
#include <deque>

#include "main.hpp"

/*#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace NS = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif*/

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

void debug_print_btree_structure_(rb_node *current, int space){
    if ( current != NULL ){
        space += 10;
        debug_print_btree_structure_(current->right, space);
        std::cout << std::endl;
        for ( int _ = 0 ; _ < space ; _++ ){ std::cout << " "; }
        std::cout << "( " << current->data.first << " : " << current->data.second  << ", " << ((current->color == BLACK) ? "B" : "R") << " )" << std::endl;
        debug_print_btree_structure_(current->left, space);
    }
}

#define COUNT 5 //(MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public NS::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->_c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename NS::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	NS::vector<std::string> vector_str;
	NS::vector<int> vector_int;
	NS::stack<int> stack_int;
	NS::vector<Buffer> vector_buffer;
	NS::stack<Buffer, std::deque<int> > stack_deq_buffer;
	//NS::map<int, int> map_int;
  NS::pair <int,int> foo;
  NS::pair <int,int> bar;

  foo = NS::make_pair (10,20);
  bar = NS::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << NS_NAME << ": foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << NS_NAME << ": bar: " << bar.first << ", " << bar.second << '\n';

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	NS::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	/*for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(NS::make_pair(rand(), rand()));
	}*/

	/*int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		NS::map<int, int> copy = map_int;
	}*/
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}