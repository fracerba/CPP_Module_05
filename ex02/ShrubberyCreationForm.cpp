#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 25, 5)
{
	std::cout<<"ShrubberyCreationForm Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(target, 25, 5)
{
	std::cout<<"ShrubberyCreationForm "<<target<<" constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Form) : AForm(Form.target, 25, 5)
{
	std::cout<<"ShrubberyCreationForm "<<target<<" Copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm "<<target<<" Destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Form)
{
	std::cout<<"ShrubberyCreationForm "<<target<<" Copy assignment operator called\n";
    target = Form.target;
	return(*this);
}