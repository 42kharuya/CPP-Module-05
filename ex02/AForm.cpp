#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "\033[33m" << "AForm default constructor called."
			  << "\033[m" << std::endl;
}

AForm::AForm(const std::string &name, const int &signGrade, const int &execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade){
	std::cout << "\033[33m" << "AForm \"" << this->_name << "\" constructor called."
			  << "\033[m" << std::endl;
	this->_checkGrade(signGrade);
	this->_checkGrade(execGrade);
}

AForm::~AForm() {
	std::cout << "\033[33m" << "AForm \"" << this->_name << "\" destructor called."
			  << "\033[m" << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "\033[33m" << "AForm \"" << this->_name << "\" Copy constructor called."
			  << "\033[m" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	std::cout << "\033[33m" << "AForm Copy assignment operator called."
			  << "\033[m" << std::endl;
    if (this != &other)
		this->_signed = other._signed;
    return *this;
}

void AForm::_checkGrade(const int &grade) {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const { return this->_name; }

bool AForm::getSigned() const { return this->_signed; }

int AForm::getSignGrade() const { return this->_signGrade; }

int AForm::getExecGrade() const { return this->_execGrade; }

void AForm::beSigned(const Bureaucrat &b) {
	if (this->getSigned() == true)
		throw AForm::FormIsAlreadySigned();
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void AForm::checkExecutable(const Bureaucrat &b) const {
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (b.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
}

// GradeTooHighException Class
AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char*  AForm::GradeTooHighException::what() const throw() {
	return "The grade value is too high.";
}

// GradeTooLowException Class
AForm::GradeTooLowException::GradeTooLowException() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char*  AForm::GradeTooLowException::what() const throw() {
	return "The grade value is too low.";
}

// FormNotSignedException Class
AForm::FormNotSignedException::FormNotSignedException() {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char*  AForm::FormNotSignedException::what() const throw() {
	return "The form has not been signed yet.";
}

// FormIsAlreadySigned Class
AForm::FormIsAlreadySigned::FormIsAlreadySigned() {}

AForm::FormIsAlreadySigned::~FormIsAlreadySigned() throw() {}

const char*  AForm::FormIsAlreadySigned::what() const throw() {
	return "the form has already been signed.";
}

// overload insertion(<<)
std::ostream &operator<<(std::ostream &os, AForm const &f) {
    os << "AForm name: " << f.getName()
       << ", is signed: " << (f.getSigned() ? "true" : "false")
       << ", grade to sign: " << f.getSignGrade()
       << ", grade to execute: " << f.getExecGrade() << ".";
    return os;
}
