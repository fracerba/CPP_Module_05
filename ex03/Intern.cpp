#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<"Intern constructor called\n";
}

Intern::Intern(const Intern &intern)
{
	std::cout<<"Intern Copy constructor called\n";
	*this = intern;
}

Intern::~Intern()
{
	std::cout<<"Intern Destructor called\n";
}

Intern& Intern::operator=(const Intern &intern)
{
	std::cout<<"Intern Copy assignment operator called\n";
	*this = intern;
	return(*this);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = -1;

	while (++i < 3)
	{
		if (form_name == forms[i])
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form_name << " form " << target <<std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates " << form_name << " form " << target <<std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << form_name << " form " << target <<std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cerr << "Error! There is no Form with such name" << std::endl;
		break;
	}
	return (NULL);
}