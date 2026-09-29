/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:36 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/29 18:00:04 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
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
    if (str.find("+nan") == 0 || str.find("-nan") == 0 ||
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

static void ScalarConverter::convert(std::string const& str)
{
    double value = 0.0;
    char* endptr;
    std::string type = detectType(str);

    /* DETECT AND VALIDATION */
    if (type == "invalid")
        throw InvalidFormatException();
    
    /* PARSING */
    if (type == "char")
        value = static_cast<double>(str[1]);
    else
        value = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' && *endptr != 'f')
        throw InvalidFormatException();
        
    /* SPECIAL */
    if (std::isnan(value))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }

    if (std::isinf(value))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: inff\n";
        std::cout << "double: inf\n";
        return;
    }

    /* CHAR */
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(value);
        if (c >= 32 && c <= 126)
            std::cout << "char: non displayable\n";
    }
    
    /* INT */
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(value) << "\n";
    }
    
    /* FLOAT */
    if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: impossible\n";
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";

    /* DOUBLE */
    std::cout << "double: " << value << "\n";

}