#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void testAFormList() {
	std::cout << "\033[32m" << "\n//////////////////////////////// testAFormList ////////////////////////////////" << "\033[m" << std::endl;

	{
		std::cout << "\n----------------------------- Normal Execute -----------------------------" << std::endl;

		try {
			Bureaucrat executor("Ken", 3);
			AForm *formList[3];

			formList[0] = new ShrubberyCreationForm("Target1");
			formList[1] = new RobotomyRequestForm("Target2");
			formList[2] = new PresidentialPardonForm("Target3");

			std::cout << std::endl;
			executor.signForm(*formList[0]);
			executor.signForm(*formList[1]);
			executor.signForm(*formList[2]);

			std::cout << std::endl;
			executor.executeForm(*formList[0]);

			std::cout << std::endl;
			executor.executeForm(*formList[1]);

			std::cout << std::endl;
			executor.executeForm(*formList[2]);

			std::cout << std::endl;
			delete formList[0];
			delete formList[1];
			delete formList[2];
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

static void testPresidentialPardonForm() {
	std::cout << "\033[32m" << "\n//////////////////////////////// PresidentialPardonForm ////////////////////////////////" << "\033[m" << std::endl;

	{
		std::cout << "\n----------------------------- Normal Execute -----------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 2);
			PresidentialPardonForm f("Target");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.signForm(f);

			std::cout << std::endl;
			b.executeForm(f);

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n-------------------------- Cannot Execute --------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 5);
			PresidentialPardonForm f("Target/");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.executeForm(f);

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

static void testRobotomyRequestForm() {
	std::cout << "\033[32m" << "\n//////////////////////////////// RobotomyRequestForm ////////////////////////////////" << "\033[m" << std::endl;

	{
		std::cout << "\n----------------------------- Normal Execute -----------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 20);
			RobotomyRequestForm f("Target");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.signForm(f);

			std::cout << std::endl;
			for (int i = 1; i <= 10; ++i) {
				std::cout << i << ":" <<  std::endl;
				b.executeForm(f);
				std::cout << std::endl;
			}

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n-------------------------- Cannot Execute --------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 20);
			RobotomyRequestForm f("Target/");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.executeForm(f);

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

static void testShrubberyCreationForm() {
	std::cout << "\033[32m" << "\n//////////////////////////////// ShrubberyCreationForm ////////////////////////////////" << "\033[m" << std::endl;

	{
		std::cout << "\n----------------------------- Normal Execute -----------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 20);
			ShrubberyCreationForm f("Target");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.signForm(f);
			b.executeForm(f);

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n-------------------------- Cannot Open File(\"/\") --------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 20);
			ShrubberyCreationForm f("Target/");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.signForm(f);
			b.executeForm(f);

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n-------------------------- Cannot Execute --------------------------" << std::endl;

		try {
			Bureaucrat b("Ken", 20);
			ShrubberyCreationForm f("Target/");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << f << std::endl;
			std::cout << "target: "<< f.getTarget() << std::endl;

			std::cout << std::endl;
			b.executeForm(f);

			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

int main() {
	std::cout << "\033[35m" << "PINK" << "\033[m" << ": Bureaucrat Class" << std::endl;
	std::cout << "\033[33m" << "YELLOW" << "\033[m" << ": AForm Class" << std::endl;
	std::cout << "\033[36m" << "CYAN" << "\033[m" << ": ShrubberyCreationForm Class" << std::endl;
	std::cout << "\033[31m" << "RED" << "\033[m" << ": RobotmyRequestForm Class" << std::endl;
	std::cout << "\033[34m" << "PURPLE" << "\033[m" << ": PresidentialPardonForm Class" << std::endl;

	testShrubberyCreationForm();
	std::cout << std::endl;

	testRobotomyRequestForm();
	std::cout << std::endl;

	testPresidentialPardonForm();
	std::cout << std::endl;

	testAFormList();
	std::cout << std::endl;


}
