#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    explicit Node(T data){
        this->data= data;
        this->next = nullptr;
        this->prev =nullptr;
    }
    void killSelf() {
        if(next!=nullptr)
            next->killSelf();
        delete this;
    }
};

#endif