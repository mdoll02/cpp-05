#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
public:
	Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute);
    Form(const Form& other);
	~Form();

    Form& operator=(const Form& other);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const _NOEXCEPT;
	};
	class AlreadySignedException : public std::exception {
	public:
		virtual const char* what() const _NOEXCEPT;
	};

	const std::string &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bureaucrat);

private:
	Form();
	std::string _name;
	bool _signed;
	int _gradeToSign;
	int _gradeToExecute;



};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif

