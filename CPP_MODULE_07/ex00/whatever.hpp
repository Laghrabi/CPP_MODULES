/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:32:37 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/13 17:23:20 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void    swap(T& a, T& b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T   min(T a, T b) {
    if (a == b)
        return (b);
    else if (a < b)
        return (a);
    else
        return (b);
}

template <typename T>
T   max(T a, T b) {
    if (a == b)
        return (b);
    else if (a > b)
        return (a);
    else
        return (b);
}