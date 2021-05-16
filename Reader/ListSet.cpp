#include <cstdlib>

template <typename T> class ListSet {
public:
    ListSet();
    ListSet(const ListSet& other);
    ListSet& operator=(const ListSet& other);
    ~ListSet();

    void insert(const T& toAdd);
    bool contains(const T& toFind) const;

private:
    struct cellT {
        T data;
        cellT* next;
    };
    cellT* list;

    void copyOther(const ListSet& other);
    void clear();
};

// Cleanest:
// template <typename T> void ListSet<T>::copyOther(const ListSet& other) {
//     for (cellT* source = other.list; source != NULL; source = source->next)
//         insert(source);
// }

// Reverse:
// template <typename T> void ListSet<T>::copyOther(const ListSet& other) {
//     for (cellT* source = other.list; source != NULL; source = source->next) {
//         cellT* newNode = new cellT;
//         newNode->data = source->data;
//         newNode->next = list;
//         list = newNode;
//     }
// }

// In order
template <typename T> void ListSet<T>::copyOther(const ListSet& other) {
    cellT** current = &list;

    for (cellT* source = other.list; source != NULL; source = source->next) {
        *current = new cellT;
        (*current)->data = source->data;
        (*current)->next = NULL;

        current = &((*current)->next);
    }
}
