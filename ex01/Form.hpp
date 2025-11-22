#ifndef _FORM_H_
#define _FORM_H_

#include <string>
#include <iostream>
class Bureaucrat;

class Form
{
	public:
	 Form();
	 Form(const std::string &name, const int &signGrade, const int &execGrade);
	 ~Form();
	 Form(const Form &other);
	 Form& operator=(const Form &other);

	 void beSigned(const Bureaucrat &b);

	 std::string getName() const;
	 bool getSigned() const;
	 int getSignGrade() const;
	 int getExecGrade() const;

	 class GradeTooHighException : public std::exception {
	 	public:
		 GradeTooHighException();
		 ~GradeTooHighException() throw();
		 const char* what() const throw();
	 };

	 class GradeTooLowException : public std::exception {
	 	public:
		 GradeTooLowException();
		 ~GradeTooLowException() throw();
		 const char* what() const throw();
	 };

	 class FormIsAlreadySigned : public std::exception {
	 	public:
		 FormIsAlreadySigned();
		 ~FormIsAlreadySigned() throw();
		 const char* what() const throw();
	 };

	private:
	 const std::string _name;
	 bool _signed;
	 const int _signGrade;
	 const int _execGrade;
	 void _checkGrade(const int &grade);
};

std::ostream &operator<<(std::ostream &os, Form const &f);

#endif // _FORM_H_
