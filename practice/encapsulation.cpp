#include <iostream>

using	std::string;

int	char_is_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	is_alpha(string str)
{
	int	i = -1;

	while (str[++i])
		if (!char_is_alpha(str[i]))
			return (0);
	return (1);
}

class	Employee {
private:
	string	Name;
	string	Company;
	int			Age;
public:
	void	setName(string	name) {
		if (is_alpha(name))
			Name = name;
		else
			std::cout << "Name should contain alphabetical letters only!" << std::endl;
	}
	string	getName() {
		return Name;
	}
	
	void	setCompany(string company) {
		Company = company;
	}
	string	getCompany() {
		return Company;
	}

	void	setAge(int age) {
		if (age > 17)
			Age = age;
		else
			std::cout << "Age cannot be less than 18." << std::endl;
	}
	int	getAge() {
		return Age;
	}

	void	introduceYourself() {
		std::cout << "Name:\t" << Name << std::endl;
		std::cout << "Cmpy:\t" << Company << std::endl;
		std::cout << "Age:\t" << Age << std::endl;
	}

	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
};

int	main()
{
	Employee employee1 = Employee("Serge", "42-Born2Code", 35);
	employee1.introduceYourself();

	employee1.setAge(19);
	employee1.setName("Apolo16");
	std::cout << employee1.getName() << " is " << employee1.getAge() << " years old now." << std::endl;
}
