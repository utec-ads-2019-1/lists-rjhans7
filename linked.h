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
                this->head = this->tail = nullptr;
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
                this->nodes--;
            }else if(this->nodes == 1){
                delete this->tail;
                this->tail = this->head = nullptr;
                this->nodes--;
            }
        }

        T operator[](int index) {
            if( (index <0) || (index >= this->nodes)){
                throw out_of_range("Out of range!");
            }else if(index > this->nodes/2){
                auto temp = this->tail;
                for (int i=this->nodes-1; i>index; i--)
                    temp =temp->prev;
                return temp->data;
            }else{
                auto temp = this->head;
                for (int i=0; i<index; i++)
                    temp =temp->next;
                return temp->data;
            }

        }

        bool empty() { return this->head==nullptr;}

        int size() { return this->nodes;}

        void clear() {
            if(this->nodes>0) {
                this->head->killSelf();
                this->head = nullptr;
                this->tail = nullptr;
                this->nodes = 0;
            }else
                throw out_of_range("La lista ya está vacía");
        }

        void sort() {
            auto temp = this->head;
            for (int i = 0; i < this->nodes - 1; i++) {
                temp = this->head;
                for (int j = 0; j < this->nodes - i - 1; j++) {
                    if (temp->data > temp->next->data)
                        swap(temp->data, temp->next->data);
                    temp = temp->next;
                }
            }
        }
    
        void reverse() {
            swap( this->tail, this->head);
            auto temp1 = this->head;
            do{
                auto temp2=temp1->prev;
                swap(temp1->next,temp1->prev);
                temp1 = temp2;
            }while(temp1->prev!= nullptr);
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