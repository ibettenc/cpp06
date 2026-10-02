/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:38:22 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/02 14:39:17 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : value(0) {}
Data::~Data() {}
Data::Data(const Data& other) : value(other.value) {}
Data& Data::operator=(const Data &other)
{
    if (this != &other)
        value = other.value;
    return *this;
}

uintptr_t Data::get_value()
{
    return (value);
}

void Data::set_value(uintptr_t v)
{
    value = v;
}