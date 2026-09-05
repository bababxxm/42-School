/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 03:31:31 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/01 10:57:20 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:

		std::string		_target;

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		virtual ~RobotomyRequestForm( void );

		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
		virtual void	execute( Bureaucrat const & executor ) const;

};

#endif
