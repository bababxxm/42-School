/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:39:10 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/30 04:01:19 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm( "PresidentialPardonForm", 25, 5 ),
	_target( "Untitled" ) {}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) :
	AForm( "PresidentialPardonForm", 25, 5 ),
	_target( target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm( other ),
	_target( other._target ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}
	return ( *this );
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
