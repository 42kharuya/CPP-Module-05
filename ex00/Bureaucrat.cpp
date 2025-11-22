#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name) {
	std::cout << "Bureaucrat \"" << this->_name << "\" constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat \"" << this->_name << "\" destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat \"" << this->_name << "\" Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat Copy assignment operator called." << std::endl;
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
