#include <iostream>

using	std::string;

int	char_is_alpha(int c);
int	is_alpha(string str);

/* Abstract class. Contract. Interface */
class	AbstractEmployee {
	virtual void	AskFofPromotion() = 0;
};

/* ..signing the contract "AbstractEmployee" which should have to have its implementation */
class	Employee:AbstractEmployee {
private:
	string	Company;
	int			Age;
protected:
	string	Name;
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

	void	AskFofPromotion() {
		if (Age > 29)
			std::cout << Name << ", you are promoted! " << std::endl;
		else
			std::cout << Name << ", no promotion for you. " << std::endl;
	}

	//void	Work() {
	/* ..by making this method virtual and invoking it from main 
	it will first check if there is another implementation of Work method in children classes if they are used in main.. */
	virtual void	Work() {
		std::cout << Name << " is checking emails and task backlog." << std::endl;
	}
};

/* 
** creating new class which will inherit all things from Employee class 
** if we want to access methods and abstract parts from the parent class we use "public" keyword in declaration (after :)
*/
class	Developer : public Employee {
public:
	string	FavProgrammingLanguage;
	Developer(string name, string company, int age, string favProgrammingLanguage)
		:Employee(name, company, age)
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	void	FixBug() {
		std::cout << getName() << " fixing bugs using " << FavProgrammingLanguage << std::endl;
	}
	void	Work() {
		std::cout << Name << " is writing " << FavProgrammingLanguage << " code.." << std::endl;
	}
};

class	Teacher : public Employee {
public:
	string	Subject;
	void	PrepareLesson() {
		std::cout << Name << " is preparing a " << Subject << " lesson." << std::endl;
	}
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	{
		Subject = subject;
	}
	void	Work() {
		std::cout << Name << " is having a " << Subject << " lesson.." << std::endl;
	}
};

int	main()
{
	Developer dev = Developer("Serge", "42-Born2Code", 35, "C++");
	Teacher t = Teacher("Olha", "42 School", 32, "History");

	dev.Work();
	t.Work();

	std::cout << std::endl;

	Employee* e1 = &dev;
	Employee* e2 = &t;

	e1->Work();
	e2->Work();
}

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
