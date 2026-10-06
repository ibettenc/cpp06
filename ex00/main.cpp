/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:51 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/06 14:27:40 by ibettenc         ###   ########.fr       */
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

// ./scalar 3.14159   -> float: 3.14159f   double: 3.14159
// ./scalar 4.25f     -> float: 4.25f      double: 4.25
// ./scalar 42        -> float: 42.0f      double: 42.0
// ./scalar -5        -> char: impossible
// ./scalar 127       -> char: Non displayable
// ./scalar a         -> char: 'a'   int: 97
// ./scalar .         -> char: '.'  
// ./scalar -inff   -> float: -inff        double: -inf
// ./scalar +inff   -> float: +inff        double: +inf
// ./scalar .25     -> float: 0.25f        double: 0.25
// ./scalar 42.     -> float: 42.0f        double: 42.0
// ./scalar nanf    -> float: nanf         double: nan