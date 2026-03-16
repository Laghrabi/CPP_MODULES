/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:54:54 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/13 18:09:40 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T, typename Func>
void    iter(T *array, const size_t len, Func func)
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

#endif