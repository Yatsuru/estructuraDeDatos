
#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"


template <class T>
class BinaryTree {
private:
    BNode<T> * root = nullptr;

public:
    BinaryTree() {}
    virtual ~BinaryTree();

    bool empty() const;

    void clear();
    void clear(BNode<T> * node);

    BNode<T> * getRoot() const;
    void setRoot(BNode<T> * node);

    bool insert(BNode<T> * parent, T value);
    bool insert(BNode<T> * parent, BNode<T> * value);

    bool insertPre(T value);
    bool insertIn(T value);

    void preOrder() const;
    void preOrder(BNode<T> * node) const;

    void inOrder() const;
    void inOrder(BNode<T> * node) const;

    void postOrder() const;
    void postOrder(BNode<T> * node) const;

    void isLeaf() const;
    void isLeaf(BNode<T> * node) const;
    int treeLeavesCount() const;

    void ancestors(BNode<T> * node) const;
    bool isBrothers(BNode<T> * node1,BNode<T> * node2) const;

    int height(BNode<T> * node) const;
    int treeHeight() const;

    int max(int x, int y) const;
    //void copyTreeUPD(BNode<T> * &copiedTreeRoot, BNode<T> * otherTreeRoot);
    int treeNodeCount() const;


    BinaryTree(const BinaryTree<T>& otherTree);
    //const BinaryTree<T>& operator= (const BinaryTree<T>&);
    //virtual void search(const T& searchItem) const = 0;


    int intPreOrder() const;
    int intPreOrder(BNode<T> * node) const;
    int reflex(BNode<T> * node);
    int reflex();


    //bool isSymmetric();
    //BNode<T> * copy(const BNode<T> * node);
    bool operator==(const BinaryTree<T> & a) const;

    //BinaryTree<T> * copy();
    //BNode<T> * copy(const BNode<T> * node);
    int intPreOrderSime() const;
    int intPreOrderSime(BNode<T> * node, int nodos) const;
    bool sime2() const;
    bool sime2(BNode<T> * nodeA, BNode<T> * nodeB ) const;
};

template <class T>
bool BinaryTree<T>::sime2() const
{
    if (!empty())
        sime2(root->getLeft(), root->getRight() );
    else
        return true;
}

template <class T>
bool BinaryTree<T>::sime2(BNode<T> * nodeA, BNode<T> * nodeB ) const
{
    if (!nodeA && !nodeB) return true;

    if ((!nodeA && nodeB) || (nodeA && !nodeB)) return false;

    if ( sime2(nodeA->getLeft(), nodeB->getRight())) {
        return sime2(nodeA->getRight(), nodeB->getLeft());
    }
    else
        return false;
}



template <class T>
int BinaryTree<T>::intPreOrderSime() const
{
    intPreOrderSime(root, 0);
}

template <class T>
int BinaryTree<T>::intPreOrderSime(BNode<T> * node, int nodos) const
{
    static int suma = 0;
    static int l = 0;
    static int r = 0;
    bool sime;

    if (node) {

        /* Procesar el nodo */
        //return node->getInfo();
         suma += node->getInfo();
        //std::cout << *node << std::endl;

        /* Invocar a los hijos */
        l = intPreOrderSime(node->getLeft(), nodos++);
        r = intPreOrderSime(node->getRight(), nodos++);

    }
    return nodos;
}


template <class T>
BinaryTree<T>::~BinaryTree()
{
    clear();
}

template <class T>
bool BinaryTree<T>::empty() const
{
    return root == nullptr;
}

template <class T>
void BinaryTree<T>::clear()
{
    clear(root);
}

template <class T>
void BinaryTree<T>::clear(BNode<T> * node)
{
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());

        delete node;
    }
}

template <class T>
BNode<T> * BinaryTree<T>::getRoot() const
{
    return root;
}

template <class T>
void BinaryTree<T>::setRoot(BNode<T> * node)
{
    if (!empty()) {
        node->setLeft(root);
        root->setParent(node);
        root = node;
    }
    else {
        root = node;
    }
}

