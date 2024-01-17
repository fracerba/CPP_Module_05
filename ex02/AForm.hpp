#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include <exception> 
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                sign;
        const int           sign_grade;
        const int           exec_grade;
    public:
        AForm();
        AForm(std::string new_name, int grade_sign, int grade_exec);
        AForm(const AForm &AForm);
        ~AForm();
        AForm& operator=(const AForm &AForm);

        std::string getName() const;
        bool getSigned() const;
        int  getSignGrade() const;
        int  getExecGrade() const;
        void setSigned(bool new_sign);
        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
    
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

std::ostream& operator<<(std::ostream& os, const AForm &AForm);

#endif