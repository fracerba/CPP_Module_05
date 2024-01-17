#include "AForm.hpp"

AForm::AForm() : name("Default"), sign_grade(150), exec_grade(150)
{
	std::cout<<"Form Default constructor called\n";
    this->sign = false;
}

AForm::AForm(std::string new_name, int grade_sign, int grade_exec) : name(new_name), sign_grade(grade_sign), exec_grade(grade_exec)
{
	std::cout<<"Form "<<name<<" constructor called\n";
    this->sign = false;
	try
	{
		if (sign_grade < 1)
			throw (GradeTooHighException());
		if (sign_grade > 150)
		   throw (GradeTooLowException());
		if (exec_grade < 1)
			throw (GradeTooHighException());
		if (exec_grade > 150)
		   throw (GradeTooLowException());
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::AForm(const AForm &Form) : name(Form.name), sign(Form.sign), sign_grade(Form.sign_grade), exec_grade(Form.exec_grade)
{
	std::cout<<"Form "<<name<<" Copy constructor called\n";
}

AForm::~AForm()
{
	std::cout<<"Form "<<name<<" Destructor called\n";
}

AForm& AForm::operator=(const AForm &Form)
{
	std::cout<<"Form "<<name<<" Copy assignment operator called\n";
	this->sign = Form.getSigned();
	return(*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSigned() const
{
    return (this->sign);
}

int  AForm::getSignGrade() const
{
    return (this->sign_grade);
}

int  AForm::getExecGrade() const
{
    return (this->exec_grade);
}

void AForm::setSigned(bool new_sign)
{
    this->sign = new_sign;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (this->sign == true)
		return ;
	if (b.getGrade() <= this->sign_grade)
		this->sign = true;
	else
		throw (GradeSignTooLowException());
}

std::ostream& operator<<(std::ostream& os, const AForm &Form)
{
	os<<"Form Name: "<<Form.getName()<<std::endl;
    os<<"Form Sign Grade: "<<Form.getSignGrade()<<std::endl;
    os<<"Form Execute Grade: "<<Form.getExecGrade()<<std::endl;
    os<<"Form Signed: ";
    if (Form.getSigned() == true)
        os<<"YES"<<std::endl;
    else
        os<<"NO"<<std::endl;
    return (os);
}