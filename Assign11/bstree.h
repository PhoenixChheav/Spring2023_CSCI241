//***************************************************************
//
//  bstree.h
//  CSCI 241 Assignment 11
//
//  Created by Phoenix Chheav (z1966108) and Sam Normoyle (z-id: Z1980761)
//
//***************************************************************

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

using namespace std;

template <class K, class V>
struct node{
    K key;
    V value;
    node<K, V>* l_subtree;
    node<K, V>* r_subtree;

    node(const K& key = K(), const V& value = V(), node<K, V>* l_subtree = nullptr, node<K, V>* r_subtree = nullptr){
        this->key = key;
        this->value = value;
        this->l_subtree = l_subtree;
        this->r_subtree = r_subtree;
    }
};

template <class K, class V>
class bstree{
    private:
        node<K, V>* root; //tree node
        size_t t_size;

        //extra method
        node<K, V>* clone(node<K, V>*);//DONE
        void preorder(node<K, V>*) const; //recursive DONE
        void inorder(node<K, V>*) const; //recursive DONE
        void postorder(node<K, V>*) const; //recursive //DONE
        void print_level(node<K, V>*, int) const; //DONE
        size_t height(node<K, V>* ) const; //DONE
        const K& min(node<K, V> *) const; //DONE
        const K& max(node<K, V> *) const; //DONE

    public:
        bstree(); //constructor //DONE
        ~bstree(); //destructor //DONE
        bstree(const bstree<K, V>& ); //copy constructor //DONE
        bstree<K, V>& operator=(const bstree<K, V>& ); //overload //DONE
        void clear(); //DONE
        size_t size() const; //DONE
        size_t height() const; //NOT YET
        bool empty() const; //DONE
        const K& min() const;
        const K& max() const;
        bool insert(const K&, const V& ); //DONE
        bool remove(const K&); //DONE
        const node<K, V>* find(const K& ) const; //DONE
        void preorder() const; //DONE
        void inorder() const; //DONE
        void postorder() const; //DONE
        void level_order() const; //DONE

        //extra method
        //node<K, V>* clone(const bstree<K, V>*) const;//DONE
        void destroy(node<K, V>*); //DONE
};


/**
 * @brief Construct a new bstree<K, V>::bstree object
 * 
 *  Constructor
 */
template <class K, class V>
bstree<K, V>::bstree(){
    root = nullptr;
    t_size = 0;
}

/**
 * @brief Destroy the bstree<K, V>::bstree object
 * 
 * Destructor
 */
template <class K, class V>
bstree<K, V>::~bstree(){
    clear();
}

/**
 * @brief Construct a new bstree<K, V>::bstree object
 * 
 * Copy Constructor
 * 
 * @param x reference to a constant bstree
 */
template <class K, class V>
bstree<K, V>::bstree(const bstree<K, V>& x){
    //copy the order bstree object's size
    t_size = x.t_size;

    //copy the nodes of the other bstree object
    root = clone(x.root);
}

/**
 * @brief operator=(const bstree<K, V>& x) 
 * 
 * Overload function
 * 
 * @param x reference to a constant bstree
 * @return bstree<K, V>& 
 */
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x){
    if(this != &x){
        clear(); //Make the left bstree object empty
        t_size = x.t_size; // copy the other bstree object's size
        root = clone(x.root); //copy the nodes of the other bstree object
    }
    return *this;
}

/**
 * 
 * @brief clear(): set the tree back to empty state
 * 
 */
template <class K, class V>
void bstree<K, V>::clear(){
    //set tree back to empty size
    destroy(root);
    //delete all nodes in tree
    root = nullptr;
    //set size back to 0
    t_size = 0;
}

/**
 * @brief size() const
 * 
 * @return t_size return the tree size
 */
template <class K, class V>
size_t bstree<K, V>::size() const {
    return t_size;
}

//height()
template <class K, class V>
size_t bstree<K, V>::height() const{
    return height(root);
}

//empty()
template <class K, class V>
bool bstree<K, V>::empty() const{
    if(t_size == 0){
        return true;
    }
    return false;
}

/**
 * @brief const K& min(node<K, V> *root): minimum key in the tree
 * 
 * @tparam K 
 * @tparam V 
 * @return const K& 
 */
template <class K, class V>
const K& bstree<K, V>::min() const{
    return min(root);
    //return min key in tree
}

template <class K, class V>
const K& bstree<K, V>::min(node<K, V> *root) const{
    if(root->l_subtree != nullptr){
        return min(root->l_subtree);
    }
    return root -> key;
    //return min key in tree
}


