#include <iostream>

const int MAX_SIZE = 5; // Maximum size of the circular queue

class CircularQueue {
private:
    int front;            // Index of the front element
    int rear;             // Index of the rear element
    int arr[MAX_SIZE];    // Array to store circular queue elements

public:
    CircularQueue() {
        front = -1;        // Initialize front and rear indices
        rear = -1;
    }

    // Function to check if the circular queue is full
    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to enqueue (insert) an element at the rear of the circular queue
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Circular Queue Overflow! Cannot enqueue element " << value << ".\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // If the circular queue is empty, set front and rear to 0
        } else {
            rear = (rear + 1) % MAX_SIZE; // Increment rear in a circular manner
        }
        arr[rear] = value; // Insert the value at the rear
        std::cout << "Enqueued element " << value << " into the circular queue.\n";
    }

    // Function to dequeue (remove) an element from the front of the circular queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Circular Queue Underflow! The circular queue is empty.\n";
            return -1; // Return a sentinel value to indicate an empty circular queue
        }
        int value = arr[front]; // Get the front element
        if (front == rear) {
            front = rear = -1; // If there is only one element, set front and rear to -1
        } else {
            front = (front + 1) % MAX_SIZE; // Increment front in a circular manner
        }
        return value;
    }

    // Function to get the front element of the circular queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "The circular queue is empty.\n";
            return -1; // Return a sentinel value to indicate an empty circular queue
        }
        return arr[front];
    }
};

int main() {
    CircularQueue myCircularQueue;

    myCircularQueue.enqueue(10);
    myCircularQueue.enqueue(20);
    myCircularQueue.enqueue(30);

    std::cout << "Front element: " << myCircularQueue.peek() << std::endl;

    std::cout << "Dequeued element: " << myCircularQueue.dequeue() << std::endl;

    myCircularQueue.enqueue(40);
    myCircularQueue.enqueue(50);

    std::cout << "Is the circular queue full? " << (myCircularQueue.isFull() ? "Yes" : "No") << std::endl;

    return 0;
}
