/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:36 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/05 17:30:50 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cctype>

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::~ScalarConverter()
{
    
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
    
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return (*this);
}

static std::string detectType(std::string const& str)
{
    bool is_spe = false;
    
    /* INVALID */
    if (str.empty())
        return ("invalid");    
    
    /* CHAR */
    if (!isalnum(str[0]))
        return ("char");
    if ((str.length()) == 3 && str[0] == '\'' && str[2] == '\'')
        return ("char");
    
    /* SPECIAL */
    if (str.find("nan") == 0 || str.find("inf") == 0)
        is_spe = true;
    if (str[0] == '+')
    {
        if (str.find("+nan") == 0 || str.find("+inf") == 0 ||
            str.find("+nanf") == 0 || str.find("+inff") == 0)
            return ("special +");
    }
    else if (str[0] == '-')
    {
        if (str.find("-nan") == 0 || str.find("-inf") == 0 ||
            str.find("-nanf") == 0 || str.find("-inff") == 0)
            return ("special -");      
    }
    if (str.find("nanf") == 0 || str.find("inff") == 0)
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
    std::string type;
    
    /* DETECT AND VALIDATION */
    type = detectType(str);

    if (type == "invalid")
        throw InvalidFormatException();
    
    /* PARSING */
    if (type == "char")
        value = static_cast<double>(str[0]);
    else
    {
        value = std::strtod(str.c_str(), &endptr); // endptr = en of numbers by strtod()
        if (endptr == str.c_str()) // Case 1: no conversion
            throw InvalidFormatException();
        if (endptr[0] && (endptr[0] != 'f' || endptr[1] != '\0')) // Case: 2 characters remaining after 
            throw InvalidFormatException();
    }
        
    /* SPECIAL */
    if (value != value)
    {
        if (type == "special +")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: +nanf\n";
            std::cout << "double: +nan\n";
        }
        else if (type == "special -")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: -nanf\n";
            std::cout << "double: -nan\n";
        }
        else 
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
        return;
    }

    if (std::numeric_limits<double>::infinity() == value)
    {
        if (type == "special +")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        }
        else if (type == "special -")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else 
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: inff\n";
            std::cout << "double: inf\n";
        }
        return;
    }

    /* CHAR */
    if (value < 0 || value > 127)
        std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(value);
        
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
    // else 
        // std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
    else
    {
        int len = str.length();
        int point = str.find('.');

        int j =  len - point;
        
        std::cout << "number of digit after '.': " << j << "\n";
        
        // std::cout << "float: " << std::fixed << std::setprecision(str.length()) << static_cast<float>(value) << "f\n";
    }   
    // if (str.find('.'))
    // {
        
    // }
    
    /* DOUBLE */
    std::cout << "double: " << value << "\n";

}
