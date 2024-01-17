#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
    target = "Default";
	std::cout<<"PresidentialPardonForm Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string trgt) : AForm(trgt, 25, 5)
{
    target = trgt;
	std::cout<<"PresidentialPardonForm "<<target<<" constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Form) : AForm(Form.target, 25, 5)
{
    target = Form.target;
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

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeExecTooLowException();
    std::cout << target << " has been pardoned by Zafod Beeblebrox\n";
}