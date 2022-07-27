/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bts.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmehdaou <fmehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:49:17 by fmehdaou          #+#    #+#             */
/*   Updated: 2022/07/22 15:36:25 by fmehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP
#include "pair.hpp"
#include <cstddef>


template <class _T>
struct _node
{
    public:
        typedef _T  value_type;
        _T          value;
        _node<_T>   *parent;
        _node<_T>   *left;
        _node<_T>   *right;
        int balance_factor;
        //examp;e to ilustrate 
        _node(const value_type  &p):value(p){};
        _node   &operator=(const _node rhs){
            this->value = rhs.value;
            this->parent = rhs.parent;
            this->left = rhs.left;
            this->right = rhs.right;
            this->balance_factor = rhs.balance_factor;
        }
        bool operator<(const _node &rhs)
        {
            return (this->value.first < rhs.value.first);
        }





}







#endif