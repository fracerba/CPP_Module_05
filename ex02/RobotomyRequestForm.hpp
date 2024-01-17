#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string trgt);
        RobotomyRequestForm(const RobotomyRequestForm &Form);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm &Form);

        void execute(Bureaucrat const & executor) const;
};