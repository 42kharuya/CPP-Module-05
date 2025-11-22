#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\033[35m" << "PINK" << "\033[m" << ": Bureaucrat Class" << std::endl;
	std::cout << "\033[33m" << "YELLOW" << "\033[m" << ": Form Class" << std::endl;

	{
		std::cout << "\033[32m" << "\n------------------ Can Sign ------------------" << "\033[m" << std::endl;

		try {
			Bureaucrat b("Ken", 20);
			Form f("bill1", 50, 50);

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl << std::endl;

			b.signForm(f);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\033[32m" << "\n------------------ Too Low ------------------" << "\033[m" << std::endl;

		try {
			Bureaucrat b("Ken", 100);
			Form f("bill1", 50, 50);

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl << std::endl;

			b.signForm(f);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\033[32m" << "\n------------------ Already Signed ------------------" << "\033[m" << std::endl;

		try {
			Bureaucrat b1("Bob", 25);
			Bureaucrat b2("Mike", 25);
			Form f("bill1", 50, 50);

			std::cout << std::endl;
			std::cout << b1 << std::endl;
			std::cout << b2 << std::endl;
			std::cout << f << std::endl << std::endl;

			b1.signForm(f);
			b2.signForm(f);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}
