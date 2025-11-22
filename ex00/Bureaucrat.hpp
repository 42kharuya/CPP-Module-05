#ifndef _BUREAUCRAT_H_
#define _BUREAUCRAT_H_

#include <iostream>
#include <string>

class Bureaucrat
{
	public:
	 Bureaucrat();
	 Bureaucrat(const std::string &name, const int &grade);
	 ~Bureaucrat();
	 Bureaucrat(const Bureaucrat &other);
	 Bureaucrat& operator=(const Bureaucrat &other);

	 std::string getName() const;
	 int getGrade() const;

	 void promote();
	 void demote();

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

	private:
	 const std::string _name;
	 int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif // _BUREAUCRAT_H_
