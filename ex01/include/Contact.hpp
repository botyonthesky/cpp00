/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:38:00 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/20 10:42:43 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    public:
        Contact();
        ~Contact(); 
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string get_phone();
        void    set_phone(std::string& munber);
        std::string get_darkest();
        void    set_darkest(std::string& secret);
        
    private:
        std::string phone_number;
        std::string darkest_secret;
};

#endif
