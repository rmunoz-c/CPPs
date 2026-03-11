/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 18:36:58 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 18:36:58 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T& min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
const T& max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif