#include "Span.hpp"

/* Constructs */

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

Span::~Span( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* Methods */

void Span::addNumber( int n ) {
	if (this->_pos >= this->_size)
		throw Span::FullException();

	this->_container.push_back(n);
	this->_pos++;
}

void Span::addRandNumber( int max, time_t seed ) {
	if (this->_pos >= this->_size)
		throw Span::FullException();

	if (seed == 0)
		seed = time(NULL);
	srand(seed);

	for (int i = 0; i < this->_size - this->_pos; i++) {
		this->_container.push_back(rand() % max);
		this->_pos++;
	}
}

int Span::shortestSpan( void ) const {
	if (this->_pos <= 1)
		throw Span::NoSpanException();

	std::vector<int> tmp(this->_container);
	std::sort(tmp.begin(), tmp.end());

	int min = tmp[1] - tmp[0];

	for (int i = 2; i < this->_pos; i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan( void ) const {
	if (this->_pos <= 1)
		throw Span::NoSpanException();

	std::vector<int> tmp(this->_container);
	std::sort(tmp.begin(), tmp.end());

	return tmp[this->_pos - 1] - tmp[0];
}

/* Getters */

int Span::getSize( void ) const {
	return this->_size;
}

int Span::getPos( void ) const {
	return this->_pos;
}
