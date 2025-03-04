/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 07:39:01 by aatieh            #+#    #+#             */
/*   Updated: 2025/03/04 12:41:55 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:

				Fixed();
				~Fixed();
				Fixed( const Fixed &src );
				Fixed( const int init_value );
				Fixed( const float init_value );
		Fixed	&operator=( const Fixed &src );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt ( void ) const;

	private:

		int					value;
		static const int	f_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
