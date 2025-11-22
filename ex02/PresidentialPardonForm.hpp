#ifndef _PRESIDENTIAL_PARDON_FORM_H_
#define _PRESIDENTIAL_PARDON_FORM_H_

#include <fstream>
#include <cstdlib>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
	 PresidentialPardonForm();
	 PresidentialPardonForm(const std::string &target);
	 ~PresidentialPardonForm();
	 PresidentialPardonForm(const PresidentialPardonForm &other);
	 PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

	 const std::string getTarget() const;
	 void execute(const Bureaucrat &executor) const;

	private:
	 const std::string _target;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif // _PRESIDENTIAL_PARDON_FORM_H_
