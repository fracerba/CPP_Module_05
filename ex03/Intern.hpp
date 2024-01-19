#ifndef Intern_HPP
#define Intern_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &intern);
        ~Intern();
        Intern& operator=(const Intern &intern);

        AForm *makeForm(std::string form_name, std::string trgt);
};

#endif