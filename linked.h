#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {
            this->head = this->tail= nullptr;
            this->nodes=0;
        }

        T front() {
            if(this->head)
                return this->head->data;
            else
                throw out_of_range("Empty list!");
        }

        T back() {
            if(this->head)
                return this->tail->data;
            else
                throw out_of_range("Empty list!");
        }

        void push_front(T value) {
            auto newNode = new Node <T> (value);
            if (this->head){
                newNode->next = this->head;
                this->head->prev = newNode;
                this->head = newNode;
            }else{
                this->head = this->tail = newNode;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto newNode = new Node<T> (value);
            if(this->tail){
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
            }else
                this->tail=this->head=newNode;
        this->nodes++;
        }

        void pop_front() {
            if (this->nodes>1) {
                auto temp = this->head;
                this->head = this->head->next;
                delete temp;
                this->nodes--;
            }else if(this->nodes==1){
                delete this->head;
                this->head = nullptr;
                this->nodes--;
            }else
                throw out_of_range("Empty list!");
        }

        void pop_back() {
            if(this->nodes >1) {
                auto temp = this->tail;
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
                delete temp;
            }else if(this->nodes == 1){
                delete this->tail;
                this->tail= nullptr;
            }
        }

        T operator[](int index) {
            if( (this->nodes<0) || (this->nodes >= index)){
                throw out_of_range("Out of range!");
            }
            //Mejorar
            auto temp = this->head;
            for (int i=0; i<index; i++)
                temp =temp->next;
            return temp->data;
        }

        bool empty() {
            // TODO
        }

        int size() {
            // TODO
        }

        void clear() {
            // TODO
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }
};

#endif