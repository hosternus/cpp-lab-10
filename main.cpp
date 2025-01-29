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
        size_t QelemsCounter = 0;
        size_t QmaxPriority = 0;
        size_t Qlength = 0;

        size_t nextElem(void) const {
            for (size_t priority = this->QmaxPriority; priority >= 0; priority--) {
                for (size_t i = 0; i < this->QelemsCounter; i++) {
                    QueueElem& elem = this->arr[i];
                    if (!elem.poped && elem.priority == priority) { return i; }
                }
            }
            return 0;
        }

    public:

        PriorityQueue(size_t length) {
            this->arr = new QueueElem[length];
            this->Qlength = length;
        }

        ~PriorityQueue() {
            delete[] arr;
        }

        T pop(void) {
            if (this->QelemsCounter == 0) { cout << "Пустая очередь" << endl; abort(); }
            T item = this->peek();
            this->arr[this->nextElem()].poped = true;
            return item;
        }

        T peek(void) const {
            if (this->QelemsCounter == 0) { cout << "Пустая очередь" << endl; abort(); }
            return this->arr[this->nextElem()].item;
        }

        void push(T item, size_t priority) {
            if ((this->QelemsCounter + 1)  == this->Qlength) { cout << "Очередь переполнена" << endl; abort(); }
            QueueElem elem;
            elem.item = item;
            elem.priority = priority;
            if (this->QmaxPriority < priority) { this->QmaxPriority = priority; }
            this->arr[QelemsCounter++] = elem;
        }

        size_t size(void) const { 
            size_t activeElems = 0;
            for (size_t i = 0; i < this->QelemsCounter; i++) {
                QueueElem& elem = this->arr[i];
                if (!elem.poped) { activeElems++; }
            }
            return activeElems;
        }


        size_t amount(void) const { return this->QelemsCounter; }
        size_t length(void) const { return this->Qlength; }
        size_t maxPriority(void) const { return this->QmaxPriority; }


};

template <typename T>
ostream& operator<<(ostream& out, const PriorityQueue<T>& qu) {

    out << "Заполнено: " << qu.amount() << "/" << qu.length() << endl;
    out << "Активных элеметов: " << qu.size() <<  endl;
    out << "Максимальный приоритет: " << qu.maxPriority() << endl;
    out << "Следущий элемент: " << qu.peek() << endl;
 
    return out;
}
 

int main(void) {

    PriorityQueue qu = PriorityQueue<char>(100);


    qu.push('a', 1);
    qu.push('c', 3);
    qu.push('b', 2);

    cout << qu;

    // cout << qu.pop() << endl;
    // cout << qu.pop() << endl;
    // cout << qu.pop() << endl;


    return 0;
}