/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <tmaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:38:00 by tmaillar          #+#    #+#             */
/*   Updated: 2024/05/22 13:38:53 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    public:
        Contact();
        ~Contact(); 
        std::string get_fname();
        std::string get_lname();
        std::string get_nname();
        std::string get_phone();
        std::string get_darkest();
        int         get_index();
        void    set_fname(std::string &fname);
        void    set_lname(std::string &lname);
        void    set_nname(std::string &nmame);
        void    set_phone(std::string &munber);
        void    set_darkest(std::string &secret);
        void    set_index(int &idx);
        
    private:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif
