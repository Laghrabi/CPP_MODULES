/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:43:28 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/15 23:47:49 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n] ()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _arr(new T[other._size] ()), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete [] _arr;
        _size = other._size;
        _arr = new T[_size] ();
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete [] _arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBounds();
    return (_arr[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBounds();
    return (_arr[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
    return("Index out of bounds");
}

#endif