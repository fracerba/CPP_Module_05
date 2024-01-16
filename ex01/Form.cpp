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

Form::Form(const Form &Form) : name(Form.name), sign(Form.sign), sign_grade(Form.sign_grade), exec_grade(Form.exec_grade)
{
	std::cout<<"Form "<<name<<" Copy constructor called\n";
}

Form::~Form()
{
	std::cout<<"Form "<<name<<" Destructor called\n";
}

Form& Form::operator=(const Form &Form)
{
	std::cout<<"Form "<<name<<" Copy assignment operator called\n";
	this->sign = Form.getSigned();
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
    try
	{
		if (b.getGrade() <= this->sign_grade)
			this->sign = true;
		else
		   throw (GradeTooLowException());
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& os, const Form &Form)
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