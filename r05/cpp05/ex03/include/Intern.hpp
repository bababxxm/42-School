/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 04:51:12 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:29:37 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

class Intern {

	public:

		Intern( void );
		Intern( const Intern& other );
		~Intern( void );

		Intern&	operator=( const Intern& other );
		AForm*	makeForm( const std::string& name, const std::string& target );

		class FormNotFound : public std::exception {
			public: const char* what() const throw(); };

};

#endif
