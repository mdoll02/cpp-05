#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
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
		this->_signed = other._signed;
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::performAction() const {
	int seed = std::clock();
	std::srand(seed);
	int random_nb = std::rand() % 2;

	if (!random_nb)
		std::cout << RED << "robotomy failed" << R << std::endl;
	else
		std::cout << GREEN << _target << " has been robotomized" << R << std::endl;
}

