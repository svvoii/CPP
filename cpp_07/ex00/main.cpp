#include "whatever.hpp"

/*
** The following main function is given in the subject.
**
** The expected return is:

a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2

*/

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}

/*
** `::` is a scope resolution operator.
** When used in front of a function `::swap` it means that
** the function is not a member of a class, but a global function.
**
** Here `::swap` is being called from the global namespace.
** This ensures that the correct function is called, avoiding
** conflicts with `std::swap` function.
**
** Namespaces are used to avoid naming conflicts by grouping
** entities like classes, objects and functions under a name.
** The global namespace is the namespace that holds 
** global functions and variables.  
*/
