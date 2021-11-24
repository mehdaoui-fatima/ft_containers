/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:14:16 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/24 11:42:21 by fmehdaou         ###   ########.fr       */
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
        //the range 2 is empty so range 1 is greather(false)
        if (last2 == first2 || *first2 < *first1)
          return (false);
        else if (*first1 < *first2)
          return (true);
        first1++;
        first2++;
    }
    // (first1 == first2) so range1 is smaller (true) 
    // if only fisrt2 != last2
    return (first2 != last2);
    
}


//TODO: fix it
// template <class InputIterator1, class InputIterator2, class Compare>
//   bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
//                                 InputIterator2 first2, InputIterator2 last2,
//                                 Compare comp)
// {
//     while (comp(*first1, *last1) || comp(*last1, *first1))
//     {
//         //the range 2 is empty so range 1 is greather(false)
//         if (!(comp(*last2, *first2) && !comp(*last2, *first2)) || comp(*first2, *first1))
//           return (false);
//         else if (comp(*first1, *first2))
//           return (true);
//         first1++;
//         first2++;
//     }
//     // (first1 == first2) so range1 is smaller (true) 
//     // if only fisrt2 != last2
//     return (comp(*first1, *last1) || comp(*last1, *first1));


// }


}

#endif /* LEXICOGRAPHICAL_HPP */
