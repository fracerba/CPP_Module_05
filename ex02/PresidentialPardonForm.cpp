#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
	std::cout<<"PresidentialPardonForm Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(target, 25, 5)
{
	std::cout<<"PresidentialPardonForm "<<target<<" constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Form) : AForm(Form.target, 25, 5)
{
	std::cout<<"PresidentialPardonForm "<<target<<" Copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm "<<target<<" Destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &Form)
{
	std::cout<<"PresidentialPardonForm "<<target<<" Copy assignment operator called\n";
    target = Form.target;
	return(*this);
}