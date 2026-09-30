/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:36 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/30 17:05:55 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cerrno>

static std::string detectType(std::string const& str)
{
    bool is_spe = false;
    
    /* INVALID */
    if (str.empty())
        return ("invalid");    
    
    /* CHAR */
    if ((str.length()) == 3 && str[0] == '\'' && str[2] == '\'')
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
    if (str.find('.') != std::string::npos || str[str.length() - 1] == 'f')
        return ("float_or_double");
    
    /* INT */
    else
        return ("int");
}

void ScalarConverter::convert(std::string const& str)
{
    double value = 0.0;
    char* endptr;

    /* DETECT AND VALIDATION */
    std::string type = detectType(str);

    if (type == "invalid")
        throw InvalidFormatException();
    
    /* PARSING */
    if (type == "char")
        value = static_cast<double>(str[1]);
    else
    {
        errno = 0;
        value = std::strtod(str.c_str(), &endptr);
        if (endptr == str.c_str()) // Case 1: no conversion
            throw InvalidFormatException();
        if (*endptr != '\0' && *endptr != 'f') // Case: 2 characters remaining after 
            throw InvalidFormatException();
    }
        
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
        
        // // DEBUG
        // std::cout << "\nvalue: " << value << "\n";
        // std::cout << "type: " << type << "\n";
        // std::cout << "c: " << c << "\n";
        // std::cout << "str: " << str << "\n\n";
        
        if (c >= 32 && c <= 126)
            std::cout << "char: '" << c << "'\n";
        else
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