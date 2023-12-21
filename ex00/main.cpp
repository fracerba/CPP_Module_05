#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b("Hermes", 36);

    std::cout<<"\n"<<a;
    std::cout<<b<<"\n";
    std::cout<<"Decremeting grades\n";
    a.decrementGrade();
    b.decrementGrade();
    std::cout<<"\n"<<a;
    std::cout<<b<<"\n";
    std::cout<<"Incremeting grades\n";
    a.incrementGrade();
    b.incrementGrade();
    std::cout<<"\n"<<a;
    std::cout<<b<<"\n";
    std::cout<<"Setting grades\n";
    a.setGrade(0);
    b.setGrade(1);
    std::cout<<"\n"<<a;
    std::cout<<b<<"\n";
    std::cout<<"Incremeting grades\n";
    a.incrementGrade();
    b.incrementGrade();
    std::cout<<"\n"<<a;
    std::cout<<b<<"\n";
}