/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:20:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/30 03:06:21 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) :
	_name( "Untitled" ),
	_isSigned( false ),
	_gradeToSign( 1 ),
	_gradeToExecute( 1 ) {}

AForm::AForm( const std::string& name, int gradeToSign, int gradeToExecute ) :
	_name( name ),
	_isSigned( false ),
	_gradeToSign( gradeToSign ),
	_gradeToExecute( gradeToExecute ) {
	checkGrade();
}

AForm::AForm( const AForm& other ) :
	_name( other._name ),
	_isSigned( other._isSigned ),
	_gradeToSign( other._gradeToSign ),
	_gradeToExecute( other._gradeToExecute ) {}

AForm::~AForm( void ) {}

void	AForm::checkGrade( void ) const {
	if ( _gradeToSign > 150 || _gradeToExecute > 150 ) {
		throw GradeTooLowException();
	} else if ( _gradeToSign < 1 || _gradeToExecute < 1) {
		throw GradeTooHighException();
	}
}

void	AForm::checkExecutable( const Bureaucrat& executor ) const {
	if ( !_isSigned ) {
		throw FormNotSignedException();
	} else if ( executor.getGrade() > _gradeToExecute ) {
		throw GradeTooLowException();
	}
}

const std::string&	AForm::getName( void ) const {
	return ( _name );
}

bool	AForm::getIsSigned( void ) const {
	return ( _isSigned );
}

int	AForm::getGradeToSign( void ) const {
	return ( _gradeToSign );
}

int	AForm::getGradeToExecute( void ) const {
	return ( _gradeToExecute );
}

AForm&	AForm::operator=( const AForm& other ) {
	if ( this != &other ) {
		_isSigned = other._isSigned;
	}
	return ( *this );
}

void	AForm::beSigned( const Bureaucrat& bureaucrat ) {
	if ( _isSigned ) {
		throw FormAlreadySignedException();
	} else if ( bureaucrat.getGrade() > _gradeToSign )  {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ( "Grade too high!!" );
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ( "Grade too low!!" );
}

const char*	AForm::FormAlreadySignedException::what() const throw() {
	return ( "Form is already signed" );
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return ( "Form not signed!!" );
}

std::ostream&	operator<<( std::ostream &os, const AForm& form ) {
	os << "Form: " << form.getName()
		<< " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< " | Grade Required: Sign " << form.getGradeToSign()
		<< ", Exec " << form.getGradeToExecute();
	return ( os );
}
