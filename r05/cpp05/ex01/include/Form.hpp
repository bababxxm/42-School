/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:20:33 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/29 03:47:14 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

    void checkGrade( void ) const;

public:
    Form( void );
    Form( const std::string& name, int gradeToSign, int gradeToExecute );
    Form( const Form& other );
    ~Form( void );

    const std::string& getName( void ) const;
    bool getIsSigned( void ) const;
    int getGradeToSign( void ) const;
    int getGradeToExecute( void ) const;

    Form& operator=( const Form& other );
    void beSigned( const Bureaucrat& bureaucrat );

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormAlreadySignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif
