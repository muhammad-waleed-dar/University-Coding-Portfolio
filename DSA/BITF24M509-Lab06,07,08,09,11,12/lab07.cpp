#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
public:
    virtual void enqueue(const T&) = 0;
    virtual T dequeue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual ~Queue() {}
};


template <typename T>
class ArrayQueue : public Queue<T> {
private:
    T* arr;
    int frontIndex, rearIndex, count, capacity;

public:
    ArrayQueue(int size = 5) {
        capacity = size;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void enqueue(const T& val) override {
        if (count == capacity) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        count++;
    }

    T dequeue() override {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return T();
        }
        T val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return val;
    }

    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return arr[frontIndex];
    }

    bool isEmpty() const override {
        return count == 0;
    }

    int size() const override {
        return count;
    }

    ~ArrayQueue() {
        delete[] arr;
    }
};

template <typename T>
class LinkedQueue : public Queue<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(NULL) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    LinkedQueue() {
        frontNode = rearNode = NULL;
        count = 0;
    }

    void enqueue(const T& val) override {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    T dequeue() override {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return T();
        }
        Node* temp = frontNode;
        T val = temp->data;
        frontNode = frontNode->next;
        if (frontNode == NULL)
            rearNode = NULL;
        delete temp;
        count--;
        return val;
    }

    T front() const override {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return frontNode->data;
    }

    bool isEmpty() const override {
        return count == 0;
    }

    int size() const override {
        return count;
    }

    ~LinkedQueue() {
        while (!isEmpty())
            dequeue();
    }
};


int main() {
    cout << "=== ARRAY QUEUE ===\n";
    Queue<int>* aq = new ArrayQueue<int>(5);

    aq->enqueue(10);
    aq->enqueue(20);
    aq->enqueue(30);

    cout << "Dequeued: " << aq->dequeue() << endl;
    cout << "Front: " << aq->front() << endl;
    cout << "Size: " << aq->size() << endl;
    cout << "Empty? " << aq->isEmpty() << endl;

    delete aq;

    cout << "\n=== LINKED QUEUE ===\n";
    Queue<int>* lq = new LinkedQueue<int>();

    lq->enqueue(100);
    lq->enqueue(200);
    lq->enqueue(300);

    cout << "Dequeued: " << lq->dequeue() << endl;
    cout << "Front: " << lq->front() << endl;
    cout << "Size: " << lq->size() << endl;
    cout << "Empty? " << lq->isEmpty() << endl;

    delete lq;

    return 0;
}