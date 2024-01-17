#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
    target = "Default";
	std::cout<<"ShrubberyCreationForm Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string trgt) : AForm(trgt, 145, 137)
{
    target = trgt;
	std::cout<<"ShrubberyCreationForm "<<target<<" constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Form) : AForm(Form.target, 145, 137)
{
    target = Form.target;
	std::cout<<"ShrubberyCreationForm "<<target<<" Copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm "<<target<<" Destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Form)
{
	std::cout<<"ShrubberyCreationForm "<<target<<" Copy assignment operator called\n";
    target = Form.target;
	return(*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    std::ofstream file;
    std::string name;

    name = target + "_shrubbery";
    if (!this->getSigned())
        throw NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeExecTooLowException();
    file.open(name.c_str());
    file << "              .     .  .      +     .      .          .\n";
    file << "     .       .      .     #       .           .\n";
    file << "        .      .         ###            .      .      .\n";
    file << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
    file << "          .      . \"####\"###\"####\"  .\n";
    file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
    file << "  .             \"#########\"#########\"        .        .\n";
    file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
    file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n";
    file << "                .\"##\"#####\"#####\"##\"           .      .\n";
    file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
    file << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
    file << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n";
    file << "            .     \"      000      \"    .     .\n";
    file << "       .         .   .   000     .        .       .\n";
    file << ".. .. ..................O000O........................ ...... ...\n";
    file.close();
}