#ifndef BIN_STABLO_H_INCLUDED
#define BIN_STABLO_H_INCLUDED

enum ErrorCode { success, duplicate, notfound};         //uvodi simbolicka imena --- konstante

template <typename T>
struct Node
{
// konstruktori
    Node();
    Node(T const &);
// podaci
    Node *left;
    Node *right;
    T data;
};

template <typename T>
class BinarySTree
{
public:
    /** Konstruktor. Kreira prazno stablo. */
    BinarySTree();                                                  /////////////
    /** Destruktor. */
    ~BinarySTree(){ clear(); }
    /** Kopirati za sada "ne znamo". */
    BinarySTree(BinarySTree const &) = delete;              //izbrisali smo copy-kostruktor
    /** Vraća true ako je stablo prazno. */
    bool empty() const;                                             //////////////
    /** Obilazi stablo u pre-order poretku.
     *  Na svakom čvoru x poziva visit(x->data).
     */
    template <typename Funct>
    void preOrder(Funct visit){ preOrder(root, visit); }
    /** Isto, ali postorder. */
    template <typename Funct>
    void postOrder(Funct visit){ postOrder(root, visit); }
    /** Isto, ali inorder. */
    template <typename Funct>
    void inOrder(Funct visit) { inOrder(root, visit); }
    /** Broj elemenata stabla. */
    int size();                                                     /////////////////
    /** Eliminiraj (dealociraj) sve elemente stabla. Za dodatne bodove. */
    void clear();
    /** Ubaci element u stablo. */
    ErrorCode insert(T const & t){ return insert(root,t); }
    /** Da li je element u stablu? */
    bool isInTree(T const & t);                                           //////////
    /** Izbaci element iz stabla. Za dodatne bodove.*/
    ErrorCode remove(T const & t);                                         //delete
protected:
    Node<T> *root;
private:

    // tu dodavat svoje f-je tipa serch

    /** Insertiraj novi element ako već nije u stablu.
     * Budući da metoda mijenja veze među elementima ona mora uzimati
     * referencu na pokazivač! Njoj treba pristup pokazivačima koji
     * ostvaruju veze, a ne njihovim kopijama. Vraća success kad uspije,
     * odnosno duplicate kada je element već u stablu.
     */
    ErrorCode insert(Node<T> * & root, T const & t);                  ////////////////////  //new ///referenca na root pointer, da je mozmo promjenit ako ubacujem root

    /** Ukloni element na koji pokazuje root i vrati success. Ako je
     * root = nullptr ne radi ništa i vrati notfound. */
    ErrorCode remove(Node<T> * & root);

    /** Rekurzivni preorder obilazak. */
    template <typename Funct>
    void preOrder(Node<T> * root, Funct visit);
    /** Rekurzivni postorder obilazak. */
    template <typename Funct>
    void postOrder(Node<T> * root, Funct visit);
    /** Rekurzivni inorder obilazak. */
    template <typename Funct>
    void inOrder(Node<T> * root, Funct visit);

    int preorder_recursive(Node<T> * sub_root);             //dodana f-ja
    Node<T>* search(Node<T> * sub_root, T temp);            //dodana f-ja
    Node<T>* brisi(Node<T> * & sub_root, T el);             //dodana f-ja
    Node<T>* minimalna(Node<T> * & sub_root);               //dodana f-ja
};


#include "bin_stablo_impl.h"

#endif // BIN_STABLO_H_INCLUDED
