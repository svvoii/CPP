#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 150);

        Form form1("Form1", 50, 50);
        Form form2("Form2", 1, 1);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        john.signForm(form1);
        jane.signForm(form2);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
