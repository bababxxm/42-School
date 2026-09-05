/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:33:25 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:06:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		void	checkGrade( void ) const;

	protected:

		void	checkExecutable( const Bureaucrat& executor ) const;

	public:

		AForm( void );
		AForm( const std::string& name, int gradeToSign, int gradeToExecute );
		AForm( const AForm& other );
		virtual ~AForm( void );

		const std::string&	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute( void ) const;

		AForm&	operator=( const AForm& other );
		void	beSigned( const Bureaucrat& bureaucrat );

		virtual void	execute( Bureaucrat const & executor ) const = 0;

		class GradeTooHighException : public std::exception {
			public: const char* what() const throw(); };

		class GradeTooLowException : public std::exception {
			public: const char* what() const throw(); };

		class FormAlreadySignedException : public std::exception {
			public: const char* what() const throw(); };

		class FormNotSignedException : public std::exception {
			public: const char* what() const throw(); };

};

#endif
