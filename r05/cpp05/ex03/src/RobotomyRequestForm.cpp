/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:39:10 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:18:28 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm( "RobotomyRequestForm", 72, 45 ),
	_target( "Untitled"  ) {}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) :
	AForm( "RobotomyRequestForm", 72, 45 ),
	_target( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) :
	AForm( other ),
	_target( other._target ) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if ( this != &other ) {
		AForm::operator=( other );
		_target = other._target;
	}
	return ( *this );
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	(void)executor;
	std::cout << "* drilling noises *" << std::endl;
	if ( std::rand() % 2 ) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
	}
}
