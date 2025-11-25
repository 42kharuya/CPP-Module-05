#ifndef _AFORM_H_
#define _AFORM_H_

#include <string>
#include <iostream>
class Bureaucrat;

class AForm
{
	public:
	 AForm();
	 AForm(const std::string &name, const int &signGrade, const int &execGrade);
	 virtual ~AForm();
	 AForm(const AForm &other);
	 AForm& operator=(const AForm &other);

	 void beSigned(const Bureaucrat &b);
	 void checkExecutable(Bureaucrat const & executor) const;
	 virtual void execute(Bureaucrat const & executor) const = 0;

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

	 class FormNotSignedException : public std::exception {
	 	public:
		 FormNotSignedException();
		 ~FormNotSignedException() throw();
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

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif // _AFORM_H_
