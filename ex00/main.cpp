/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:51 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/29 13:47:50 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Error : Invalid number of arguments" << std::endl;
    
    convert(av);
    
    
    return 0;
}

/*

chuis a letape B: Conversion et Validation
- je dois (bien) convertir str en la bonne la bonne
    valeur en passant par double askip, a voir 

*/

/*
4 types d'expressions 
- static_cast<type>
- dynamic_cast<ytpe>
- const_cast<type>
- reiterpret_cast<type>
*/

/* /!\ PAS OUBLIER EXCEPTIONS
- overflow pour un int si 2147483648 (int max = 2147483647) 

*/