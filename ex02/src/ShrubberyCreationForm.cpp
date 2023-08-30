#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm for " + target, target, 145, 137) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)  : AForm(other) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::performAction() const {
	std::ofstream shrubbery_file((_target + "_shrubbery").c_str());

	if (shrubbery_file.is_open()) {
		shrubbery_file << "    ^^^         ^^^         ^^^\n"
						  "   ^^^^^       ^^^^^       ^^^^^\n"
						  "  ^^^^^^^     ^^^^^^^     ^^^^^^^\n"
						  " ^^^^^^^^^   ^^^^^^^^^   ^^^^^^^^^\n"
						  "^^^^^^^^^^^ ^^^^^^^^^^^ ^^^^^^^^^^^\n"
						  "     |||         |||         |||\n"
						  "     |||         |||         |||\n";
		shrubbery_file.close();
	} else {
		throw OpenFileException();
	}
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw() {
	return "Failed to open shrubbery file";
}
