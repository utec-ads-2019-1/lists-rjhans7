#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {
            this->head = this->tail = nullptr;
            this->nodes = 0;
        }

        T front() {
            if (this->head)
                return this->head->data;
            throw out_of_range ("Lista vacía!");
        }

        T back() {
            if (this->head){
                auto temp = this->head;
                auto first = this->head;
                while(temp->next!=first)
                    temp = temp->next;
                return temp->data;
            }else{
                throw out_of_range("Lista vacía!");
            }
        }

        void push_front(T value) {
            auto newNode = new Node <T> (value);
            if (this->head){
                newNode->next = this->head;
                this->head = newNode;
                this->tail->next = this->head;
            }else{
                newNode->next = newNode;
                this->head = this->tail = newNode;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto newNode = new Node <T> (value);
            if (this->head){
                this->tail->next=newNode;
                newNode->next = this->head;
                this->tail=newNode;
            }else{
                newNode->next = newNode;
                this->head = this->tail = newNode;
            }
            this->nodes++;
        }

        void pop_front() {
            if(this->nodes > 1){
                auto temp = this->head;
                this->head = temp->next;
                this->tail->next=this->head;
                delete temp;
                this->nodes--;
            }else if(this->nodes==1){
                delete this->head;
                this->head=this->tail= nullptr;
                this->nodes--;
            }else
                throw out_of_range("Lista vacía!");

        }
        void print(){
            auto temp =this->head;
            while (temp->next!= this->head){
                cout << temp->data <<"- ";
                temp=temp->next;
            }
            cout << temp->data;
        }

        void pop_back() {
            if(this->nodes > 1){
                auto last = this->tail;
                auto previous_last = this->head;
                while( previous_last->next!=this->tail)
                    previous_last = previous_last->next;
                this->tail = previous_last;
                this->tail->next = this->head;
                delete last;
                this->nodes--;
            }else if (this->nodes == 1){
                delete this->head;
                this->head = this->tail = nullptr;
                this->nodes--;
            }else
                throw out_of_range("Lista vacía!");
        }

        T operator[](int index) {
            if((index < 0) || (index >= this->nodes))
                throw out_of_range ("Out of range!");
            auto temp = this->head;
            for (int i = 0; i<index; i++)
                temp = temp->next;
            return temp->data;
        }

        bool empty() {
            return this->head == nullptr;
        }

        int size() {return this->nodes;
        }

        void clear() {
                this->tail->next= nullptr;
                this->head->killSelf();
                this->head = this->tail = nullptr;
                this->nodes = 0;
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
            auto first = this->head;
            auto last = this->head;
            for (int i=0; i <this->nodes/2; i++) {
                for (int j = 0; j < this->nodes - 1 - i; j++)
                    last =last->next;
                swap(first->data, last->data);
                first=first->next;
                last=this->head;
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            auto iter_begin = new BidirectionalIterator<T>(this->head);
            return *iter_begin;
        }

	    BidirectionalIterator<T> end() {
            auto iter_end = new BidirectionalIterator<T>(this->tail);
            return *iter_end;
        }

        void merge(CircularLinkedList<T> list) {
            for (int i = 0; i < list.nodes; i++)
                this->push_back(list[i]);
        }
};

#endif