template <class K, class V>
const K &bstree<K, V>::max(node<K, V> *root) const
{
    if (root->r_subtree != nullptr)
    {
        return max(root->r_subtree);
    }
    return root->key;
}
//max()
template <class K, class V>
const K& bstree<K, V>::max() const{

    return max(root);
    //return max key
}

/**
 * @brief bool insert(const K& key, const V& value): attempt to insert a key and value into the binary search tree
 *                                                   if the key alr exist, return fail, otherwise a new tree node containing key and value inserted
 * 
 * @param key a key to insert
 * @param value value to insert
 * @return true if the insertion success
 * @return false if the insertion fail
 */
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value){
    //root: pointer to the root node of the tree(nullptr if node is empty)
    //t_size: tree size
    //p pointer to a tree node
    //parent: pointer to the parent node of p(nullptr if p points to the root node)
    //new_node: pointer used to create a new tree node
    // node<K, V>* root = nullptr;
    //size_t t_size = 0;
    node<K, V>* p = root;
    node<K, V>* parent = nullptr;

    //Search the tree for a null link or a duplicate key(if duplicates are disallowed)
    while(p != nullptr && key != p->key){
        parent = p;
        if(key < p->key){
            p = p->l_subtree;
        }else{
            p = p->r_subtree;
        }
    }

    //if duplicates are disallowed, signal that insertion has failed
    if(p != nullptr){
        return false;
    }

    //Otherwise, create a tree node and insert it as a new leaf node
    //Create a new tree node new_node to contain key and value
    node<K, V>* new_node = new node<K, V>(key, value);

    if(parent == nullptr){
        root = new_node;
    }else{
        if(new_node->key < parent->key){
            parent->l_subtree = new_node;
        }else{
            parent->r_subtree = new_node;
        }
    }

    t_size++;

    //If duplicates are disallowed, signal that insertion has succeed
    return true;
}

/**
 * @brief bool remove(const K& key): attempt to remove the specifiedkey to binary search tree
 * 
 * @param key key to remove from the tree
 * @return true if the node matching with the key
 * @return false if the key is not inthe tree
 */
template <class K, class V>
bool bstree<K, V>::remove(const K& key){
    node<K, V>* replace;
    node<K, V>* replace_parent;

    //start at the root of tree and search for the key to delete
    node<K, V>* p = root;
    node<K, V>* parent = nullptr;
    while(p != nullptr && key != p->key){
        parent = p;
        if(key < p->key){
            p = p->l_subtree;
        }else{
            p = p->r_subtree;
        }
    }

    //if the node to delete was not found, signal failure
    if(p == nullptr){
        return false;
    }

    if(p->l_subtree == nullptr){
        //Case 1a: p has no children. Replace p with its right child(which is nullptr)
        // - or - 
        //Case 1b: p has no left child but has a right child. Replace p with its right child
        replace = p->r_subtree;
    }else if(p->r_subtree == nullptr){
        //Case 2: p has a left child but no right child. Replace p with its left child
        replace = p->l_subtree;
    }else{
        //Case 3: p has 2 children. Replace p with its inorder predecessor.

        //Go left...
        replace_parent = p;
        replace = p->l_subtree;

        //...then all the way to the right
        while(replace->r_subtree != nullptr){
            replace_parent = replace;
            replace = replace->r_subtree;
        }

        //If we were able to go to the right, make the replacemnt node's left child the right child of its parent.
        //Then make the left child of p the replacement's left child
        if(replace_parent != p){
            replace_parent->r_subtree = replace->l_subtree;
            replace->l_subtree = p->l_subtree;
        }

        //Make the right child of p the replacement's right child
        replace->r_subtree = p->r_subtree;
    }

    //Connect replacement nnode to the parent node of p(or the root if p has no parent)
    if(parent == nullptr){
        root = replace;
    }else{
        if(p->key < parent->key){
            parent->l_subtree = replace;
        }else{
            parent->r_subtree = replace;
        }
    }

    //Delete the node, decrement the tree size, and signal success
    delete[] p; //Delete the node pointed to by p
    t_size--;
    return true;
}

/**
 * @brief const node<K, V>* find(const K& key) const : attempt to find specified key in binary search tree
 * 
 * @param key a key for which to search
 * @return nullptr if key is not in the tree
 */
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const{
    //root: pointer to the root node of the tree(nullptr if tree is empty)
    //p:    pointer to a tree node

    //Start at the root of the tree
    node<K, V>* p = root;
    //search the tree for a null link or a matching key
    while(p != nullptr && key != p->key){
        if(key < p->key){
            p = p->l_subtree;
        }else{
            p = p->r_subtree;
        }
    }
    //p either points to the node with a matching key or is nullptr if the key is not in the tree
    return p;
}

