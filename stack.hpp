/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:31:23 by fmehdaou          #+#    #+#             */
/*   Updated: 2021/11/23 19:38:39 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"
#include <stack>


namespace ft {

    template <class T, class Container = ft::vector<T> > 
    class stack {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename container_type::size_type size_type;

        //explicit to prevent impcilite cast that may happen
        explicit stack(const container_type& ctnr = container_type()) : c(ctnr)
        {}
    
        bool empty() const
        {
            return(c.size() == 0);
        }

        //NOTE !!!!! reference and value type check that
        value_type& top()
        {
            return (c.back());
        }

        size_type size() const
        {
            return c.size();
        }

        const value_type& top() const
        {
            return (c.back());
        }

        void push (const value_type& val)
        {
            c.push_back(val);
        }
        
        void pop()
        {
            c.pop_back();
        }

        template <class _T, class _Container>
        friend bool operator==(const stack<  _T,  _Container>& lhs, const stack<  _T,  _Container>& rhs);

        template <class _T, class _Container>
        friend bool operator!=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

        template <class _T, class _Container>
        friend bool operator<(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

        template <class _T, class _Container>
        friend bool operator<=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

        template <class _T, class _Container>
        friend bool operator>(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);

        template <class _T, class _Container>
        friend bool operator>=(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs);
        
    protected:
        container_type c;
    };

    template <class _T, class _Container>
    bool operator==(const stack<_T, _Container>& lhs, const stack<_T, _Container>& rhs)
    {
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c != rhs.c);
    }

    template <class T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c < rhs.c);
    }

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c <= rhs.c);
    }

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c > rhs.c);
    }

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c >= rhs.c);
    }

}
#endif 
