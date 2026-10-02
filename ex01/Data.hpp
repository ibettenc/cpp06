/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:38:37 by ibettenc          #+#    #+#             */
/*   Updated: 2026/10/02 14:40:46 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Serializer.hpp"

class Data
{
    private:
        uintptr_t value;

    public: 
        Data();
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);

        uintptr_t get_value();
        void set_value(uintptr_t v);
};