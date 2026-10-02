/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:10:37 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/02 15:06:03 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include <stdexcept>

class Data;

class Serializer
{
    private:
        Serializer() {}
        ~Serializer() {}
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer&);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
        
        class Exception : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Global error");
                }
        };
        
    
};

