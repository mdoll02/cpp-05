#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <random>
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm for " + target, target, 72, 45) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)  : AForm(other) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_signed = other._signed;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::performAction() const {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> distribution(0,1);

	int rand = distribution(gen);

	if (!rand)
		std::cout << RED << "robotomy failed" << R << std::endl;
	else
		std::cout << GREEN << _target << " has been robotomized" << R << std::endl;
}

