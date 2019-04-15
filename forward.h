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
            if(this->head)
                return this->tail->data;
            throw out_of_range("Lista vacía");
        }

        void push_front(T value) {
            auto *newNode = new Node <T> (value);
            if (this->head){
                newNode->next = this->head;
                this->head = newNode;
            }else{
                this->head = newNode;

            }
            this->nodes++;
        }

        void push_back(T value) {
            auto newNode = new Node <T> (value);
            newNode->next = nullptr;
            if (this->head){
                auto temp = this->head;
                while (temp->next!=NULL)
                    temp = temp->next;
                temp->next=newNode;
            }else
                this->head=newNode;
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
                throw out_of_range("Lista vacía");

        }

        void pop_back() {
            auto last = this->head;
            auto previousLast = this->head;
            if(this->nodes>1){
                for (int i =1; i<this->nodes-2;i++)
                    previousLast=previousLast->next;
                while(last->next!=NULL)
                    last= last->next;
                previousLast->next = nullptr;
                delete last;
                this->nodes--;
            }else if(this->nodes==1){
                delete this->head;
                this->head = nullptr;
                this->nodes--;
            }else
                throw out_of_range("Lista vacía");


        }

        T operator[](int index) {//similar tu get element at index
            if(index >this->nodes-1) {
                throw out_of_range("Lista vacía");
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
            if(this->head) {
                this->head->killSelf();
                this->head = nullptr;
                this->nodes = 0;
            }else
                throw out_of_range("Lista vacía");
        }

        void sort() {
            auto temp = this->head->next;
            for(int i=0; i<this->nodes-1; i++)
                for(int j = 0; j<this->nodes-i-1; j++ )
                    if(this->head->data > temp->data){
                        swap(this->head->data, temp->data);
            }
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

	    ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            // TODO
        }
};

#endif