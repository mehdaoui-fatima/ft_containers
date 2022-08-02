
#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

template <class Iterator>
class	tree_reverse_iter : public ft::iterator< std::bidirectional_iterator_tag,
                                typename iterator_traits<Iterator>::value_type,
                                typename iterator_traits<Iterator>::difference_type,
                                typename iterator_traits<Iterator>::pointer,
                                typename iterator_traits<Iterator>::reference>
{
    public:
        typedef Iterator												iterator;
        typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
        typedef typename iterator_traits<iterator>::difference_type  	difference_type;
        typedef typename iterator_traits<iterator>::pointer          	pointer;
        typedef typename iterator_traits<iterator>::reference        	reference;
    private:
        iterator	it;
    public:
    tree_reverse_iter(): it() {};

    explicit tree_reverse_iter(iterator n):it(n) {};

    template <class Iter>
        tree_reverse_iter (const tree_reverse_iter<Iter>& rev_it): it(rev_it.base()) {};

    iterator	base() const{
        return it;
    };
    tree_reverse_iter&	operator++(){
        --it;
        return *this;
    };
    tree_reverse_iter	operator++(int){
        tree_reverse_iter	tmp = *this;
        ++(*this);
        return tmp;
    };
    tree_reverse_iter&	operator--(){
        ++it;
        return *this;
    };
    tree_reverse_iter	operator--(int){
        tree_reverse_iter	tmp = *this;
        --(*this);
        return tmp;
    };
    reference	operator*() const{
        return *(--base());
    };
    
    pointer	operator->() const{
        return	&(operator*());
    };

    tree_reverse_iter operator+ (difference_type n) const{
        return tree_reverse_iter(it - n);
    };

    tree_reverse_iter operator- (difference_type n) const{
        return tree_reverse_iter(it + n);
    };

    tree_reverse_iter& operator+= (difference_type n){
        it -= n;
        return (*this);
    };

    tree_reverse_iter& operator-= (difference_type n){
        it += n;
        return (*this);
    };

    bool	operator==(tree_reverse_iter const &rhs){
        return	(this->base() == rhs.base());
    };

    bool	operator!=(tree_reverse_iter const &rhs){
        return	!(this->base() == rhs.base());
    };
};


#endif