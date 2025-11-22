#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "\033[35m" << "Bureaucrat default constructor called."
			  << "\033[m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name) {
	std::cout << "\033[35m" << "Bureaucrat \"" << this->_name << "\" constructor called."
			  << "\033[m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "\033[35m" << "Bureaucrat \"" << this->_name << "\" destructor called."
			  << "\033[m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "\033[35m" << "Bureaucrat \"" << this->_name << "\" Copy constructor called."
			  << "\033[m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "\033[35m" << "Bureaucrat Copy assignment operator called."
			  << "\033[m" << std::endl;
    if (this != &other)
		this->_grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::promote() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::demote() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
}

void Bureaucrat::signForm(AForm &f) const {
	try {
		f.beSigned(*this);
		std::cout << "\033[35m" << this->_name << " signed " << f.getName()
				  << "\033[m" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "\033[35m" << _name << " couldn't sign " << f.getName() << " because "
                  << e.what() << "\033[m" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &f) const {
	try {
		f.execute(*this);
		std::cout << "\033[35m" << this->_name << " execute " << f.getName()
				  << "\033[m" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "\033[35m" << _name << " couldn't execute " << f.getName() << " because "
                  << e.what() << "\033[m" << std::endl;
	}
}

// GradeTooHighException Class
Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*  Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade value is too high.";
}

// GradeTooLowException Class
Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*  Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade value is too low.";
}

// overload insertion(<<)
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
