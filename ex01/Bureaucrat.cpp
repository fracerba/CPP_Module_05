#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	std::cout<<"Default constructor called\n";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade) : name(new_name)
{
	std::cout<<"Parametrical constructor called\n";
	try
	{
		if (new_grade < 1)
			throw (GradeTooHighException());
		if (new_grade > 150)
		   throw (GradeTooHighException());
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

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat)
{
	std::cout<<"Copy constructor called\n";
	*this = Bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &Bureaucrat)
{
	std::cout<<"Copy assignment operator called\n";
	//this->name = Bureaucrat.getName();
	this->grade = Bureaucrat.getGrade();
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
		   throw (GradeTooHighException());
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat &Bureaucrat)
{
	os << Bureaucrat.getName()<<", bureaucrat grade "<<Bureaucrat.getGrade()<<"."<<std::endl;
	return (os);
}