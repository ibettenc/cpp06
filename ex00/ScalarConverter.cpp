/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:36 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/29 16:45:40 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <cerrno>

int ft_strlen(std::string const& str)
{
    int i = 0;
    
    while (str[i])
        i++;
    return (i); 
}

std::string detectType(std::string const& str)
{
    bool is_spe = false;
    
    /* INVALID */
    if (str.empty())
        return ("invalid");    
    
    /* CHAR */
    if (ft_strlen(str) == 3 && str[0] == '\''  && str[2] == '\'' )
        return ("char");
        
    /* SPECIAL */
    if (str.find("nan") == 0 || str.find("inf") == 0)
        is_spe = true;
    else if (str.find("+nan") == 0 || str.find("-nan") == 0 ||
        str.find("-inf") == 0 || str.find("+inf") == 0)
            is_spe = true;
    if (str.find("nanf") == 0 || str.find("inff") == 0)
        is_spe = true;
    if (str.find("+nanf") == 0 || str.find("-nanf") == 0 ||
        str.find("+inff") == 0 || str.find("-inff") == 0)
            is_spe = true;
    if (str.find("NaN") == 0 ||  str.find("Inf") == 0)
        is_spe = true;
    if (is_spe == true)
        return ("special");    
    
    /* FLOAT OR DOUBLE */
    if (str.find('.') != std::string::npos || str[ft_strlen(str) - 1] == 'f')
        return ("float_or_double");
    
    /* INT */
    else
        return ("int");
}

ScalarConverter::static void convert(std::string const& str)
{
    if (detectType(str) == "invalid")
        throw InvalidFormatException;
    
    if (detectType(str) == "char")
        str = static_cast<char>;

    if (detectType(str) == "int")
        str = static_cast<int>;

    if (detectType(str) == "float_or_double")
        str = static_cast<double>;
    
    if (detectType(str) == "special")
        // str = static_cast<idk>
    

}