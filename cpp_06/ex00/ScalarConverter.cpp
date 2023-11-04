/*
** Here we define the ScalarConverter class
**
** It contains a method `convert(std::string const &input)`,
** it takes a string representing literal value of a scalar type.
**
** Example of `char` literal:
** `c`, `a`, ... (any character). If a conversion to char
** is not displayable, we print "Non displayable".
**
** Example of `int` literal:
** `0`, `42`, `-42`, ... (any integer).
**
** Example of `float` literal:
** `0.0f`, `42.0f`, `-42.0f`, `0.42f`, ... (any float).
** Pseudo-literals like `-inff`, `+inff`, `nanf` are handled as well.
**
** Example of `double` literal:
** `0.0`, `4.2`, `-4.2`, `0.42`, ... (any double).
** Pseudo-literals like `-inf`, `+inf`, `nan` are handled as well.
*/