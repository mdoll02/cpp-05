#include "../includes/Bureaucrat.hpp"
#include <iostream>

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

Bureaucrat::Bureaucrat(const Bureaucrat &other) :_name(other._name) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &other) {
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat ) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
