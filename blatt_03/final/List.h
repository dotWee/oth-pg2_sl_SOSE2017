#pragma once

#include "LiNode.h"

template<typename T>
class MyList {
private:
public:
    class iterator {
        LiNode<T> *ptr;
        friend MyList;

        LiNode<T> *get() { return ptr; };
    public:
        bool operator!=(void *ptr) { return ptr != this->ptr; };

        bool operator!=(iterator &ptr) { return ptr.ptr != this->ptr; };

        iterator &operator++() {
            ptr = (ptr != nullptr) ? ptr->next : nullptr;
            return *this;
        };

        T &operator*() { return ptr->value; };

        T *operator->() { return &ptr->value; };

        iterator(LiNode<T> *node) : ptr(node) {};

        iterator() : ptr(nullptr) {};
    };

private:
    int size = 0;
    LiNode<T> *first = nullptr;
    LiNode<T> *last = nullptr;

    iterator getNode(int index) {
        MyList<T>::iterator it = begin();

        if (it != nullptr) {
            for (int i = 0; i < index || it.get()->next != nullptr; ++i, ++it);
        }
        return it;
    }

public:

    iterator begin() { return MyList<T>::iterator(first); };

    iterator end() { return MyList<T>::iterator(); };

    int getSize() { return size; };

    void push_back(const T &);

    T pop_back();

    void push_front(const T &);

    T pop_front();

    void insert(T, int);

    void erase(int);

    void assign(T, int);
};

template<typename T>
inline void MyList<T>::push_back(const T &val) {
    last = new LiNode<T>(val, last, nullptr);

    if (last->prev != nullptr) {
        last->prev->next = last;
    }
    if (nullptr == first) {
        first = last;
    }
    ++size;
}

template<typename T>
inline T MyList<T>::pop_back() {
    T tmp_val;

    if (last != nullptr) {
        tmp_val = last->value;
        LiNode<T> *tmp_ptr = last->prev;

        delete last;
        last = tmp_ptr;
        --size;
    }
    return tmp_val;
}

template<typename T>
inline T MyList<T>::pop_front() {
    T tmp_val;

    if (first != nullptr) {
        tmp_val = first.value;
        LiNode<T> *tmp_ptr = first.next;

        delete first;
        --size;

        first = tmp_ptr;
    }
    return tmp_val;
}

template<typename T>
inline void MyList<T>::insert(T value, int index) {
    MyList<T>::iterator it = getNode(index);

    if (it != nullptr) {
        it
        prev->next = new LiNode<T>(value, it.get()->prev, it.ptr);
        it.get()->prev = it.get()->prev->next;
        ++size;
    }
}

template<typename T>
inline void MyList<T>::erase(int index) {
    List<T>::iterator it = getNode(index);

    if ((it != nullptr) && (it.get()->prev != nullptr)) {
        it.get()->prev->next = it.get()->next;
        it.get()->next->prev = it.get()->prev;
        delete it();
        --size;
    }
}

template<typename T>
inline void MyList<T>::assign(T value, int index) {
    MyList<T>::iterator it = getNode(index);

    if (it != nullptr) {
        *it = value;
    }
}

template<typename T>
inline void MyList<T>::push_front(const T &val) {
    first = new LiNode<T>(val, nullptr, first);

    if (first->next = !nullptr) {
        first->next->prev = first;
    }
    if (nullptr == last) {
        last = first;
    }
    ++size;
}
