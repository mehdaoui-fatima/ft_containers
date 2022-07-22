/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:17:01 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/24 16:40:00 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

  template <class T1, class T2> struct pair
  {

      typedef T1 first_type;
      typedef T2 second_type;

      pair() : first(), second()
      {}

      template<class U, class V> 
      pair (const pair<U, V>& pr)
      {
          this->first = pr.first;
          this->second = pr.second;
      }

      pair (const first_type& a, const second_type& b)
      {
          this->first = a;
          this->second = b;
      }

      pair& operator=(const pair& pr)
      {   
          this->first = pr.first;
          this->second = pr.second;
          return(*this);
      }
      
      first_type first;
      second_type second;
  
  };

  template <class T1, class T2> pair<T1, T2>
  make_pair(T1 x, T2 y)
  {
      return (pair<T1,T2>(x,y));
  }

}

template <class T1, class T2>
  bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ 
    return lhs.first==rhs.first && lhs.second==rhs.second;
}

template <class T1, class T2>
  bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ 
    return !(lhs==rhs);
}

template <class T1, class T2>
  bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ 
    return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
}

template <class T1, class T2>
  bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ 
    return !(rhs<lhs);
}

template <class T1, class T2>
  bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ 
    return rhs<lhs;
}

template <class T1, class T2>
  bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ 
    return !(lhs<rhs);
}


#endif /* PAIR_HPP */
