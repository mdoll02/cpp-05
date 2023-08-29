#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int id;

	for(id = 0; id < 3; id++) {
		if (formName == forms[id])
			break;
	}
	switch (id) {
		case 0: {
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 1: {
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		}
		case 2: {
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		}
		default: {
			throw FormatNotFoundException();
		}
	}
}

const char *Intern::FormatNotFoundException::what() const throw() {
	return "Unknown form name";
}
