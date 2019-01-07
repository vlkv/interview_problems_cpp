/*
4.2 Minimal Tree: Given a sorted (increasing order) array with unique integer elements, 
write an algorithm to create a binary search tree with minimal height.
*/
#include <memory>


template<class T>
struct Node {
    T _value;
    std::shared_ptr<Node<T>> _left;
    std::shared_ptr<Node<T>> _right;

    Node<T>(T value) : _value(value) {}
};

template<class T>
class MinimalTree {
public:
    static std::shared_ptr<Node<T>> buildTree(T* array, int ibeg, int iend) {
        if (ibeg == iend) {
            return std::shared_ptr<Node<T>>(nullptr);
        }
        int imid = (ibeg + iend) / 2;
        std::shared_ptr<Node<T>> root = std::shared_ptr<Node<T>>(new Node<T>(array[imid]));
        root->_left = buildTree(array, ibeg, imid);
        root->_right = buildTree(array, imid + 1, iend);
        return root;
    }
};
