/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:19:15 by fmehdaou          #+#    #+#             */
/*   Updated: 2022/07/23 11:39:49 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

/* NOTE: enable_if is a specialized tenplate
define as :
*/

namespace ft {
    
    template <bool Cond, class T = void> 
    struct enable_if {};

    template <class T> 
    struct enable_if<true, T> {
        typedef T type;
    };
}

#endif 
