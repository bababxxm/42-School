/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 04:20:50 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/17 04:55:20 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::zombieHorde( int N, std::string name )
{
	if (N <= 0) return (NULL);

	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}
