#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	std::cout<<"Bureaucrat Default constructor called\n";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade) : name(new_name)
{
	std::cout<<"Bureaucrat "<<name<<" constructor called\n";
	try
	{
		if (new_grade < 1)
			throw (GradeTooHighException());
		if (new_grade > 150)
		   throw (GradeTooLowException());
		this->grade = new_grade;
	}
	catch(GradeTooHighException &e)
	{
		this->grade = 1;
		std::cerr << e.what() << '\n';
	}
	catch(GradeTooLowException &e)
	{
		this->grade = 150;
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout<<"Bureaucrat "<<name<<" Copy constructor called\n";
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat "<<name<<" Destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout<<"Bureaucrat "<<name<<" Copy assignment operator called\n";
	this->grade = bureaucrat.getGrade();
	return(*this);
}

std::string Bureaucrat::getName() const
{
   return (this->name);
}

int Bureaucrat::getGrade() const
{
   return (this->grade);
}

void Bureaucrat::setGrade(int new_grade)
{
	try
	{
		if (new_grade < 1)
			throw (GradeTooHighException());
		if (new_grade > 150)
		   throw (GradeTooLowException());
		this->grade = new_grade;
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

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->grade > 1)
			this->grade--;
		else
			throw (GradeTooHighException());
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->grade < 150)
			this->grade++;
		else
			throw (GradeTooLowException());
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::signForm(Form &a)
{
	if (a.getSigned() == true)
	{
		std::cerr << "Bureaucrat "<<name<<" couldn't sign "<<a.getName()<<" because it's already signed"<< '\n';
		return ;
	}
	try
	{
		a.beSigned(*this);
		std::cout<<"Bureaucrat "<<name<<" signed "<<a.getName()<<"\n";
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat "<<name<<" couldn't sign "<<a.getName()<<" because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName()<<", bureaucrat grade "<<bureaucrat.getGrade()<<"."<<std::endl;
	return (os);
}