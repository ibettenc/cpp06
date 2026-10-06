/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:56 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/06 14:12:19 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>

class ScalarConverter
{
    private : /// private constructor bc it cannot be instantiable
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);    
    public :
    /* Member functions */
        static void convert(std::string const& str);
    
    /* Exceptions */
        class InvalidFormatException : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return ("Global error : Invalid format");
                }
        };


};

#endif