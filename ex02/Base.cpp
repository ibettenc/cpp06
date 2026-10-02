/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:54:35 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/02 15:43:19 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Base.hpp"
#include <cstdlib>

Base* generate(void)
{
    int random = rand() % 2;

    if (random == 0)
        return(Base* A);
    else if (random == 1)
        return (Base* B);
    else
        return (Base* C);
        
    // It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
    // to use anything you like for the random choice implementation.
}

void identify(Base* p)
{
    // It prints the actual type of the object pointed to by p: "A", "B", or "C".
          
}

void identify(Base& p)
{
    // It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
    // inside this function is forbidden.
}