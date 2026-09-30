/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:10:37 by ibettenc          #+#    #+#             */
/*   Updated: 2026/09/30 17:26:48 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Serializer
{
    private:
        Serializer() {}
        ~Serializer() {}
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
        
        class Exception : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {
                    return ("Global error");
                }
        }
    
};

class Data
{
    private:
        int value;

    public: 
        Data();
        ~Data();
        Data(const Data&);
        Data operator=(const Data&);
};