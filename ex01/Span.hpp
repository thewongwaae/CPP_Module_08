#pragma once

#include <iostream>
#include <vector>

class Span {
	private:
		int					_size;
		int					_pos;
		std::vector<int>	_container;

		Span( void );

	public:
		Span( int N );
		Span( Span const &copy );
		Span &operator=( Span const &assign );
		~Span( void );

		int getSize( void ) const;
		int getPos( void ) const;
}