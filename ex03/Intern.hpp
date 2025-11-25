#ifndef _INTERN_H_
#define _INTERN_H_

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

    	AForm *makeForm(const std::string &name, const std::string &target);

		class FormNotExistException: public std::exception {
			const char *what() const throw();
		};

	private:
		struct FormType {
			const char*	formName;
			AForm* (*createForm)(const std::string&);
		};
		static FormType _FormType[];
};

#endif // _INTERN_H_
