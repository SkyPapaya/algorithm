class MyCircularQueue {
private:
    int queue[1000] = {0};
    int k = 0;
    int head = 0;
    int end = -1;
    int count = 0;
    
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (count < k) {
            count++;
            end = (end + 1) % k;
            queue[end] = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (count == 0) {
            return false;
        }
        count--;
        head = (head + 1) % k;
        return true;
    }
    
    int Front() {
        if (count == 0) {
            return -1;
        }
        return queue[head];
    }
    
    int Rear() {
        if (count == 0) {
            return -1;
        }
        return queue[end];
    }
    
    bool isEmpty() {
        if (count == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (count == k) {
            return true;
        }
        return false;
    }
};
