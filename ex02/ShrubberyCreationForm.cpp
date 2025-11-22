#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "\033[36m" << "ShrubberyCreationForm default constructor called."
			  << "\033[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[36m" << "ShrubberyCreationForm constructor called."
			  << "\033[m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\033[36m" << "ShrubberyCreationForm destructor called."
			  << "\033[m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "\033[36m" << "ShrubberyCreationForm Copy constructor called."
			  << "\033[m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "\033[36m" << "ShrubberyCreationForm Copy assignment operator called."
			  << "\033[m" << std::endl;
    if (this != &other) {
		AForm::operator=(other);
	}
    return *this;
}

const std::string ShrubberyCreationForm::getTarget() const { return this->_target; }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	checkExecutable(executor);
	std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file)
		throw std::runtime_error("Cannot open \"" + this->_target + "_shrubbery" + "\".");
    file << "       /_\\\n"
       	 << "      / _ \\\n"
         << "     / _ _ \\\n"
         << "    / _ _ _ \\\n"
         << "   / _ _ _ _ \\\n"
         << "  / _ _ _ _ _ \\\n"
         << " / _ _ _ _ _ _ \\\n"
         << "/ _ _ _ _ _ _ _ \\\n"
         << "       ||\n"
         << "       ||\n";
    file.close();
}
