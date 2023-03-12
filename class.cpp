#include <iostream>

class	Employee {
public:
	std::string	Name;
	std::string	Company;
	int			Age;

	void	introduceYourself() {
		std::cout << "Name:\t" << Name << std::endl;
		std::cout << "Cmpy:\t" << Company << std::endl;
		std::cout << "Age:\t" << Age << std::endl;
	}

	Employee(std::string name, std::string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
};

int	main()
{
	Employee employee1 = Employee("Serge", "42-Born2Code", 35);
	employee1.introduceYourself();
}