/**
 * @brief void preorder(node<K, V>* root): recursive preorder method
 * 
 * @param root pointer to tree node
 */
template <class K, class V>
void bstree<K, V>::preorder(node<K, V>* root) const{
    if(root != nullptr){
        //Visit the node pointer to by root
        cout << root->key << ": " << root->value << endl;
        preorder(root->l_subtree);
        preorder(root->r_subtree);
    }
}

/**
 * 
 * @brief void preorder() const: call the recursive preorder in
 *  
 */
template <class K, class V>
void bstree<K, V>::preorder() const{
    preorder(root);
}


/**
 * @brief void inorder(node<K, V>* root): recursive inorder traversals
 * 
 * @param root pointer to tree node 
 */
template <class K, class V>
void bstree<K, V>::inorder(node<K, V>* root) const{
    if(root != nullptr){
        inorder(root->l_subtree);
        cout << root->key << ": " << root->value << endl; //visit the node pointed to by p
        inorder(root->r_subtree);
    }
}
//inorder
template <class K, class V>
void bstree<K, V>::inorder() const{
    inorder(root);
}

/**
 * @brief void postorder(node<K, V>* root): recursive postorder
 * 
 * @param root pointer to tree node
 */
template <class K,  class V>
void bstree<K, V>::postorder(node<K, V>* root) const{
    if(root != nullptr){
        postorder(root->l_subtree);
        postorder(root->r_subtree);
        cout << root->key << ": " << root->value << endl;
    }
}
//postorder
template <class K, class V>
void bstree<K, V>::postorder() const{
    postorder(root);
}

/**
 * 
 * @brief void level_order() const: iteraive level order
 * 
 */
template <class K, class V>
void bstree<K, V>::level_order() const{
    //root: pointer to the root node of the tree (nullptr if tree is empty)
    //h:    computed height of the tree (i.e number of levels)
    //i:    loop counter

    size_t h = height(root);

    size_t i = 1;
    while(i <= h){
        print_level(root, i);
        i++;
    }
}

/**
 * @brief void print_level(node<K, V>* root, int level)
 *
 * @param root pointer to tree node
 * @param level level number
 */
template<class K, class V>
void bstree<K, V>::print_level(node<K, V>* root, int level) const{
    if(root == nullptr){
        return;
    }

    if(level == 1){
        cout << root->key << ": " << root->value << endl;
    }else if(level > 1){
        print_level(root->l_subtree, level-1);
        print_level(root->r_subtree, level-1);
    }
}

/**
 * @brief void height(node<K, V> root)
 * 
 * @param root 
 * @return height of right or left tree
 */
template<class K, class V>
size_t bstree<K, V>::height(node<K, V>* root) const{
    //l_height: computed height of node's left subtree
    //r_height: computed height of node's right subtree
    size_t l_height = 0;
    size_t r_height = 0;

    if(root == nullptr){
        return 0;
    }

    l_height = height(root->l_subtree);
    r_height = height(root->r_subtree);

    if(l_height > r_height){
        return l_height + 1;
    }else{
        return r_height + 1;
    }
}

/**
 * @brief destroy(node<K, V>* root): Recursively deletes the nodes of a bstree object
 *                                   modified version of a postorder traversal of the tree
 * 
 * @param root pointer to a tree node
 */
template <class K, class V>
void bstree<K, V>::destroy(node<K, V>* root){
    if(root != nullptr){
        //recursively destroy the left and right subtrees of the node pointed to by root
        destroy(root->l_subtree);
        destroy(root->r_subtree);

        //delete the node pointed to by root
        delete[] root;
    }
}

/**
 * @brief clone(node<K, V>* root): recursively copies the node of a bstree
 *                                 modified version of a preorder traversal of the tree
 * 
 * @param root pointer to the tree node
 * @return node<K, V>* 
 */
template <class K, class V>
node<K, V>* bstree<K, V>::clone(node<K, V>* root){
    if(root != nullptr){
        //make a copy of the node pointed to by root
        //Allocate a new treenode, new_node
        node<K, V>* new_node = new node<K, V>(root->key, root->value);
        // new_node->key = root->key;
        // neW_node->value = root->value;

        //recursively copy the left and right subtrees of the node pointed to by p
        new_node->l_subtree = clone(root->l_subtree);
        new_node->r_subtree = clone(root->r_subtree);

        return new_node;
    }else{
        return nullptr;
    }
}


#endif