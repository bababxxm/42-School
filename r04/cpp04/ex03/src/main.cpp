/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:26:06 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:37:57 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>
#include <sstream>
#include <string>

// Prototypes
int		ToInt(const std::string Str);
void	printTitle(const std::string& title);
void	testCases( int caseID );

// Test Functions
void	test1( void ); // Basic Deep Copy Check
void	test2( void ); // Array Deletion Test
void	test3( void ); // Deep Copy vs Shallow Copy demonstration

// -----------------------------------------------------------------
//                                MAIN
// -----------------------------------------------------------------

int	main( int ac, char **av ) {
	if ( ac == 1 ) {
		testCases( 0 );
	} else if ( ac == 2 ) {
		int caseID = ToInt( av[1] );
		if ( caseID == - 1) {
			std::cerr << "Error: Invalid argument for test case ID." << std::endl;
			return ( 1 );
		}
		testCases( caseID );
	} else {
		std::cerr << "Usage: " << av[0] << " <test_case_id>" << std::endl;
		return ( 1 );
	}
	return ( 0 );
}

void	testCases( int caseID ) {
	switch ( caseID ) {
		case 0:
		case 1:
			test1(); if ( caseID != 0 ) break;
		case 2:
			test2(); if ( caseID != 0 ) break;
		case 3:
			test3(); if ( caseID != 0 ) break;
		default:
			if ( caseID != 0 ) {
				std::cerr << "Error: Test case ID "
					<< caseID << " does not exist." << std::endl;
			}
			break;
	}
}

// -----------------------------------------------------------------
//                                TESTS
// -----------------------------------------------------------------

void	test1( void ) {
	printTitle("TEST 1: CHARACTER INVENTORY & USE");
	
	ICharacter* me = new Character("me");
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	test2( void ) {
	printTitle("TEST 2: MATERIA CLONING (Deep Copy Check)");
	
	AMateria* ice = new Ice();
	
	AMateria* cloned_ice = ice->clone(); 

	std::cout << "Original Type: " << ice->getType() << " at address: " << ice << std::endl;
	std::cout << "Cloned Type:   " << cloned_ice->getType() << " at address: " << cloned_ice << std::endl;
	
	delete ice;
	delete cloned_ice;
}

void	test3( void ) {
	printTitle("TEST 3: INVENTORY LIMIT, UNEQUIP, AND MEMORY");
	
	ICharacter* hero = new Character("Hero");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	for (int i = 0; i < 4; ++i) {
		hero->equip(src->createMateria("ice"));
	}

	AMateria* overflow = new Cure();
	std::cout << "Attempting to equip a 5th item (should fail)." << std::endl;
	hero->equip(overflow);
	
	hero->unequip(0);
	
	delete hero;
	delete src;
}

// -----------------------------------------------------------------
//                          HELPER FUNCTIONS
// -----------------------------------------------------------------

int ToInt(const std::string Str) {
	int					Value;
	char				Leftover;
	std::istringstream	Iss(Str);

	if (!(Iss >> Value)) return (-1);
	if (Iss >> Leftover) return (-1);

	return (Value);
}

void	printTitle(const std::string& title) {
	const int total_width = 63;
	const int title_length = title.length();
	const int padding = (total_width - title_length) / 2;

	std::cout << "===============================================================" << std::endl;
	for (int i = 0; i < padding; ++i) {
		std::cout << " ";
	}
	std::cout << title << std::endl;
	std::cout << "===============================================================" << std::endl;
}
