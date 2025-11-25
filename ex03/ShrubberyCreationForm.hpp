#ifndef _SHRUBBERY_CREATION_FORM_H_
#define _SHRUBBERY_CREATION_FORM_H_

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
	 ShrubberyCreationForm();
	 ShrubberyCreationForm(const std::string &target);
	 ~ShrubberyCreationForm();
	 ShrubberyCreationForm(const ShrubberyCreationForm &other);
	 ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

	 const std::string getTarget() const;
	 void execute(Bureaucrat const & executor) const;

	private:
	 const std::string _target;
};

#endif // _SHRUBBERY_CREATION_FORM_H_
