#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute): _name(name), _signed(false){
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
}

Form::Form(const Form &other) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_signed = other._signed;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char *Form::AlreadySignedException::what() const throw() {
	return "Form already signed";
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	if (this->_signed)
		throw Form::AlreadySignedException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form name: " << form.getName() << ", signed: " << form.getSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}