template <class T>
bool BinaryTree<T>::insert(BNode<T> * parent, T value)
{
    BNode<T> * node = new BNode<T>(value);
    bool inserted = insert(parent, node);

    if (!inserted) delete node;

    return inserted;
}

template <class T>
bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
{
    bool inserted = false;

    if (empty() || !parent) {
        setRoot(value);
        inserted = true;
    }
    else {
        if (!parent->getLeft()) {
            parent->setLeft(value);
            value->setParent(parent);
            inserted = true;
        }
        else if (!parent->getRight()) {
            parent->setRight(value);
            value->setParent(parent);
            inserted = true;
        }
    }

    return inserted;
}

int x = 0;
template <class T>
bool BinaryTree<T>::insertPre(T value){
  if(x == 0){
    BNode<T> * node = new BNode<T>(value);
    bool inserted = insert(node->getLeft(), node);
    if (!inserted) delete node;
    x = 1;
    return inserted;
  }else if(x == 1){
    BNode<T> * node = new BNode<T>(value);
    bool inserted = insert(node->getRight(), node);
    if (!inserted) delete node;
    x = 0;
    return inserted;
  }
}

int y = 0;
template <class T>
bool BinaryTree<T>::insertIn(T value){
  if(y == 0){
    BNode<T> * node = new BNode<T>(value);
    bool inserted = insert(node->getLeft(), node);
    if (!inserted) delete node;
    y = 1;
    return inserted;
  }else if(y == 1){
    BNode<T> * node = new BNode<T>(value);
    bool inserted = insert(node->getParent(), node);
    if (!inserted) delete node;
    y = 2;
    return inserted;
  }else if(y == 2){
    BNode<T> * node = new BNode<T>(value);
    bool inserted = insert(node->getRight(), node);
    if (!inserted) delete node;
    y = 0;
    return inserted;
  }
}



template <class T>
void BinaryTree<T>::preOrder() const
{
    preOrder(root);
}

template <class T>
void BinaryTree<T>::preOrder(BNode<T> * node) const
{
    if (node) {
        /* Procesar el nodo */
        std::cout << *node << std::endl;

        /* Invocar a los hijos */
        preOrder(node->getLeft());
        preOrder(node->getRight());

    }
}

template <class T>
int BinaryTree<T>::intPreOrder() const
{
    intPreOrder(root);
}

template <class T>
int BinaryTree<T>::intPreOrder(BNode<T> * node) const
{
    static int suma = 0;
    if (node) {

        /* Procesar el nodo */
        //return node->getInfo();
         suma += node->getInfo();
        //std::cout << *node << std::endl;

        /* Invocar a los hijos */
        suma = intPreOrder(node->getLeft());
        suma = intPreOrder(node->getRight());

    }
    return suma;
}

template <class T>
void BinaryTree<T>::inOrder() const
{
    inOrder(root);
}

template <class T>
void BinaryTree<T>::inOrder(BNode<T> * node) const
{
    if (node) {

        /* Invocar al hijo izquierdo */
        inOrder(node->getLeft());

        /* Procesar el nodo */
        std::cout << *node << std::endl;

        /* Invocar al hijo derecho */
        inOrder(node->getRight());
    }
}

template <class T>
void BinaryTree<T>::postOrder() const
{
    postOrder(root);
}

template <class T>
void BinaryTree<T>::postOrder(BNode<T> * node) const
{
    if (node) {
        /* Invocar a los hijos */
        postOrder(node->getLeft());
        postOrder(node->getRight());

        /* Procesar el nodo */
        std::cout << *node << std::endl;
    }
}

template <class T>
void BinaryTree<T>::isLeaf() const
{
    isLeaf(root);
}

template <class T>
void BinaryTree<T>::isLeaf(BNode<T> * node) const
{
    if (node) {
        if (!node->getLeft() && !node->getRight()) {
            std::cout << *node << std::endl;
        }
        else {
            isLeaf(node->getLeft());
            isLeaf(node->getRight());
        }
    }
}

