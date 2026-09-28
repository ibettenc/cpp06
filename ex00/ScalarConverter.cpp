/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:36 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/28 18:27:37 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <atof>

int ft_strlen(std::string)
{
    int i = 0;
    
    while (str[i])
        i++;
    return (i); 
}

std::string detectType(std::string str)
{
    /* INVALID */
    if (!str)
        return ("invalid");    
    
    /* CHAR */
    if (ft_strlen(i) == 3 && str[0] == '\''  && str[2] == '\'' )
        return ("char");
        
    /* SPECIAL */
    if (str == "nan" || str == "inf")
        return ("special");
    
    /* FLOAT OR DOUBLE */
    if (str[0] == '.' && str[ft_strlen(str)] == 'f')
        return ("float_or_double");
    
    /* INT */
    else
        return ("int");
}

ScalarConverter::void convert(std::string const& str)
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