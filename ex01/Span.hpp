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

		void addNumber( int n );
		void addRandNumber( int max, time_t seed = 0);
		int shortestSpan( void ) const;
		int longestSpan( void ) const;

		int getSize( void ) const;
		int getPos( void ) const;

	class FullException : public std::exception {
		public:
			virtual const char *what( void ) const throw() {
				return "Container is full";
			}
	};

	class NoSpanException : public std::exception {
		public:
			virtual const char *what( void ) const throw() {
				return "No span to find";
			}
	};
};