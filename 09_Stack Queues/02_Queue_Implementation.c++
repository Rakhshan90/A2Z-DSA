#include <iostream>

using namespace std;
class queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    queue(int size)
    {
        this->size = size;
        arr = new int[this->size];
        front = 0;
        rear = 0;
    }

    int enqueue(int data)
    {
        // overflow condition
        if (rear == size)
            cout<<"queue is full "<<endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    int dequeue()
    {
        // underflow condition
        if (front == rear)
            cout<<"queue is underflow "<<endl;
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (rear == front)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }
    bool isEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
    int Front()
    {
        if (front == rear)
            return -1;
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    queue q(5);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(10);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(20);
    
    if(q.isEmpty()){
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<<"queue is not empty "<<endl;
    }
    cout<<"front: "<<q.Front()<<endl;
    q.dequeue();
    cout<<"front: "<<q.Front()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    if(q.isEmpty()){
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<<"queue is not empty "<<endl;
    }
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(10);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(20);


    return 0;
}