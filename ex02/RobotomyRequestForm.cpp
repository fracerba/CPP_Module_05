#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
	std::cout<<"RobotomyRequestForm Default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, 72, 45)
{
	std::cout<<"RobotomyRequestForm "<<target<<" constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Form) : AForm(Form.target, 72, 45)
{
	std::cout<<"RobotomyRequestForm "<<target<<" Copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm "<<target<<" Destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &Form)
{
	std::cout<<"RobotomyRequestForm "<<target<<" Copy assignment operator called\n";
    target = Form.target;
	return(*this);
}