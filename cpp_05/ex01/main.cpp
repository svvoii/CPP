#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat miranda("Miranda", 150);
		std::cout << std::endl;		

        Form form1("Form1", 50, 50);
        Form form2("Form2", 1, 1);
		std::cout << std::endl;		

		std::cout << "Calling overloaded << operator to print the Form info:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

		std::cout << "Calling `signForm()':" << std::endl;
        bob.signForm(form1);
        miranda.signForm(form2);

		std::cout << "Calling overloaded << operator to print the Form info:" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
