class MyCircularQueue {
public:
    vector <int> Queue;
    int front;
    int rear;
    int size;
    
    MyCircularQueue(int k) {
        Queue.resize(k);    
        front = -1;
        rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        if(front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        
        Queue[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        int elem = Queue[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return Queue[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return Queue[rear];
    }
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        if((front == -1 && rear == -1) || (((rear + 1) % size) != front)) return false;
        return true;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */