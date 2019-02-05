#ifndef MIN_MAX_HEAP_HPP__
#define MIN_MAX_HEAP_HPP__

#include <vector>
#include <stdexcept>

template <class T> class MinMaxHeap {
    std::vector<T> _nodes;
public:
    MinMaxHeap() {
    }

    void add(const T& t) {
        _nodes.push_back(t);
        heapifyUp(_nodes.size() - 1);
    }

    T pop() {
        if (_nodes.size() == 0) {
            throw std::runtime_error("Heap is empty, cannot pop element");
        }
        T root = _nodes[0];
        T newRoot = _nodes[_nodes.size() - 1];
        _nodes.pop_back();
        if (_nodes.size() > 0) {
            _nodes[0] = newRoot;
            heapifyDown(0);
        }
        return root;
    }

    size_t size() {
        return _nodes.size();
    }

private:
    void heapifyUp(int i) {

        int parent = parentOf(i);
        while (parent >= 0 && !isOK(_nodes[parent], _nodes[i])) {
            swapNodes(parent, i);
            i = parent;
            parent = parentOf(i);
        }
    }

    bool isOK(const T& parent, const T& child) { // TODO: take comparator from ctor
        return parent >= child;
    }

    void swapNodes(int i, int j) {
        T tmp = _nodes[j];
        _nodes[j] = _nodes[i];
        _nodes[i] = tmp;
    }

    void heapifyDown(int i) {
        do {
            int leftChild = leftChildOf(i);
            int rightChild = rightChildOf(i);
            if (leftChild == -1) {
                return;
            }
            if (rightChild == -1) {
                if (!isOK(_nodes[i], _nodes[leftChild])) {
                    swapNodes(i, leftChild);
                }
                return;
            }
            bool isLeftOK = isOK(_nodes[i], _nodes[leftChild]);
            bool isRightOK = isOK(_nodes[i], _nodes[rightChild]);
            if (!isLeftOK && !isRightOK) {
                bool isLeftWillBeTheRoot = isOK(_nodes[leftChild], _nodes[rightChild]);
                if (isLeftWillBeTheRoot) {
                    swapNodes(i, leftChild);
                    i = leftChild;
                } else {
                    swapNodes(i, rightChild);
                    i = rightChild;
                }
            } else if (!isLeftOK) {
                swapNodes(leftChild, i);
                i = leftChild;
            } else if (!isRightOK) {
                swapNodes(rightChild, i);
                i = rightChild;
            } else {
                return;
            }
        } while (i < _nodes.size());
    }

    int parentOf(int i) {
        return (i - 1) / 2;
    }
    
    int leftChildOf(int i) {
        int child = 2 * i + 1;
        return child < _nodes.size() ? child : -1;
    }

    int rightChildOf(int i) {
        int child = 2 * i + 2;
        return child < _nodes.size() ? child : -1;
    }
};

#endif
