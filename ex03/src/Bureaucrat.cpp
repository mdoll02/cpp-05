#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include "Colors.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if(_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signAForm(AForm &AForm) const {
	if (AForm.getSigned())
		std::cout << this->_name << " cannot sign " << AForm.getName() << " because it is already signed" << std::endl;
	else if (this->_grade > AForm.getGradeToSign())
		std::cout << this->_name << " cannot sign " << AForm.getName() << " because his grade is too low" << std::endl;
	else {
		std::cout << this->_name << " signs " << AForm.getName() << std::endl;
		AForm.beSigned(*this);
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &ex) {
		std::cerr << RED << this->getName() << " couldn't execute form because " << ex.what() << R << std::endl;
	}
	catch (AForm::NotSignedException &ex) {
		std::cerr << RED << this->getName() << " couldn't execute form because " << ex.what() << R << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat ) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
