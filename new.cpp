#include <iostream>
#include <string>

using namespace std;

template<typename T=string>
class PQueue {

    private:

        struct Item {
            size_t priority;
            T data;
            Item *next = nullptr;
        };

        Item *head = nullptr;
        Item *last = nullptr;
        size_t qsize = 0;

    public:

        PQueue() {}

        ~PQueue() {
            Item* i = this->head;
            Item* e = nullptr;
            while (i != nullptr) {
                e = i->next;
                delete i;
                i = e;
            }
        }

        bool push(T data, size_t priority) {

            Item* nitem = new Item;
            nitem->data = data;
            nitem->priority = priority;

            if (this->head == nullptr) {
                this->head = nitem;
                this->last = nitem;
                this->qsize++;
                return true;
            } else if (nitem->priority <= this->last->priority) {
                this->last->next = nitem;
                this->last = nitem;
                this->qsize++;
                return true;
            } else if (this->head->priority < nitem->priority) {
                nitem->next = this->head;
                this->head = nitem;
                this->qsize++;
                return true;
            } else if (nitem->priority > this->last->priority) {
                Item* previous = nullptr;
                for (Item* i = this->head; i->priority >= nitem->priority; i = i->next) { previous = i; }
                nitem->next = previous->next;
                previous->next = nitem;
                this->qsize++;
                return true;
            }

            return false;
        }

        Item* pop(void) {
            Item* out = this->head;
            this->head = this->head->next;
            this->qsize--;
            return out;
        }

        Item* peek(void) const { return this->head; }

        size_t size(void) const { return this->qsize; }
};


template <typename T>
ostream& operator<<(ostream& os, const PQueue<T> &q) {
    os << "Элементов: " << q.size() << endl;
    os << "Следущий элемент: " << q.peek() << endl;
    return os;
}


int main(void) {

    PQueue<string> pq;

    cout << pq << endl;

    pq.push("prior3", 3);
    pq.push("prior2", 2);
    pq.push("prior1", 1);

    cout << pq << endl;

    return 0;
}