#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "\033[33m" << "Form default constructor called."
			  << "\033[m" << std::endl;
}

Form::Form(const std::string &name, const int &signGrade, const int &execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
	std::cout << "\033[33m" << "Form \"" << this->_name << "\" constructor called."
			  << "\033[m" << std::endl;
	this->_checkGrade(signGrade);
	this->_checkGrade(execGrade);
}

Form::~Form() {
	std::cout << "\033[33m" << "Form \"" << this->_name << "\" destructor called."
			  << "\033[m" << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "\033[33m" << "Form \"" << this->_name << "\" Copy constructor called."
			  << "\033[m" << std::endl;
}

Form& Form::operator=(const Form &other) {
	std::cout << "\033[33m" << "Form Copy assignment operator called."
			  << "\033[m" << std::endl;
    if (this != &other)
		this->_signed = other._signed;
    return *this;
}

void Form::_checkGrade(const int &grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const { return this->_name; }

bool Form::getSigned() const { return this->_signed; }

int Form::getSignGrade() const { return this->_signGrade; }

int Form::getExecGrade() const { return this->_execGrade; }

void Form::beSigned(const Bureaucrat &b) {
	if (this->getSigned() == true)
		throw Form::FormIsAlreadySigned();
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

// GradeTooHighException Class
Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char*  Form::GradeTooHighException::what() const throw() {
	return "The grade value is too high.";
}

// GradeTooLowException Class
Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char*  Form::GradeTooLowException::what() const throw() {
	return "The grade value is too low.";
}

// FormIsAlreadySigned Class
Form::FormIsAlreadySigned::FormIsAlreadySigned() {}

Form::FormIsAlreadySigned::~FormIsAlreadySigned() throw() {}

const char*  Form::FormIsAlreadySigned::what() const throw() {
	return "the form has already been signed.";
}

// overload insertion(<<)
std::ostream &operator<<(std::ostream &os, Form const &f) {
    os << "Form name: " << f.getName()
       << ", is signed: " << (f.getSigned() ? "true" : "false")
       << ", grade to sign: " << f.getSignGrade()
       << ", grade to execute: " << f.getExecGrade() << ".";
    return os;
}
