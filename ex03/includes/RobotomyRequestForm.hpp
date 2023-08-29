#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
public:
	explicit RobotomyRequestForm(std::string const &target);
    
    RobotomyRequestForm(const RobotomyRequestForm& other);
    
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    ~RobotomyRequestForm();

	virtual void performAction() const;

private:
	RobotomyRequestForm();
    
};

#endif