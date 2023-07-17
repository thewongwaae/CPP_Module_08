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

	if (std::find(this->_container.begin(), this->_container.end(), n) != this->_container.end())
		throw Span::DuplicateNumberException();

	this->_container.push_back(n);
	this->_pos++;
}

void Span::addNumber( std::vector<int> const &numbers ) {
	if (this->_pos + static_cast<int>(numbers.size()) > this->_size)
		throw Span::FullException();

	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
		if (std::find(this->_container.begin(), this->_container.end(), *it) != this->_container.end())
			throw Span::DuplicateNumberException();

		this->_container.push_back(*it);
		this->_pos++;
	}
}

void Span::addNumber( int const *begin, int const *end ) {
	if (this->_pos + std::distance(begin, end) > this->_size)
		throw Span::FullException();

	for (int const *it = begin; it != end; ++it) {
		if (std::find(this->_container.begin(), this->_container.end(), *it) != this->_container.end())
			throw Span::DuplicateNumberException();

		this->_container.push_back(*it);
		this->_pos++;
	}
}

void Span::addRandNumber( int max, time_t seed ) {
	if (this->_pos >= this->_size)
		throw Span::FullException();

	if (max <= 0)
		throw Span::InvalidMaxException();

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

	int min = std::abs(this->_container[1] - this->_container[0]);

	for (int i = 2; i < this->_pos; i++) {
		if (std::abs(this->_container[i] - this->_container[i - 1]) < min)
			min = std::abs(this->_container[i] - this->_container[i - 1]);
	}
	return min;
}

int Span::longestSpan( void ) const {
	if (this->_pos <= 1)
		throw Span::NoSpanException();

	int max = this->_container[1] - this->_container[0];

	for (int i = 2; i < this->_pos; i++) {
		if (this->_container[i] - this->_container[i - 1] > max)
			max = this->_container[i] - this->_container[i - 1];
	}
	return abs(max);
}

/* Getters */

std::vector<int> Span::getContainer( void ) const {
	return this->_container;
}

int Span::getSize( void ) const {
	return this->_size;
}

int Span::getPos( void ) const {
	return this->_pos;
}

/* ostream */

std::ostream &operator<<( std::ostream &o, Span const &span ) {
	o << "[";
	for (size_t i = 0; i < span.getContainer().size(); ++i) {
		o << " " << span.getContainer()[i] << " ";
	}
	o << "]" << std::endl;
	return o;
}
