#include <stack>
#include <iostream>

template <typename T>

class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;


		MutantStack( void ) : std::stack<T>() {}

		MutantStack( const MutantStack<T> &copy ) : std::stack<T>(copy) {}

		MutantStack<T> &operator=( const MutantStack<T> &assign ) {
			if (this != &assign)
				*this = assign;
			return (*this);
		}

		~MutantStack( void ) {}

		/* Iterator functions */

		iterator begin( void ) {
			return std::stack<T>::c.begin();
		}

		iterator end( void ) {
			return std::stack<T>::c.end();
		}
}; 