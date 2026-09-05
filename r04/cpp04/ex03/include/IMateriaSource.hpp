/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:14:02 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 23:19:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOUCE_HPP
# define IMATERIASOUCE_HPP

class IMateriaSource {

	public:

		virtual ~IMateriaSource( void ) {};

		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( const std::string & type ) = 0;

};

#endif
