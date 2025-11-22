#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("")
{
	std::cout << "\033[34m" << "PresidentialPardonForm default constructor called."
			  << "\033[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[34m" << "PresidentialPardonForm constructor called."
			  << "\033[m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\033[34m" << "PresidentialPardonForm destructor called."
			  << "\033[m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "\033[34m" << "PresidentialPardonForm Copy constructor called."
			  << "\033[m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "\033[34m" << "PresidentialPardonForm Copy assignment operator called."
			  << "\033[m" << std::endl;
    if (this != &other) {
		AForm::operator=(other);
	}
    return *this;
}

const std::string PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	checkExecutable(executor);
    std::cout << "\033[34m" << getTarget() << " has been pardoned by Zaphod Beeblebrox."
              << "\033[m" << std::endl;
}
