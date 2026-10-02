/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:10:12 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/02 14:53:19 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data myData;
    Data* deserializedData;
    
    myData.set_value(65); // to change for the eval
    
    std::cout << "data value: " << myData.get_value() << "\n";
    
    
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "raw data or serialized data value: " << raw << "\n";

    deserializedData = Serializer::deserialize(raw);
    std::cout << "data value after deserialization: " << deserializedData->get_value() << "\n";

    if (&myData != deserializedData)
    {
        std::cout << "project failed... :()\n";
        return (1);
    }
    else
        std::cout << "exercice completed! :)\n";
    return 0;
}

