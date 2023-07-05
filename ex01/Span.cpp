#include "Span.hpp"

Span::Span( void ) : _size(0), _pos(0) {
	std::cout << "Default constructor called" << std::endl;
}

Span::Span( int N ) : _size(N), _pos(0) {
	this->_container.reserve(N);
	std::cout << "Constructor called with size " << N << std::endl;
}

Span::Span( Span const &copy ) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Span &Span::operator=( Span const &assign ) {
	if (this == &assign)
		return *this;

	this->_size = assign._size;
	this->_pos = assign._pos;
	this->_container = assign._container;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

int Span::getSize( void ) const {
	return this->_size;
}

int Span::getPos( void ) const {
	return this->_pos;
}
