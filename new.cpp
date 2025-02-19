#include <iostream>
#include <string>

using namespace std;

template<typename T=string>
class PQueue {

    private:

        struct Item {
            size_t priority;
            T data;
            Item *previous = nullptr;
        };

        Item *first = nullptr;
        size_t size = 0;

    public:

    Item* pop() {}

    Item* push() {}

    Item* peek() const {}

    size_t size() const {}

    void print() const {}

};




int main(void) {


    



    return 0;
}