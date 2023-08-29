#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include "Colors.hpp"
#include "Intern.hpp"

int main () {
	std::cout << BOLDYELLOW << "Bureaucrat Joe" << R << std::endl;
	Bureaucrat Joe("Joe", 2);
	std::cout << BOLDYELLOW << "Bureaucrat UselessJoe" << R << std::endl;
	Bureaucrat UselessJoe("UselessJoe", 150);
	std::cout << "Intern Fred" << std::endl;
	Intern Fred;
	std::cout << std::endl;
	AForm *ppf;
	AForm *rrf;
	AForm *scf;
	AForm *noworky;
	std::cout << std::endl;
	try {
		ppf = Fred.makeForm("presidential pardon", "Guillaume");
		rrf = Fred.makeForm("robotomy request", "Bethan");
		scf = Fred.makeForm("shrubbery creation", "Forest");
		noworky = Fred.makeForm("noworky", "Bender");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n"<< Joe << *ppf << *rrf << *scf << std::endl;
	std::cout << BOLDMAGENTA << "Joe tries to execute " << ppf->getName() << R << std::endl;
	Joe.executeForm(*ppf);
	std::cout << std::endl;
	std::cout << BOLDMAGENTA << "Joe tries to sign " << ppf->getName() << R << std::endl;
	Joe.signAForm(*ppf);
	std::cout << std::endl;
	std::cout << BOLDMAGENTA << "Joe tries to execute " << ppf->getName() << R << std::endl;
	Joe.executeForm(*ppf);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << BOLDMAGENTA << "UselessJoe tries to sign " << rrf->getName() << R << std::endl;
	UselessJoe.signAForm(*rrf);
	std::cout << std::endl;
	Joe.signAForm(*rrf);
	std::cout << BOLDMAGENTA << "UselessJoe tries to execute " << rrf->getName() << R << std::endl;
	UselessJoe.executeForm(*rrf);
	std::cout << std::endl;
	std::cout << BOLDMAGENTA << "Joe tries to execute " << rrf->getName() << R << std::endl;
	Joe.executeForm(*rrf);
	Joe.executeForm(*rrf);
	Joe.executeForm(*rrf);
	Joe.executeForm(*rrf);
	Joe.executeForm(*rrf);
	std::cout << std::endl;

	std::cout << BOLDMAGENTA << "Joe tries to sign " << scf->getName() << R << std::endl;
	Joe.signAForm(*scf);
	std::cout << std::endl;
	std::cout << BOLDMAGENTA << "Joe tries to execute " << scf->getName() << R << std::endl;
	Joe.executeForm(*scf);

	std::cout << std::endl;
	delete ppf;
	delete rrf;
	delete scf;
}