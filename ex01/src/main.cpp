#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "Colors.hpp"

int main () {


	std::cout << BOLDMAGENTA << "----- Creating new bureaucrat with grade 1 -----" << R << std::endl;
	Bureaucrat b("Harald", 1);
	std::cout << b;
	std::cout << BOLDMAGENTA << "----- Trying to increment grade ----" << R << std::endl;
	try {
		b.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "----- Creating new bureaucrat with grade 150 -----" << R << std::endl;
	Bureaucrat a("Guillaume", 150);
	std::cout << a;
	std::cout << BOLDMAGENTA << "----- Trying to decrement grade ----" << R << std::endl;
	try {
		a.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "----- Creating new bureaucrat with grade 0 -----" << R << std::endl;
	try {
		Bureaucrat no("No", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "----- Creating new bureaucrat with grade 151 -----" << R << std::endl;
	try {
		Bureaucrat yes("Yes", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "----- Creating new form with grade to sign 1 and grade to execute 1 -----" << R << std::endl;
	Form f("Form", 1, 1);
	std::cout << f;
	std::cout << BOLDMAGENTA << "----- Trying to sign form with bureaucrat with grade 1 -----" << R << std::endl;
	b.signForm(f);
	std::cout << f;

	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "----- Trying to sign form which is already signed -----" << R << std::endl;
	b.signForm(f);

	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "----- Trying to sign form with bureaucrat with grade 150 -----" << R << std::endl;
	Bureaucrat c("Günni", 150);
	Form g("Form", 1, 1);
	c.signForm(g);
	std::cout << g;

	std::cout << std::endl;

	return 0;
}