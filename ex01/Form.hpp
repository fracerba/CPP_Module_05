#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string>
#include <exception> 
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                sign;
        const int           sign_grade;
        const int           exec_grade;
    public:
        Form();
        Form(std::string new_name, int grade_sign, int grade_exec);
        Form(const Form &Form);
        ~Form();
        Form& operator=(const Form &Form);

        std::string getName() const;
        bool getSigned() const;
        int  getSignGrade() const;
        int  getExecGrade() const;
        void setSigned(bool new_sign);
        void beSigned(Bureaucrat &b);
    
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too high");
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too low");
            }
    };
};

std::ostream& operator<<(std::ostream& os, const Form &Form);

#endif