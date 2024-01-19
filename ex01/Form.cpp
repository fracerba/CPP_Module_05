#include "Form.hpp"

Form::Form() : name("Default"), sign_grade(150), exec_grade(150)
{
	std::cout<<"Form Default constructor called\n";
    this->sign = false;
}

Form::Form(std::string new_name, int grade_sign, int grade_exec) : name(new_name), sign_grade(grade_sign), exec_grade(grade_exec)
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

Form::Form(const Form &form) : name(form.name), sign(form.sign), sign_grade(form.sign_grade), exec_grade(form.exec_grade)
{
	std::cout<<"Form "<<name<<" Copy constructor called\n";
}

Form::~Form()
{
	std::cout<<"Form "<<name<<" Destructor called\n";
}

Form& Form::operator=(const Form &form)
{
	std::cout<<"Form "<<name<<" Copy assignment operator called\n";
	this->sign = form.getSigned();
	return(*this);
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getSigned() const
{
    return (this->sign);
}

int  Form::getSignGrade() const
{
    return (this->sign_grade);
}

int  Form::getExecGrade() const
{
    return (this->exec_grade);
}

void Form::setSigned(bool new_sign)
{
    this->sign = new_sign;
}

void Form::beSigned(Bureaucrat &b)
{
	if (this->sign == true)
        return ;
	if (b.getGrade() <= this->sign_grade)
		this->sign = true;
	else
		throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Form &form)
{
	os<<"Form Name: "<<form.getName()<<std::endl;
    os<<"Form Sign Grade: "<<form.getSignGrade()<<std::endl;
    os<<"Form Execute Grade: "<<form.getExecGrade()<<std::endl;
    os<<"Form Signed: ";
    if (form.getSigned() == true)
        os<<"YES"<<std::endl;
    else
        os<<"NO"<<std::endl;
    return (os);
}