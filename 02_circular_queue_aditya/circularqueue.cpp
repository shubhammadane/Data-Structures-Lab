 #include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Insert element
void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is Full\n";
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    cout << value << " inserted\n";
}

// Delete element
void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << queue[front] << " deleted\n";

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Display elements
void display()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";

    int i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
