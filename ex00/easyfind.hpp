#pragma once

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return "Not found";
		}
};

template< typename T >

typename T::iterator easyfind(T &array, int n)
{
	typename T::iterator it = std::find(array.begin(), array.end(), n);
	if (it == array.end())
		throw NotFoundException();
	return it;
}