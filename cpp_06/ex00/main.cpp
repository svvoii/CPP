/*
** This exccercise is about conversion of scalar types.
** The main function takes a string as argument and converts it
** to its corresponding, actual scalar type.
** Then we convert it explicitly to three other data types.
** The result is printed to the standard output.
**
** In case of the string not being a valid scalar type, 
** meaning the conversion is not possible, we print an error message.
*/



/*
** Example of expected output:
```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```
*/
