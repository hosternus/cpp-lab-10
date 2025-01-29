#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue {
    private:

        struct QueueElem {
            T item;
            size_t priority;
        };

        QueueElem* arr = nullptr;

    public:
        PriorityQueue() {
            this->arr = new QueueElem[1000];
        }

        ~PriorityQueue() {
            delete[] arr;
        }

        // pop();
        // push();
        // peek();
        // size();

};


int main(void) {



    return 0;
}