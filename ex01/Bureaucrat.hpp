#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception> 
#include <fstream>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string new_name, int new_grade);
        Bureaucrat(const Bureaucrat &Bureaucrat);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &Bureaucrat);

        std::string getName() const;
        int getGrade() const; 
        void setGrade(int new_grade);
        void incrementGrade();
        void decrementGrade();
        void signForm(Form a);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &Bureaucrat);

class GradeTooHighException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Grade too high, the highest is 1");
        }
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Grade too low, the lowest is 150");
        }
};


#endif