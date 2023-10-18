/*
**
*/

#ifndef _SAMPLE1_CLASS_HPP_
# define _SAMPLE1_CLASS_HPP_

class Sample1 {

public:
	int		num_var;

	Sample1(void);
	~Sample1(void);

	void	function(void) const;

};

struct Sample2 {

	int		num_var;

	Sample2(void);
	~Sample2(void);

	void	function(void) const;

};

#endif

/*
** Declaratio and initalization of both Class and Struct
** can be the same.
**
** The difference between a class and a struct is that
** the members of a `class` are private by default, while
** the members of a `struct` are public by default.
**
** If we need the members of a `class` to be public/visible,
** we need to specify it using the keyword `public`.
*/