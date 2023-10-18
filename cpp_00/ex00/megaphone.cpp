/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbocanci <sbocanci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:06:49 by sbocanci          #+#    #+#             */
/*   Updated: 2023/10/18 11:34:53 by sbocanci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
** Converts the command line arguments to uppercase and prints them.
** If there are no arguments, prints a specific message.
**
** Input
** argc: The number of command line arguments.
** argv: The array of command line arguments.
**
** Flow
** First we check if there are more than 1 command line arguments.
** If yes we iterate over each argument starting from the second.
** For each argument, it iterates over each character.
** Convert each character to uppercase using the std::toupper f().
** Print the uppercase character.
** Print a newline after printing all the characters of an argument.
** If there are no arguments, print the message: 
** "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
**
** Output
** If there are command line arguments, it prints the uppercase version of each argument.**
** If there are no arguments, it prints the message "* LOUD AND UNBEARABLE FEEDBACK NOISE *".
*/
int main(int argc, char **argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            for (int j = 0; argv[i][j]; j++) {
                std::cout << (char)std::toupper(argv[i][j]);
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}

/*
** The program shall behave as follows:

$>./megaphone "shhhhh... I think the students are asleep..."
	SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$>./megaphone
	* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/