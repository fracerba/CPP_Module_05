#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string>
#include <exception> 
#include <fstream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool    sign;
        const int   sign_grade;
        const int   exec_grade;
    public:
        Form();
        Form(std::string new_name, int new_grade);
        Form(const Form &Form);
        ~Form();
        Form& operator=(const Form &Form);

        std::string getName() const;
        bool getSigned() const;
        int  getSignGrade() const;
        int  getExecGrade() const;
        void setSigned(bool sign);
        //void setSignGrade(int new_grade);
        //void setExecGrade(int new_grade);
        void beSigned(Bureaucrat b);
};

std::ostream& operator<<(std::ostream& os, const Form &Form);

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