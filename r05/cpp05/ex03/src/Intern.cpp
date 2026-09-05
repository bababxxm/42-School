/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 04:51:26 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/29 03:42:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& other ) {
    ( void )other;
}

Intern::~Intern( void ) {}

Intern& Intern::operator=( const Intern& other ) {
    ( void )other;
    return ( *this );
}

AForm* makeShrub( const std::string& target ) {
    return ( new ShrubberyCreationForm( target ) );
}

AForm* makeRobo( const std::string& target ) {
    return ( new RobotomyRequestForm( target ) );
}

AForm* makePardon( const std::string& target ) {
    return ( new PresidentialPardonForm( target ) );
}

AForm* Intern::makeForm( const std::string& name, const std::string& target ) {
    const std::string forms[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

    AForm* ( *makeEachForm[] )( const std::string& ) = { makeShrub, makeRobo, makePardon };

    size_t size = sizeof( forms ) / sizeof( forms[0] );

    for ( size_t i = 0; i < size; i++ ) {
        if ( name == forms[i] ) {
            std::cout << "Intern creates " << name << std::endl;
            return ( makeEachForm[i]( target ) );
        }
    }
    throw FormNotFound();
    return ( NULL );
}

const char* Intern::FormNotFound::what() const throw() {
    return ( "Intern couldn't find the form" );
}
