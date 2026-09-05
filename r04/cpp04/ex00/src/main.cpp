/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:32:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 18:21:52 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <sstream>

int		ToInt(const std::string Str);
void	printTitle(const std::string& title);
void	testCases( int caseID );

void	test1( void );
void	test2( void );
void	test3( void );
void	test4( void );
void	test5( void );

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
		case 4:
			test4(); if ( caseID != 0 ) break;
		case 5:
			test5(); if ( caseID != 0 ) break;
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
	printTitle("TEST 1: VIRTUAL FUNCTION & DESTRUCTOR CHECK");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}

void	test2( void ) {
	printTitle("TEST 2: NON-VIRTUAL FUNCTION BEHAVIOR (WrongAnimal)");
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << wrong_meta->getType() << std::endl;
	std::cout << wrong_cat->getType() << std::endl; 
	wrong_cat->makeSound(); 
	wrong_meta->makeSound();
	delete wrong_cat; 
	delete wrong_meta;
}

void	test3( void ) {
	printTitle("TEST 3: CANONICAL FORM - DEEP COPY CHECK");
	Cat original;
	original.makeSound(); 
	Cat copy_constructor(original);
	std::cout << "Original Cat address: " << &original << std::endl;
	std::cout << "Copied Cat address: " << &copy_constructor << std::endl;

	Dog dog_a;
	Dog dog_b;
	dog_b = dog_a;
	std::cout << "Dog A address: " << &dog_a << std::endl;
	std::cout << "Dog B address: " << &dog_b << std::endl;
}

void	test4( void ) {
	printTitle("TEST 4: ARRAY OF ANIMAL POINTERS");
	const int size = 4;
	Animal* animals[size];
	for (int i = 0; i < size; ++i) {
		animals[i] = (i < size / 2) ? (Animal*)new Dog() : (Animal*)new Cat();
	}

	std::cout << "\n--- Array Sounds (Polymorphic Call) ---\n";
	for (int i = 0; i < size; ++i) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	
	std::cout << "\n--- Cleanup (Requires Virtual Destructor) ---\n";
	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}
}

void	test5( void ) {
	printTitle("TEST 5: DESTRUCTOR TIMING SCOPE CHECK");
	std::cout << "Entering inner scope:\n";
	{
		Cat stack_cat;
		Dog stack_dog;
		stack_cat.makeSound();
		stack_dog.makeSound();
		std::cout << "Stack objects created.\n";
	}
	std::cout << "Exiting inner scope: Stack destructors should have been called.\n";
}

// -----------------------------------------------------------------
//                          HELPER FUNCTIONS
// -----------------------------------------------------------------

int	ToInt(const std::string Str) {
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
