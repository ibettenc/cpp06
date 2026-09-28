/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:15:56 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/28 17:58:51 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <limits>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
    private :
        ScalarConverter() {}
        ~ScalarConverter() {}
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);    
    public :
    /* Member functions */
        void convert(std::string const& str);
    
    /* Exceptions */
        class OverflowException : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return ("Global error : Overflow");
                }
        };

        class InvalidFormatException : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return ("Global error : Invalid format");
                }
        };


};
