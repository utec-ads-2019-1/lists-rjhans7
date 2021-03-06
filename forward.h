#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {
            this->head = this->tail = nullptr;
            this->nodes = 0;
        }

        T front() {
            if(this->head)
                return this->head->data;
            throw out_of_range("Lista vacía");
        }

        T back() {
            if (this->head) {
                auto temp = this->head;
                while (temp->next != nullptr)
                    temp = temp->next;
                return temp->data;
            } else {
                throw out_of_range("Lista vacía");
            }
        }

        void push_front(T value) {
            auto newNode = new Node <T> (value);
            if (this->head){
                newNode->next = this->head;
                this->head = newNode;
            }else{
                this->head = this->tail = newNode;

            }
            this->nodes++;
        }

        void push_back(T value) {
            auto newNode = new Node <T> (value);
            newNode->next = nullptr;
            if (this->head){
                this->tail->next =newNode;
                this->tail = newNode;
            }else
                this->head=this->tail=newNode;
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
                this->head=this->tail = nullptr;
                this->nodes--;
            }else
                throw out_of_range("Lista vacía");

        }

        void pop_back() {
            auto last = this->tail;
            auto previousLast = this->head;
            if(this->nodes>1){
                for (int i =0; i<this->nodes-2;i++)
                    previousLast=previousLast->next;
                previousLast->next = nullptr;
                this->tail = previousLast;
                delete last;
                this->nodes--;
            }else if(this->nodes==1){
                delete this->head;
                this->head = this->tail=nullptr;
                this->nodes--;
            }else
                throw out_of_range("Lista vacía");


        }

        T operator[](int index) {
            if(index >=this->nodes) {
                throw out_of_range("Out of range!");
            }
            auto temp = this->head;
            for (int i=0; i<index; i++)
                temp =temp->next;
            return temp->data;

        }

        bool empty() {return this->head == nullptr;}

        int size() {
            return this->nodes;
        }
        void clear() {
            if(this->nodes>0) {
                this->head->killSelf();
                this->head = nullptr;
                this->nodes = 0;
            }else
                throw out_of_range("Lista vacía");
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
        void print(){
            auto temp =this->head;
            while (temp->next!= nullptr){
                cout << temp->data <<"- ";
                temp=temp->next;
            }
            cout << temp->data;
        }
        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            auto iter_begin = new ForwardIterator<T>(this->head);
            return *iter_begin;
        }

	    ForwardIterator<T> end() {
            auto iter_end = new ForwardIterator<T>(this->tail);
            return *iter_end;
        }

        void merge(ForwardList<T> list) {
            for (int i = 0; i <list.nodes;i++)
                this->push_back(list[i]);
        }
};

#endif