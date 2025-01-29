#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue {
    private:

        struct QueueElem {
            T item;
            size_t priority;
            bool poped = false;
        };

        QueueElem* arr = nullptr;
        size_t elemsCounter = 0;
        size_t maxPriority = 0;
        size_t length = 0;

        size_t nextElem(void) const {
            for (size_t priority = this->maxPriority; priority >= 0; priority--) {
                for (size_t i = 0; i < this->elemsCounter; i++) {
                    QueueElem elem = this->arr[i];
                    if (!elem.poped && elem.priority == priority) { return i; }
                }
            }
            return 0;
        }

    public:
        PriorityQueue(size_t length) {
            this->arr = new QueueElem[length];
            this->length = length;
        }

        ~PriorityQueue() {
            delete[] arr;
        }

        T pop(void) {
            if (this->elemsCounter == 0) { cout << "Пустая очередь" << endl; abort(); }
            T item = this->peek();
            this->arr[this->nextElem()].poped = true;
            return item;
        }

        T peek(void) const {
            if (this->elemsCounter == 0) { cout << "Пустая очередь" << endl; abort(); }
            return this->arr[this->nextElem()].item;
        }

        void push(T item, size_t priority) {
            if ((this->elemsCounter + 1)  == this->length) { cout << "Очередь переполнена" << endl; abort(); }
            QueueElem elem;
            elem.item = item;
            elem.priority = priority;
            if (this->maxPriority < priority) { this->maxPriority = priority; }
            this->arr[elemsCounter++] = elem;
        }

        size_t size(void) const { 
            size_t activeElems = 0;
            for (size_t i = 0; i < this->elemsCounter; i++) {
                QueueElem elem = this->arr[i];
                if (!elem.poped) { activeElems++; }
            }
            return activeElems;
         }

};


int main(void) {

    PriorityQueue qu = PriorityQueue<char>(100);


    qu.push('a', 1);
    qu.push('c', 3);
    qu.push('b', 2);


    cout << qu.pop() << endl;
    cout << qu.pop() << endl;
    cout << qu.pop() << endl;


    return 0;
}