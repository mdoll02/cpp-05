#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
    Intern();
    
    Intern(const Intern& other);
    
    Intern& operator=(const Intern& other);

    ~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target);

	class FormatNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
    
};

#endif