
#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "viterator.hpp"
#include "iterator_traits.hpp"

template <class Iterator> 
class reverse_iterator_ : public iterator<std::random_access_iterator_tag, Iterator>
{
public:
	typedef Iterator                                                iterator_type;
    typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef typename iterator_traits<Iterator>::value_type	        value_type;
    typedef typename iterator_traits<Iterator>::pointer             pointer;
    typedef typename iterator_traits<Iterator>::reference           reference;
    typedef typename iterator_traits<Iterator>::difference_type     difference_type;

    reverse_iterator_() : current() //(1)default
    {};

	explicit reverse_iterator_(iterator_type it) : current(it){} //(2)initialization

    // template <class Iterator>
    // reverse_iterator (const reverse_iterator<Iter>& rev_it)
    // {
        
    // }

    // template <class Iter> //(3)copy
    // reverse_iterator_& operator=(reverse_iterator_<Iter> const &iter){
    //     current = iter.current;
    // }
    
    template <class iterator_type>
		reverse_iterator_ (const reverse_iterator_<iterator_type>& rev_it) { current = rev_it.base();}

	reverse_iterator_& 		operator=(reverse_iterator_ const&	other)
	{
		current = other.base();
		return (*this);	
	}

	iterator_type base() const // base
	{
		return (current);
	}

    reference operator*() const {
        Iterator    iter_tmp = current;
        iter_tmp--;
        return *(iter_tmp);
    }

    reverse_iterator_ operator+(difference_type n) const
    {
        return reverse_iterator_(current - n);
    }
    
    reverse_iterator_ operator++(int) //a++
    {
        reverse_iterator_ iter_tmp = *this;
        current--;
        return iter_tmp;
    }

    reverse_iterator_& operator++() //++a
    {
        current--;
        return (*this);
    }
    
    reverse_iterator_& operator+=(difference_type n) //+=
    {
        current -= n;
        return (*this);
    }
    
    reverse_iterator_ operator-(difference_type n) const
    {
        current = current + n;
        return (*this);
    }

    reverse_iterator_& operator--(void) // --a preDecrementation 
    {
        current++;
        return (*this);
    }
    
    reverse_iterator_ operator--(int) // a--
    {
        reverse_iterator_ iter_tmp = *this;
        current++;
        return iter_tmp;
    }
    
    reverse_iterator_& operator-=(difference_type n)
    {
        current += n;
        return (*this);
    }

    pointer operator->() const
    {
        return &(operator*());
    }

    reference operator[](difference_type n) const
    {
        return(*(current - n - 1));
    }
    
    ~reverse_iterator_(){}
    
protected:
	Iterator current;
};


template <class Iterator>
bool operator==(const reverse_iterator_<Iterator>& lhs,
                   const reverse_iterator_<Iterator>& rhs)
{
    return(lhs.current == rhs.current);
}

template <class Iterator>
  bool operator!=(const reverse_iterator_<Iterator>& lhs,
                   const reverse_iterator_<Iterator>& rhs)
{
    return(lhs.base() != rhs.base());
}
	
template <class Iterator>
  bool operator<(const reverse_iterator_<Iterator>& lhs,
                   const reverse_iterator_<Iterator>& rhs)
{
    return(lhs.base() < rhs.base());
}

template <class Iterator>
  bool operator<=(const reverse_iterator_<Iterator>& lhs,
                   const reverse_iterator_<Iterator>& rhs)
{
    return(lhs.base() <= rhs.base());
}

template <class Iterator>
  bool operator>(const reverse_iterator_<Iterator>& lhs,
                   const reverse_iterator_<Iterator>& rhs)
{
    return(lhs.base() > rhs.base());
}
	
template <class Iterator>
  bool operator>=(const reverse_iterator_<Iterator>& lhs,
                   const reverse_iterator_<Iterator>& rhs)
{
    return(lhs.base() >= rhs.base());
}


// template <class Iterator>
// reverse_iterator_<Iterator> operator+(
//              typename reverse_iterator_<Iterator>::difference_type n,
//              const reverse_iterator_<Iterator>& rev_it)
// {
    
// }

// template <class Iterator>
//   typename reverse_iterator_<Iterator>::difference_type operator-(
//     const reverse_iterator_<Iterator>& lhs,
//     const reverse_iterator_<Iterator>& rhs)
// {
//     rhs.current - lhs.current;
// }

#endif /* REVERSE_ITERATOR_HPP */
