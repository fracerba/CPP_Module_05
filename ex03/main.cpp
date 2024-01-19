#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat a("Hermes", 36);
    Intern f;

    std::cout<<"\n";
    AForm *b = f.makeForm("presidential pardon", "Zoidberg");
    std::cout<<"\n";
    AForm *c = f.makeForm("robotomy request", "Bender");
    std::cout<<"\n";
    AForm *d = f.makeForm("shrubbery creation", "Home");
    std::cout<<"\n";
    AForm *e = f.makeForm("shrubbery destruction", "Home");

    std::cout<<"\n"<<a;
    std::cout<<"\n"<<*b;
    std::cout<<"\n"<<*c;
    std::cout<<"\n"<<*d<<"\n";
    std::cout<<"Incremeting grades\n";
    a.setGrade(24);
    std::cout<<a<<"\n";
    std::cout<<"Signing forms\n";
    a.signForm(*b);
    a.signForm(*c);
    a.signForm(*d);
    std::cout<<"\n"<<*b;
    std::cout<<"\n"<<*c;
    std::cout<<"\n"<<*d<<"\n";
    std::cout<<"Executing forms\n";
    a.executeForm(*b);
    a.executeForm(*c);
    a.executeForm(*d);
    std::cout<<"\nIncremeting grades";
    a.setGrade(2);
    std::cout<<"\n"<<a<<"\n";
    std::cout<<"Executing forms\n";
    a.executeForm(*b);
    std::cout<<"\n";

    delete b;
    delete c;
    delete d;
    delete e;
    std::cout<<"\n";
}