template <class T>
void BinaryTree<T>::ancestors(BNode<T> * node) const
{
    if (node) {
        std::cout << *node << " -> ";
        ancestors(node->getParent());
    }
}


/*template <class T>
bool BinaryTree<T>::isBrothers(BNode<T> * node1, BNode<T> * node2) const{
    if (node1 == node->getParent()->getRight()) {
        std::cout << "Es hermano"<< std::endl;
        std::cout << *node->getParent()->getRight();
        return true;
    }else if (node2 == node->getParent()->getLeft()){
        std::cout << "Es hermano"<< std::endl;
        std::cout << *node->getParent()->getLeft();
        return true;
    }else{
        std::cout << "no es hermano"<< std::endl;
        return false;
    }
}*/

template <class T>
int BinaryTree<T>::max(int x, int y) const {
    if(x >= y){
        return x;
    }else{
        return y;
    }
}

template <class T>
int BinaryTree<T>::height(BNode<T> * node) const{
   if(node == nullptr){
       return 0;
   } else{
       return 1 + max(height(node->left), height(node->right));
   }
}

/*
template <class T>
void BinaryTree<T>::copyTreeUPD(BNode<T> * &copiedTreeRoot, BNode<T> * otherTreeRoot){
    if(otherTreeRoot == nullptr){
        copiedTreeRoot = nullptr;
    }else{
        copiedTreeRoot = new BNode<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTreeUPD(copiedTreeRoot->right, otherTreeRoot->right);
        copyTreeUPD(copiedTreeRoot->left, otherTreeRoot->left);

    }
}

*/

template <class T>
int BinaryTree<T>::treeHeight() const{
    return height(root);
}

template <class T>
int BinaryTree<T>::treeNodeCount() const{
    return nodeCount(root);
}

template <class T>
int BinaryTree<T>::treeLeavesCount() const{
    return leavesCount(root);
}

/*
template <class T>
const BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& otherTree){
    if (this != &otherTree){
        if (root != NULL)
            clear(root);
        if (otherTree.root == NULL)
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }
    return *this;
}
*/



template <class T>
int BinaryTree<T>::reflex(BNode<T> * node)
{
    if (node) {
        reflex(node->getLeft());
        reflex(node->getRight());

        //Intercambiar derecho por izquierdo
        BNode<T> *aux = node->getRight();
        node->setRight(node->getLeft());
        node->setLeft(aux);
    }

}

template <class T>
int BinaryTree<T>::reflex()
{
   reflex(root);


}





/*


template <class T>
BNode<T> * BinaryTree<T>::copy(const BNode<T> * node){
    if (node){
        BNode<T> * output = new BNode<T>();
        output->setInfo(node->getInfo());
        output->setRight(copy(node->getRight()));
        output->setLeft(copy(node->getLeft()));
        return output;
    }
    return nullptr;
}


template <class T>
bool BinaryTree<T>::isSymmetric(){
    BinaryTree<T> * reflection = this->copy();
    reflection->reflect();
    bool output = (*this == *reflection);
    delete reflection;
    return output;
}


template <class T>
bool BinaryTree<T>::operator == (const BinaryTree<T> & b) const{
    return equals(this, &b);
}

template <class T>
BinaryTree<T> * BinaryTree<T>::copy(){
    BinaryTree<T> * output = new BinaryTree<T>();
    BNode<T> * node = new BNode<T>();
    node = copy(this->getRoot());
    output->insert(nullptr, node);
    return output;
}

template <class T>
BNode<T> * BinaryTree<T>::copy(const BNode<T> * node){
    if (node){
        BNode<T> * output = new BNode<T>();
        output->setInfo(node->getInfo());
        output->setRight(copy(node->getRight()));
        output->setLeft(copy(node->getLeft()));
        return output;
    }
    return nullptr;
}*/

#endif