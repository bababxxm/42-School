/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:24:22 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:29:02 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

	private:

		const std::string	_name;
		int					_grade;

		void	checkGrade( void ) const;

	public:

		Bureaucrat( void );
		Bureaucrat( const std::string& name, int grade );
		Bureaucrat( const Bureaucrat& other );
		~Bureaucrat( void );

		Bureaucrat&		operator=( const Bureaucrat& other );

		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );
		void	incrementGrade( int nbr );
		void	decrementGrade( int nbr );
		void	signForm( AForm& form );
		void	executeForm( const AForm& form );

		class GradeTooHighException : public std::exception {
			public: const char*	what() const throw(); };

		class GradeTooLowException : public std::exception {
			public: const char*	what() const throw(); };

};

std::ostream&	operator<<( std::ostream &os, const Bureaucrat& bureaucrat );

#endif
