/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:20:31 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 22:07:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) :
	_name( "Untitled" ),
	_isSigned( false ),
	_gradeToSign( 1 ),
	_gradeToExecute( 1 ) {}

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) :
	_name( name ),
	_isSigned( false ),
	_gradeToSign( gradeToSign ),
	_gradeToExecute( gradeToExecute ) {
	checkGrade();
}

Form::Form( const Form& other ) :
	_name( other._name ),
	_isSigned( other._isSigned ),
	_gradeToSign( other._gradeToSign ),
	_gradeToExecute( other._gradeToExecute ) {}

Form::~Form( void ) {}

void	Form::checkGrade( void ) const {
	if ( _gradeToSign > 150 || _gradeToExecute > 150 ) {
		throw GradeTooLowException();
	} else if ( _gradeToSign < 1 || _gradeToExecute < 1) {
		throw GradeTooHighException();
	}
}

const std::string&	Form::getName( void ) const {
	return ( _name );
}

bool	Form::getIsSigned( void ) const {
	return ( _isSigned );
}

int	Form::getGradeToSign( void ) const {
	return ( _gradeToSign );
}

int	Form::getGradeToExecute( void ) const {
	return ( _gradeToExecute );
}

Form&	Form::operator=( const Form& other ) {
	if ( this != &other ) {
		_isSigned = other._isSigned;
	}
	return ( *this );
}

void	Form::beSigned( const Bureaucrat& bureaucrat ) {
	if ( _isSigned ) {
		throw FormAlreadySignedException();
	} else if ( bureaucrat.getGrade() > _gradeToSign )  {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ( "Grade too high!!" );
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ( "Grade too low!!" );
}

const char*	Form::FormAlreadySignedException::what() const throw() {
	return ( "Form is already signed" );
}

std::ostream&	operator<<( std::ostream &os, const Form& form ) {
	os << "Form: " << form.getName()
		<< " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< " | Grade Required: Sign " << form.getGradeToSign()
		<< ", Exec " << form.getGradeToExecute();
	return ( os );
}
