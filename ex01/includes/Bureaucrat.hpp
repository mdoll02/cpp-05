#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include "Form.hpp"

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

	void signForm(Form &form) const;

private:
	Bureaucrat();
	std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat );

#endif
