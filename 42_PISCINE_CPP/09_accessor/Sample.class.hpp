/*
** This usage of Class illustrates
** the usage of accessors and mutators.
*/

#ifndef _SAMPLE_CLASS_HPP_
# define _SAMPLE_CLASS_HPP_

class Sample {

public:

	Sample(void);
	~Sample(void);

	int		getPrivateVariable(void) const;
	void	setPrivateVariable(int value);

private:

	int		_privateVariable;

};

#endif

/*
** Accessors are used to access private members.
** They are also known as getters.
** In this example, the accessor is getPrivateVariable.
**
** Mutators are used to modify private members.
** They are also known as setters.
** In this example, the mutator is setPrivateVariable.
**
** This allows us to control the access to the private members.
** For example, we can add a condition to the mutator to
** prevent the private member from being modified.
** This is also known as data validation.
*/