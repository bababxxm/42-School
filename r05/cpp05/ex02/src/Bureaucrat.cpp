/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:24:29 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 20:47:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <AForm.hpp>

Bureaucrat::Bureaucrat( void ) :
	_name( "John Doe" ),
	_grade( 150 ) {}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) :
	_name( name ),
	_grade( grade ) {
	checkGrade();
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	_name( other._name ),
	_grade( other._grade ) {}

Bureaucrat::~Bureaucrat( void ) {}

void	Bureaucrat::checkGrade( void ) const {
	if ( _grade > 150 ) {
		throw GradeTooLowException();
	} else if ( _grade < 1 ) {
		throw GradeTooHighException();
	}
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other ) {
	if ( this != &other ) {
		_grade = other._grade;
	}
	return ( *this );
}

const std::string	Bureaucrat::getName( void ) const {
	return ( _name );
}

int Bureaucrat::getGrade( void ) const {
	return ( _grade );
}

void	Bureaucrat::incrementGrade( void ) {
	_grade--;
	checkGrade();
}

void	Bureaucrat::decrementGrade( void ) {
	_grade++;
	checkGrade();
}

void	Bureaucrat::incrementGrade( int nbr ) {
	_grade -= nbr;
	checkGrade();
}

void	Bureaucrat::decrementGrade( int nbr ) {
	_grade += nbr;
	checkGrade();
}

void	Bureaucrat::signForm( AForm& form ) {
	try {
		form.beSigned( *this );
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	} catch ( const std::exception &e ) {
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm( const AForm & form ) {
	try {
		form.execute( *this );
		std::cout << _name << " executed " << form.getName() << "." << std::endl;
	} catch ( const std::exception &e ) {
		std::cout << _name << " couldn't execute " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ( "Grade too high!!" );
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ( "Grade too low!!" );
}

std::ostream&	operator<<( std::ostream &os, const Bureaucrat& bureaucrat ) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ( os );
}
