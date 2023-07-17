#include "Span.hpp"

int main()
{
	{
		// Test constructor with size
		Span a(5);
		std::cout << "Size of a: " << a.getSize() << std::endl;
		std::cout << "Pos of a: " << a.getPos() << std::endl;

		// Test addNumber function
		try
		{
			a.addNumber(1);
			a.addNumber(2);
			a.addNumber(4);
			a.addNumber(3);
			a.addNumber(5);
			a.addNumber(6); // This will throw an exception because the Span is already full
		}
		catch (std::exception &e)
		{
			std::cerr << std::endl << e.what() << std::endl;
		}

		try
		{
			std::cout << a << std::endl;
			std::cout << "Shortest span of a: " << a.shortestSpan() << std::endl;
			std::cout << "Longest span of a: " << a.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << std::endl << e.what() << std::endl;
		}
		std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;

		// Test addRandNumber function
		try
		{
			Span b(10000);
			b.addRandNumber(10000, time(NULL));
			std::cout << b << std::endl;
			std::cout << "shortest span is " << b.shortestSpan() << std::endl;
			std::cout << "longest span is " << b.longestSpan() << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << std::endl << e.what() << std::endl;
		}
	}
	return (0);
}