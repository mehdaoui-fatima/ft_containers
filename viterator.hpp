
#ifndef VITERATOR_HPP
#define VITERATOR_HPP
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

template <class T>
class iterator_ : public iterator<std::random_access_iterator_tag, T>
{ 
public:
	typedef T                                                            iterator_type;
    typedef typename iterator_traits<iterator_type>::iterator_category   iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type	         value_type;
    typedef typename iterator_traits<iterator_type>::pointer             pointer;
    typedef typename iterator_traits<iterator_type>::reference           reference;
    typedef typename iterator_traits<iterator_type>::difference_type     difference_type;

    iterator_() : current(nullptr) {}
	
    explicit iterator_(iterator_type it) : current(it){} //(2)initialization
	
    template <class _T>
  		iterator_(const iterator_<_T>& it) {current = it.base();}
    
    iterator_& 		operator=(iterator_ const&	other)
	{
		current = other.current;
		return (*this);
    }
    
	iterator_type base() const // base
	{
		return (current);
	}

    reference operator*() const 
    {
        return *(current);
    }

    iterator_ operator+(difference_type n) const
    {
        return iterator_(current + n);
    }
    
    iterator_ operator++(int) //a++
    {
        iterator_ iter_tmp = *this;
        current++;
        return iter_tmp;
    }

    iterator_& operator++() //++a
    {
		current++;
        return (*this);
    }
    
    iterator_& operator+=(difference_type n) //+=
    {
        current += n;
        return (*this);
    }
    
    iterator_ operator-(difference_type n) const
    {
        return (iterator_(current - n));
    }

    iterator_& operator--() // --a preDecrementation 
    {
        current--;
        return (*this);
    }
    
    iterator_ operator--(int) // a--
    {
        iterator_ iter_tmp = *this;
        current--;
        return iter_tmp;
    }
    
    iterator_& operator-=(difference_type n)
    {
        current -= n;
        return (*this);
    }

    pointer operator->() const
    {
        return &(operator*());
    }

    reference operator[](difference_type n) const
    {
        return(*(current + n - 1));
    }
    
    ~iterator_(){}
    
protected:
	iterator_type current;
};


template <class Iterator>
bool operator==(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.base() == rhs.base());
}

template <class Iterator>
  bool operator!=(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.base() != rhs.base());
}
	
template <class Iterator>
  bool operator<(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.base() < rhs.base());
}

template <class Iterator>
  bool operator<=(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.base() <= rhs.base());
}

template <class Iterator>
  bool operator>(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.base() > rhs.base());
}
	
template <class Iterator>
  bool operator>=(const iterator_<Iterator>& lhs,
                   const iterator_<Iterator>& rhs)
{
    return(lhs.base() >= rhs.base());
}

template <class T>
iterator_<T> operator+(
             typename iterator_<T>::difference_type n,
             const iterator_<T>& rev_it)
{
    return (iterator_<T>(rev_it.base() + n));
}

template <class T>
typename iterator_<T>::difference_type operator-(
	const iterator_<T>& lhs,
    const iterator_<T>& rhs)
{
     ptrdiff_t diff = (lhs.base() - rhs.base());
     return diff;
}

#endif


