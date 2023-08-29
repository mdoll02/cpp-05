#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, std::string const &target, const int &gradeToSign, const int &gradeToExecute): _name(name), _signed(false), _target(target){
	std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_gradeToSign = gradeToSign;
	this->_gradeToExecute = gradeToExecute;
}

AForm::AForm(const AForm &other) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = other;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_signed = other._signed;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
		this->_target = other._target;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const _NOEXCEPT {
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const _NOEXCEPT {
	return "Grade too low";
}

const char *AForm::AlreadySignedException::what() const _NOEXCEPT {
	return "AForm already signed";
}

const char *AForm::NotSignedException::what() const _NOEXCEPT {
	return "Form is not yet signed";
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	if (this->_signed)
		throw AForm::AlreadySignedException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!this->getSigned())
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	performAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
	os << "AForm name: " << AForm.getName() << ", signed: " << AForm.getSigned() << ", grade to sign: " << AForm.getGradeToSign() << ", grade to execute: " << AForm.getGradeToExecute() << std::endl;
	return os;
}
