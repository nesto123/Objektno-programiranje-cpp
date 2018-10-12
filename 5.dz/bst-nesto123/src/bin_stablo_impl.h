#ifndef BIN_STABLO_IMPL_H_INCLUDED
#define BIN_STABLO_IMPL_H_INCLUDED

#include <vector>
///// Implementacija metoda iz Node klase //////////////////////

template <typename T>
Node<T>::Node(){
    left=nullptr;
    right=nullptr;
}


//// Implementacija metoda iz BinaryTree klase //////////////////



template <typename T>
template <typename Funct>
void BinarySTree<T>::preOrder(Node<T> * root, Funct visit)                      ////////
{
    //throw "Not implemented.";
    // sub_root je ili nullptr ili korijen stabla ili korijen podstabla
    if(root != nullptr){
       visit(root->data);
       preOrder(root->left, visit);
       preOrder(root->right, visit);
    }
}
template <typename T>
template <typename Funct>
void BinarySTree<T>::postOrder(Node<T> * root, Funct visit)
{
     //throw "Not implemented.";
    if(root != nullptr){
       postOrder(root->left, visit);
       postOrder(root->right, visit);
       visit(root->data);
    }
}
template <typename T>
template <typename Funct>
void BinarySTree<T>::inOrder(Node<T> * root, Funct visit)
{
     //throw "Not implemented.";
    if(root != nullptr){
       inOrder(root->left, visit);
       visit(root->data);
       inOrder(root->right, visit);

    }
}

template <typename T>                                                   //////////////
BinarySTree<T>::BinarySTree()
{
    root = nullptr;

    /*
     root = new Node<T>;
     root->left = nullptr;
     root->right = nullptr;
*/
}

template <typename T>                                                  /////////////////
bool BinarySTree<T>::empty() const{

    if( root == nullptr )
        return true;
    else
        return false;
}

//dodana f-ja vraća broj elemenata u stablu ---preko preordera----
template <typename T>
int BinarySTree<T>::preorder_recursive(Node<T> * sub_root){
  // sub_root je ili nullptr ili korijen stabla ili korijen podstabla
    static int i= 0;
    if (root == sub_root)
        i = 0;
  if(sub_root != nullptr){
     ++i;//cout << sub_root->data << ",";
     preorder_recursive(sub_root->left);
     preorder_recursive(sub_root->right);
  }
  return i;             ///         vraca broj cvorova
}

template <typename T>
int BinarySTree<T>::size(){                                         ///////////////

    return preorder_recursive(root);
}

template <typename T>
ErrorCode BinarySTree<T>::insert(Node<T> * & root, T const & t){      ////////////////

    if( root == nullptr ){              //za prazno stablo
        root = new Node<T>;
        root->data = t;
        root->right = root->left = nullptr;
        return success;
    }
    if( root->data == t)
        return duplicate;
    if( t < root->data)
        return insert(root->left, t);
        /*{
        if( sroot->left != nullptr )
            return insert(sroot->left, t);
        else{
            sroot->left = new Node<T>;
            sroot = sroot->left;
            sroot->right = sroot->left = nullptr;
            return success;
        }*/
    if( t > root->data )
        return insert(root->right, t);
    else
        return notfound;
}

// dodana f-ja za pretrazivanje stabla --vraca nullptr ako nije naden  element po vrjednosti
//inace vraca pokazivac na taj element
template <typename T>
Node<T>* BinarySTree<T>::search(Node<T> * sub_root, T  temp){

  /*
  // sub_root je ili nullptr ili korijen stabla ili korijen podstabla
  if( sub_root == nullptr )
      return nullptr;
  if(sub_root != nullptr){
      T temp2;
     if( sub_root->data == temp )
         return root;
     temp2 = preorder_recursive(sub_root->left);
     if( temp2 != nullptr )
         return temp2;
     temp2 = preorder_recursive(sub_root->right);
     if( temp2 != nullptr )
         return temp2;
  }
         return nullptr;
    */
   if( sub_root == nullptr || sub_root->data == temp )
       return sub_root;
   if( sub_root->data < temp )
       return search(sub_root->right, temp);
   else
       return search(sub_root->left, temp);
  /* if( temp < sub_root->data )
       return search(sub_root->left, temp);
   else//if( temp > sub_root->data )
       return search(sub_root->right, temp);
       */
}

template <typename T>
bool BinarySTree<T>::isInTree(T const & t){                         ///////////

    if( search(root, t) != nullptr )
        return true;
    else
        return false;
}

//dodana fja, nalazi minimalni node
template <typename T>
Node<T>* BinarySTree<T>::minimalna(Node<T> * & sub_root){
    auto temp = sub_root;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp;
}

//dodana f-ja, rekurzija za brisanje
template <typename T>
Node<T>* BinarySTree<T>::brisi(Node<T> * & sub_root, T el){

    if( sub_root == nullptr )
        return sub_root;
    if( el < sub_root->data )
        sub_root->left = brisi(sub_root->left, el);
    else if( el > sub_root->data )
       sub_root->right = brisi( sub_root->right, el);
    else{
        if( sub_root->left == nullptr ){
            auto temp = sub_root->right;
            delete sub_root;
            return temp;
        }
        if( sub_root->right == nullptr ){
            auto temp = sub_root->left;
            delete sub_root;
            return temp;
        }
        auto temp = minimalna(sub_root->right);
        sub_root->data = temp->data;
        sub_root->right = brisi(sub_root->right, temp->data);

    }
    return sub_root;
}





template<typename T>
void BinarySTree<T>::clear(){
    std::vector<T> vec;
    preOrder([&vec](T x){vec.push_back(x);});

    for( auto x : vec )
        remove(x);
}

template <typename T>
ErrorCode BinarySTree<T>::remove(T const & t){
    if( search(root, t) == nullptr )
        return notfound;
    else{
        root=brisi(root, t);
        return success;
    }
}






#endif // BIN_STABLO_IMPL_H_INCLUDED
