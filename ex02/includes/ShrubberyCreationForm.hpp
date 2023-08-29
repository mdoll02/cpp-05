#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
public:
	explicit ShrubberyCreationForm(std::string const &target);
    
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    ~ShrubberyCreationForm();

	class OpenFileException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	virtual void performAction() const;

private:
	ShrubberyCreationForm();
    
};

#endif