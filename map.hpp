/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:16:09 by adupuy            #+#    #+#             */
/*   Updated: 2021/10/11 18:16:10 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "red_black_tree.hpp"
#include "bidirectional_iterator.hpp"
#include <functional>

namespace   ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
    class   map
    {
        public:

            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef Compare                                         key_compare;
            typedef Alloc                                           allocator_type;
            typedef ft::pair<const Key, T>                          value_type;

            typedef size_t                                          size_type;
            typedef std::ptrdiff_t                                  difference_type;

            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;

            typedef Node<value_type>                                node_type;
            typedef node_type *                                     node_ptr;

            class   value_compare/*: public std::binary_function<value_type, value_type, bool>*/
            {
                friend class map;
                public:

                    bool    operator()(const value_type & x, const value_type & y) const {
                        
                        return key_compare()(x.first, y.first); // mettre key_compare()
                    }

                    value_compare &operator=(const value_compare &) { return *this; }

                /*protected:

                    Compare     comp;
                    value_compare(Compare c): comp(c) {}*/
            };

        private:

            typedef typename    Alloc::template rebind<value_type>::other   pair_allocator_type;
            //typedef RedBlackTree<value_type, key_compare, pair_allocator_type>    RBT;

        public:

            typedef typename ft::bidirectional_iterator<value_type, node_type >             iterator;
            typedef typename ft::bidirectional_iterator<const value_type, const node_type>  const_iterator;
            typedef ft::reverse_iterator<iterator>                                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                    const_reverse_iterator;

            explicit map(const key_compare & comp = key_compare(),
                            const allocator_type & alloc = allocator_type()): _tree() {

                _alloc = alloc;
                _key_comp = comp;
                _value_comp = value_compare();
            }

            template<class InputIterator>
            map(InputIterator first, InputIterator last,
                    const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type()): _tree() {

                _alloc = alloc;
                _key_comp = comp;
                _value_comp = value_compare();
                _tree.insert(first, last);
            }

            map(const map & cpy) {

                *this = cpy;
            }

            ~map() {}

            map &   operator=(const map & rhs) {

                if (this != &rhs)
                {
                    clear();
                    _alloc = rhs._alloc;
                    _value_comp = rhs._value_comp;
                    insert(rhs.begin(), rhs.end());
                }
                return *this;
            }

        /*
            Renvoie un itérateur faisant référence au premier élément de map .
            => begin pointe vers l'élément qui va en premier suivant le critère de tri du conteneur .
            Si le conteneur est vide , la valeur de l'itérateur renvoyée ne doit pas être déréférencée.
        */
            iterator            begin() {

                return iterator(_tree.minimum(_tree.getRoot()), _tree.getSent(), _tree.getRoot());
            }

            const_iterator      begin() const {

                return const_iterator(_tree.minimum(_tree.getRoot()), _tree.getSent(), _tree.getRoot());
            }


        /*
            Renvoie un itérateur se référant à l' élément au -delà de la fin dans le conteneur de map .
            Si le conteneur est vide , cette fonction renvoie la même chose que map::begin .
        */
            iterator            end() {

                return iterator(_tree.getSent(), _tree.getSent(), _tree.getRoot());
            }

            const_iterator      end() const {

                return const_iterator(_tree.getSent(), _tree.getSent(), _tree.getRoot());
            }


        /*
            Renvoie un itérateur inverse pointant sur le dernier élément du conteneur (c'est-à-dire son début inverse ).
            Les itérateurs inverses itèrent vers l'arrière : les augmenter les déplace vers le début du conteneur.
            => rbegin pointe sur l'élément précédant celui qui serait pointé par membre end .
        */
            reverse_iterator        rbegin() {

                return reverse_iterator(end());
            }
            
            const_reverse_iterator  rbegin() const {

               return const_reverse_iterator(end());
            }

        
        /*
            Renvoie un itérateur inverse pointant sur l'élément théorique juste avant le premier élément du conteneur
            (qui est considéré comme son extrémité inverse ).
            La plage entre map::rbegin et map::rend contient tous les éléments du conteneur (dans l'ordre inverse).
        */
            reverse_iterator        rend() {

               return reverse_iterator(begin());
            }

            const_reverse_iterator  rend() const {

               return const_reverse_iterator(begin());
            }

       
            bool                    empty() const {

                return (_tree.empty());
            }

            size_type               size() const {

                return (_tree.size());
            }

            size_type               max_size() const {

                return (_tree.max_size());
            }


        /*
            Si k correspond à la clé d'un élément dans le conteneur,
            la fonction renvoie une référence à sa valeur mappée.
            Si k ne correspond à la clé d'aucun élément du conteneur,
            la fonction insère un nouvel élément avec cette clé et
            renvoie une référence à sa valeur mappée.
            Notez que cela augmente toujours la taille du conteneur d'une unité,
            même si aucune valeur mappée n'est affectée à l'élément
            (l'élément est construit à l'aide de son constructeur par défaut).
        */
            mapped_type &           operator[] (const key_type & k) {

                iterator    tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    tmp = insert(tmp, value_type(k, mapped_type()));
                return (tmp->second);
            }

            mapped_type &           at(const key_type & k) {

                iterator    tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    throw std::out_of_range("map::at");
                return (tmp->second);
            }

            const mapped_type &     at(const key_type & k) const {

                const_iterator    tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    throw std::out_of_range("map::at");
                return (tmp->second);
            }


        /*
            Étend le conteneur en insérant de nouveaux éléments,
            augmentant ainsi la taille du conteneur du nombre d'éléments insérés.
            Étant donné que les clés d'élément dans une map sont uniques,
            l'opération d'insertion vérifie si chaque élément inséré a une clé équivalente à celle d'un élément déjà dans le conteneur,
            et si c'est le cas, l'élément n'est pas inséré, renvoyant un itérateur à cet élément existant ( si la fonction renvoie une valeur).
            Une autre façon d'insérer des éléments dans une carte consiste à utiliser la fonction membre map::operator[] .
            ATTENTION : 'position' n'est que un indice et il ne force pas l'insertion du nouvel élément à cette position dans le conteneur map (les éléments d'une map suivent toujours un ordre spécifique en fonction de leur clé).
        */
            ft::pair<iterator,bool> insert(const value_type & val) {

                ft::pair<node_ptr, bool> tmp = _tree.insert(val);
                return ft::make_pair(iterator(tmp.first, _tree.getSent(), _tree.getRoot()), tmp.second);
            }

            iterator                insert(iterator position, const value_type & val) {

                (void)position;
                ft::pair<node_ptr, bool> tmp = _tree.insert(val);
                return iterator(tmp.first, _tree.getSent(), _tree.getRoot());
            }

            template <class InputIterator>
            void                    insert(InputIterator first, InputIterator last) {

                _tree.insert(first, last);
            }


        /*
            Supprime du conteneur map soit un élément unique, soit une plage d'éléments ( [first,last) ).
            Cela réduit efficacement la taille du conteneur par le nombre d'éléments retirés, qui sont détruits.
        */
            void                    erase(iterator position) {

                _tree.erase(position.node());
            }

            size_type               erase(const key_type & k) {

                iterator    position = find(k);
                bool        ret = _tree.erase(position.node());
                return (ret == false ? 0 : 1);
            }

            void                    erase(iterator first, iterator last) {

                for (; first != last; first++)
                    _tree.erase(first);
            }


        /*
            Échange le contenu du conteneur par le contenu de x , qui est une autre map du même type.
            Les tailles peuvent différer.
            Après l'appel à cette fonction membre, les éléments de ce conteneur sont ceux qui étaient dans x avant l'appel,
            et les éléments de x sont ceux qui étaient dans this .
            Tous les itérateurs, références et pointeurs restent valides pour les objets échangés.
        */
            void                    swap(map & x) {

                _tree.swap(x._tree);
            }


        /*
            Supprime tous les éléments du conteneur map (qui sont détruits),
            laissant le conteneur avec une taille de 0 .
        */
            void                    clear() {

                _tree.clear();
            }


        /*
            Renvoie une copie de l' objet de comparaison utilisé par le conteneur pour comparer les clés .
        */
            key_compare             key_comp() const {

                return _key_comp;
            }

            value_compare           value_comp() const {

                return _value_comp;
            }

            iterator                find(const key_type & k) {

                iterator tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    return end();
                return (tmp);
            }

            const_iterator          find(const key_type & k) const {

                const_iterator tmp = lower_bound(k);
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                if (tmp == end() || _value_comp(p, tmp.node()->value))
                    return end();
                return (tmp);
            }


        /*
            Recherche dans le conteneur des éléments avec une clé équivalente à k
            et renvoie le nombre de correspondances.
            Étant donné que tous les éléments d'un conteneur de carte sont uniques,
            la fonction ne peut renvoyer que 1 (si l'élément est trouvé) ou zéro (sinon).
        */
            size_type               count(const key_type & k) const {

                return (find(k) == end() ? 0 : 1);
            }


        /*
            Renvoie un itérateur pointant sur le premier élément du conteneur
            dont la clé n'est pas considérée comme antérieure à k
            (c'est-à-dire qu'elle est équivalente ou postérieure).
            La fonction utilise son objet de comparaison interne ( key_comp ) pour déterminer cela,
            renvoyant un itérateur au premier élément pour lequel key_comp(element_key,k) renverrait false .
            Si la classe map est instanciée avec le type de comparaison par défaut ( less ),
            la fonction renvoie un itérateur au premier élément dont la clé n'est pas inférieure à k .
        */
            iterator                lower_bound(const key_type & k) {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (!_value_comp(x->value, p))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return iterator(y, _tree.getSent(), _tree.getRoot());
            }

            const_iterator          lower_bound(const key_type & k) const {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (!_value_comp(x->value, p))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return const_iterator(y, _tree.getSent(), _tree.getRoot());
            }


        /*
            Renvoie un itérateur pointant sur le premier élément du conteneur
            dont la clé est considérée comme allant après k .
            La fonction utilise son objet de comparaison interne ( key_comp ) pour déterminer cela,
            renvoyant un itérateur au premier élément pour lequel key_comp(k,element_key) renverrait true .
            Si la classe map est instanciée avec le type de comparaison par défaut ( less ),
            la fonction renvoie un itérateur au premier élément dont la clé est supérieure à k .
        */
            iterator                upper_bound(const key_type & k) {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (_value_comp(p, x->value))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return iterator(y, _tree.getSent(), _tree.getRoot());
            }

            const_iterator          upper_bound(const key_type & k) const {

                node_ptr x = _tree.getRoot();
                node_ptr y =  _tree.getSent();

                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());

                while (x != _tree.getSent())
                {
                    if (_value_comp(p, x->value))
                    {
                        y = x;
                        x = x->left;
                    }
                    else
                        x = x->right;
                }
                return const_iterator(y, _tree.getSent(), _tree.getRoot());
            }


        /*
            Renvoie les limites d'une plage qui inclut tous les éléments du conteneur
            qui ont une clé équivalente à k .
            Étant donné que les éléments d'un conteneur de carte ont des clés uniques,
            la plage renvoyée contiendra au plus un élément.
            Si aucune correspondance n'est trouvée, la plage renvoyée a une longueur de zéro,
            les deux itérateurs pointant sur le premier élément dont la clé est considérée
            comme allant après k selon l' objet de comparaison interne du conteneur ( key_comp ).
        */
            pair<iterator,iterator>                 equal_range(const key_type & k) {

                return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));  
            }

            pair<const_iterator,const_iterator>     equal_range(const key_type & k) const {

                return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
            }

            allocator_type  get_allocator() const {

                return _tree.get_allocator();
            }

        private:

            /*RBT*/RedBlackTree<value_type, value_compare, pair_allocator_type>              _tree;
            allocator_type  _alloc;
            key_compare     _key_comp;
            value_compare   _value_comp;

    };

    // relational operators

    template<class Key, class T, class Compare, class Alloc>
    bool    operator==( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        if (lhs.size() != rhs.size())
            return false;
        return (equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator!=( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc >& rhs ) {
        
        return !(lhs == rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator<( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator<=( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator>( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return (rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    operator>=( const map<Key, T, Compare, Alloc> & lhs,
                    const map<Key, T, Compare, Alloc> & rhs ) {

        return !(lhs < rhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    void    swap(map<Key, T, Compare, Alloc> & x, map<Key, T, Compare, Alloc> & y) {

        x.swap(y);
    }

}

#endif