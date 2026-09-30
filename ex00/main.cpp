/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:51 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/30 15:52:16 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    std::string value;
    
    if (ac != 2)
    {
        std::cout << "Error : Invalid number of arguments" << std::endl;
        return (1);
    }
    value = av[1];
    
    try
    {
        ScalarConverter::convert(value);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }
    
    return 0;
}

/*

tout convertit bien SAUF CHAR donc a gerer 

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
- 
*/