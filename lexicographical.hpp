/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:14:16 by fmehdaou          #+#    #+#             */
/*   Updated: 2022/07/23 18:07:32 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_HPP
#define LEXICOGRAPHICAL_HPP

// range1 
namespace ft {

template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (last2 == first2 || *first2 < *first1)
          return (false);
        else if (*first1 < *first2)
          return (true);
        first1++;
        first2++;
    }
    return (first2 != last2);
    
}
}

#endif /* LEXICOGRAPHICAL_HPP */
