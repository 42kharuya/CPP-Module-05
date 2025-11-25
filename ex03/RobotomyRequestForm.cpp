#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "\033[31m" << "RobotomyRequestForm default constructor called."
			  << "\033[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[31m" << "RobotomyRequestForm constructor called."
			  << "\033[m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\033[31m" << "RobotomyRequestForm destructor called."
			  << "\033[m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "\033[31m" << "RobotomyRequestForm Copy constructor called."
			  << "\033[m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "\033[31m" << "RobotomyRequestForm Copy assignment operator called."
			  << "\033[m" << std::endl;
    if (this != &other) {
		AForm::operator=(other);
	}
    return *this;
}

const std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecutable(executor);
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
    std::cout << "Bzzzzzz... Vrrrrrr... (drilling noises)" << std::endl;
    if (std::rand() % 2) {
        std::cout << "\033[31m" << this->getTarget() << " has been robotomized successfully."
                  << "\033[m" << std::endl;
    } else {
        std::cout << "\033[31m" << "Failed to robotomize " << this->getTarget() << "."
				  << "\033[m" << std::endl;
    }
}
