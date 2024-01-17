#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &intern);
        ~Intern();
        Intern& operator=(const Intern &Form);

        AForm *makeForm(std::string form_name, std::string trgt);
};