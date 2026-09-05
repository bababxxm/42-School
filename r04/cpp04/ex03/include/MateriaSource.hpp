/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:53:37 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 15:52:26 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOUCE_HPP
# define MATERIASOUCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:

		AMateria*	_learned[4];
		void		clearMateria( void );

	public:

		MateriaSource( void );
		MateriaSource( const MateriaSource& other );
		~MateriaSource( void );

		MateriaSource&	operator=( const MateriaSource& other );
		void			learnMateria( AMateria* m );
		AMateria*		createMateria( const std::string& type );

};

#endif
