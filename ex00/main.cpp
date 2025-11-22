#include "Bureaucrat.hpp"

int main() {
	{
		std::cout << "\033[32m" << "------------------ Normal ------------------" << "\033[m" << std::endl;

		try {
			Bureaucrat b1;
			Bureaucrat b2("Ken", 75);

			std::cout << std::endl;
			std::cout << b1 << std::endl;
			std::cout << b2 << std::endl << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\033[32m" << "\n------------------ Grade too low ------------------" << "\033[m" << std::endl;
		try {
			Bureaucrat b("Ken", 1234567);

			std::cout << std::endl;
			std::cout << b << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\033[32m" << "\n------------------ Grade too high ------------------" << "\033[m" << std::endl;
		try {
			Bureaucrat b("Ken", 0);

			std::cout << std::endl;
			std::cout << b << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\033[32m" << "\n------------------ Promote ------------------" << "\033[m" << std::endl;
		try {
			Bureaucrat b("Ken", 2);

			std::cout << std::endl;
			std::cout << b << std::endl << std::endl;

			b.promote();
			std::cout << b << std::endl;

			b.promote();
			std::cout << b << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\033[32m" << "\n------------------ Demote ------------------" << "\033[m" << std::endl;
		try {
			Bureaucrat b("Ken", 2);

			std::cout << std::endl;
			std::cout << b << std::endl << std::endl;

			b.promote();
			std::cout << b << std::endl;

			b.promote();
			std::cout << b << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}
