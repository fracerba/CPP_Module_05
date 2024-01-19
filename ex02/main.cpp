#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat a("Hermes", 36);
    PresidentialPardonForm b("Zoidberg");
    RobotomyRequestForm c("Bender");
    ShrubberyCreationForm d("Home");

    std::cout<<"\n"<<a;
    std::cout<<"\n"<<b;
    std::cout<<"\n"<<c;
    std::cout<<"\n"<<d<<"\n";
    std::cout<<"Signing forms\n";
    a.signForm(b);
    a.signForm(c);
    a.signForm(d);
    std::cout<<"\n"<<b;
    std::cout<<"\n"<<c;
    std::cout<<"\n"<<d<<"\n";
    std::cout<<"Incremeting grades";
    a.setGrade(24);
    std::cout<<"\n"<<a<<"\n";
    std::cout<<"Signing forms\n";
    a.signForm(b);
    a.signForm(c);
    a.signForm(d);
    std::cout<<"\n"<<b;
    std::cout<<"\n"<<c;
    std::cout<<"\n"<<d<<"\n";
    std::cout<<"Executing forms\n";
    a.executeForm(b);
    a.executeForm(c);
    a.executeForm(d);
    std::cout<<"\n"<<b;
    std::cout<<"\n"<<c;
    std::cout<<"\n"<<d<<"\n";
    std::cout<<"Incremeting grades";
    a.setGrade(2);
    std::cout<<"\n"<<a<<"\n";
    std::cout<<"Executing forms\n";
    a.executeForm(b);
    std::cout<<"\n";
}