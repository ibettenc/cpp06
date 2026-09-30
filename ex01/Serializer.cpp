/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:10:27 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/30 17:29:34 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::uintptr_t serialize(Data *ptr)
{
    // converti *ptr en uinptr_t
    // *Data -> unsigned_int
    
    reinterpret_cast<uinptr_t>(ptr) : transforme adresse mem en un nbre entier sans changer d'adresse
    // REGARDER CETTE FORMULE SUR INTERNET LE PROJET VA ETRE RAPIDE OMG ENFIN!!!!!!!!!!!
}

Serializer::Data *deserialize(uintptr_t raw)
{
    // converti raw en *Data
    // unsigned_int -> *Data
    reinterpret_cast<*Data>(raw)
}

// je dois creer une Data structure qui n'est pas vide
// je dois use serialize() sur l'adresse de l'objet Data ET..
// ..passer sa valeur de retour dans deserialize() pour comparer
