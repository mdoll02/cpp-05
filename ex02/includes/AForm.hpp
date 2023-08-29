#ifndef AForm_HPP
# define AForm_HPP

#include <string>

class Bureaucrat;

class AForm {
public:
	AForm(std::string const &name, std::string const &target, int const &gradeToSign, int const &gradeToExecute);
    AForm(const AForm& other);
	virtual ~AForm() = 0;

    AForm& operator=(const AForm& other);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class AlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	const std::string &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const;
	virtual void performAction() const = 0;

protected:
	AForm();
	std::string _name;
	bool _signed;
	int _gradeToSign;
	int _gradeToExecute;
	std::string _target;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif

