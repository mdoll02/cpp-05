#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
public:
	explicit PresidentialPardonForm(std::string const &target);
    
    PresidentialPardonForm(const PresidentialPardonForm& other);
    
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    ~PresidentialPardonForm();

	virtual void performAction() const;

private:
	PresidentialPardonForm();
    
};

#endif