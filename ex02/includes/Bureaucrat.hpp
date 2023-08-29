#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat {
public:

	Bureaucrat(const std::string &name, const int &grade);
    Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& other);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const _NOEXCEPT;
	};

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signAForm(AForm &AForm) const;

	void executeForm(AForm const & form);

private:
	Bureaucrat();
	std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat );

#endif
