/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:54:44 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/02 15:10:22 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Base
{
    public:
        /* Constructor & Destructor */
        Base();
        virtual ~Base();
        Base(const Base& other);
        
        /* Member functions */
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
        
        /* Assignement operator */
        Base operator=(const Base& other);
};
