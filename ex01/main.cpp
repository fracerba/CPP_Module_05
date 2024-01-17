#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Hermes", 36);
    Form b("Bender", 35, 35);
    Form c;
    Form d("Flexo", 200, 10);

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
    std::cout<<"Incremeting grades\n";
    a.incrementGrade();
    std::cout<<"\n"<<a<<"\n";
    std::cout<<"Signing forms\n";
    a.signForm(b);
    a.signForm(c);
    a.signForm(d);
    std::cout<<"\n"<<b;
    std::cout<<"\n"<<c;
    std::cout<<"\n"<<d<<"\n";
}