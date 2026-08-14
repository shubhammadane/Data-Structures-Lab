#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class SinglyLinkedList
{
    Node* head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << "Node inserted at beginning." << endl;
    }

    // Insert at end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            cout << "Node inserted at end." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "Node inserted at end." << endl;
    }

    // Delete from beginning
    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "Node deleted from beginning." << endl;
    }

    // Delete from end
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << "Node deleted from end." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        cout << "Node deleted from end." << endl;
    }

    // Display the list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        cout << "Singly Linked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLinkedList list;
    int choice, value;

    do
    {
        cout << "\n----- SINGLY LINKED LIST -----" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Beginning" << endl;
        cout << "4. Delete from End" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            list.deleteFromBeginning();
            break;

        case 4:
            list.deleteFromEnd();
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
