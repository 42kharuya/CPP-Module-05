#ifndef _ROBOTOMY_REQUEST_FORM_H_
#define _ROBOTOMY_REQUEST_FORM_H_

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
	 RobotomyRequestForm();
	 RobotomyRequestForm(const std::string &target);
	 ~RobotomyRequestForm();
	 RobotomyRequestForm(const RobotomyRequestForm &other);
	 RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

	 const std::string getTarget() const;
	 void execute(Bureaucrat const & executor) const;

	private:
	 const std::string _target;
};

#endif // _ROBOTOMY_REQUEST_FORM_H_
