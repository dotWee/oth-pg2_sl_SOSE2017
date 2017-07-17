#pragma once

template<typename T>
class MyList;

template<typename T>
class LiNode {
public:
    LiNode<T> *next = nullptr;
    LiNode<T> *prev = nullptr;
    T value;

    LiNode(const T &, LiNode<T> *, LiNode<T> *);

    friend class MyList<T>;
};

template<typename T>
inline LiNode<T>::LiNode(const T &val, LiNode<T> *prev = nullptr, LiNode<T> *next = nullptr)
        : value(val), prev(prev), next(next) {

}
