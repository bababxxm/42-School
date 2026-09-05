/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:39:10 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:18:32 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm( "ShrubberyCreationForm", 145, 137 ),
	_target( "Untitled_shrubbery" ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) :
	AForm( "ShrubberyCreationForm", 145, 137 ),
	_target( target + "_shrubbery" ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	AForm( other ),
	_target( other._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}
	return ( *this );
}

void	ShrubberyCreationForm::execute( Bureaucrat const& executor ) const {
	(void)executor;
	std::ofstream	shrubbery( _target.c_str() );
	if ( !shrubbery ) {
		throw FileNotCreated();
	}
	shrubbery << "      o                               o         " << std::endl;
	shrubbery << "     q_p                 o           q_p        " << std::endl;
	shrubbery << "     /o\\                q_p          /*\\      " << std::endl;
	shrubbery << "    /o *\\       _       /o\\         /o o\\    " << std::endl;
	shrubbery << "   / o o \\    _|_|_    /o *\\       /o  o \\   " << std::endl;
	shrubbery << "  / o *  o\\ \\  (\") Y  /* o o\\     /  o*  o\\" << std::endl;
	shrubbery << " /o  * o o \\ '(_:_)' /o * *  \\   /* o   *  \\ " << std::endl;
	shrubbery << "'----. .----'(_____)'---. .---' '----. .----'   " << std::endl;
	shrubbery.close();
}

const char*	ShrubberyCreationForm::FileNotCreated::what() const throw() {
	return ( "Cannot create shrubbery file." );
}
