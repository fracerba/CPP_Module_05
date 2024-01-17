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

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeExecTooLowException();
    srand(time(NULL));
    std::cout << "BZZZZZZZZZZZZZZZZ!\n";
    if(rand() % 2)
        std::cout << target <<" has been successfully robotomized \n";
    else
        std::cout << "The robotomy of "<< target <<" failed \n";
}