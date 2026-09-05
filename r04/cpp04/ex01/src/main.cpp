/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:26:06 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:26:28 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp" // New requirement for deep copy

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
	printTitle("TEST 1: CANONICAL FORM & DEEP COPY BASIC");
	
	Dog original_dog;
	Dog copied_dog = original_dog;
	
	std::cout << "Original Dog address: " << &original_dog << std::endl;
	std::cout << "Copied Dog address: " << &copied_dog << std::endl;
	
	Cat cat_a;
	Cat cat_b;
	cat_b = cat_a;
}

void	test2( void ) {
	printTitle("TEST 2: ARRAY OF BRAINS (Memory Integrity Check)");
	const int size = 4;
	Animal* animals[size];
	
	for (int i = 0; i < size; ++i) {
		animals[i] = (i % 2 == 0) ? (Animal*)new Dog() : (Animal*)new Cat();
	}

	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}
}

void	test3( void ) {
	printTitle("TEST 3: DEMONSTRATING DEEP COPY NEED (Expected Behavior)");
	Dog* dog_a = new Dog();
	
	Dog dog_b = *dog_a;
	
	std::cout << "Dog A thought (Should be different if deep copied)." << std::endl;
	std::cout << "Dog B thought (Should hold 'First thought.')." << std::endl;
	
	delete dog_a;
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
