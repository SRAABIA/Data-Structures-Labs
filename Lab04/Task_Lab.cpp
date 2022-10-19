#include <iostream>
#include <math.h>
using namespace std;
class Node
{
public:
    int data, key;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k)
    {
        this->data = 0;
        this->key = k;
        next = NULL;
    }
    Node(int k, int d)
    {
        this->data = d;
        this->key = k;
        next = NULL;
    }
};
class SinglyLinkedList
{
public:
    Node *head;
    Node *Even_Head;
    Node *Odd_Head;
    SinglyLinkedList()
    {
        head = NULL;
        Even_Head = NULL;
        Odd_Head = NULL;
    }

    SinglyLinkedList(Node *ptr)
    {
        head = ptr;
        Even_Head = NULL;
        Odd_Head = NULL;
    }

    Node *IsExist(int k)
    { // dont have node with duplicate key values
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next; // goto next node: traverse
        }
        return temp;
    }

    bool Append(Node *n)
    { // append a node to the list

        if (IsExist(n->key) != NULL)
        {
            cout << endl
                 << "Node Already exist key: " << n->key;
            return false;
        }
        else
        {
            // check if linked list even exists or not
            if (head == NULL)
            {
                head = n;
                cout << endl
                     << "Node Appended";
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                // n->next = NULL; //by default
                cout << endl
                     << "Node Appended";
            }
        }
        return true;
    }

    void Prepend(Node *n)
    { // make a new head
        // = new Node(k,d);
        if (IsExist(n->key) != NULL)
        {
            cout << endl
                 << "Node Already exist key:" << n->key;
        }
        else
        {
            n->next = head;
            head = n;
            cout << endl
                 << "Node Prepended";
        }
    }

    void Insert_in_BW(int k1, int k, int d)
    { // insert a node after a given node
        Node *prev_node = IsExist(k1);
        Node *new_node = new Node(k, d);
        // check whether the node we want to insert after exist or not
        if (IsExist(prev_node->key) == NULL)
        {
            cout << endl
                 << "There Doesn't exist SUCH Node";
        }
        else
        {
            // cout<<endl<<"Node found";
            Node *ptr = IsExist(prev_node->key);
            if (IsExist(new_node->key) == NULL)
            {
                // cout<<endl<<"Node is Unique";
                new_node->next = prev_node->next;
                prev_node->next = new_node;
                cout << endl
                     << "Node Inserted";
            }
            else
            {
                cout << endl
                     << "Node Already exist with the key:" << new_node->key << " Enter node with unique key value.";
            }
        }
    }

    void Delete_Last_Node()
    {
        if (head == NULL)
        {
            cout << endl
                 << "There does not exist any list.";
        }
        else if (head->next == NULL)
        {
            cout << endl
                 << "Node Deleted: key" << head->next->key << " .";
            delete (head);
            head = NULL;
        }

        else
        {
            Node *temp = head;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }

            cout << endl
                 << "The Last node is Deleted successfully key: " << temp->next->key << " .";
            delete (temp->next);
            temp->next = NULL; // 2nd last node is now the last node of list
        }
    }

    void Delete_Specific_Node(int k)
    {
        // check if list exist
        if (head == NULL)
        {
            cout << endl
                 << "There does not any list.";
        }
        else
        {
            // maybe the first node is to be deleted
            if (head->key == k)
            {
                head = head->next;
                cout << endl
                     << "The node with key: " << k << " is Deleted successfully";
            }
            else
            {
                Node *temp = NULL;
                Node *prev = head;
                Node *current = head->next;
                // transversing the list to get to the key
                while (current != NULL)
                {
                    if (current->key == k)
                    {
                        // prev->next = current->next;
                        temp = current;
                        current = NULL;
                    }
                    else
                    {
                        // prev = current;
                        prev = prev->next;
                        current = current->next;
                    }
                }

                if (temp == NULL)
                {
                    cout << endl
                         << "No node with key " << k << " is found in the list";
                }
                else
                {
                    prev->next = temp->next;
                    delete (temp);
                    cout << endl
                         << "The node with key: " << k << " is Deleted successfully";
                }
            }
        }
    }

    void Update_Node(int k, int d)
    {
        Node *n = IsExist(k);
        if (n != NULL)
        {
            n->data = d;
            cout << endl
                 << "Data Updated Successfully";
        }
        else
        {
            cout << endl
                 << "There does not exist a node with such key value: " << k;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << endl
                 << "There does not exist such list";
        }
        else
        {
            cout << endl
                 << "Nodes in Singly Linked List Are: " << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << " , " << temp->data << " )-->";
                temp = temp->next;
            }
        }
    }

    int length_of_list()
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void print_this()
    {
        if (head != NULL)
        {
            int length = length_of_list();
            Node *temp = head;
            int mid = (length / 2);

            for (int i = 1; i <= mid; i++)
            {
                temp = temp->next;
            }
            cout << " ( " << temp->key << " , " << temp->data << " )";
        }
    }

    void display_Even()
    {
        if (Even_Head == NULL)
        {
            cout << endl
                 << "There does not exist such list";
        }
        else
        {
            cout << endl
                 << "Even nodes in List Are: ";
            Node *temp = Even_Head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << " )-->";
                temp = temp->next;
            }
        }
    }

    void display_Odd()
    {
        if (Odd_Head == NULL)
        {
            cout << endl
                 << "There does not exist such list";
        }
        else
        {
            cout << endl
                 << "Odd nodes in List Are: ";
            Node *temp = Odd_Head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << " )-->";
                temp = temp->next;
            }
        }
    }

    void even_odd()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key % 2 == 0)
            {
                Node *even_ptr = new Node(ptr->key, ptr->data);
                if (Even_Head == NULL)
                {
                    Even_Head = even_ptr;
                    // cout<<endl<<"Node Appended";
                    // display_Even();
                }
                else
                {
                    Node *ptr2 = Even_Head;
                    while (ptr2->next != NULL)
                    {
                        ptr2 = ptr2->next;
                    }
                    ptr2->next = even_ptr;
                    // ptr2->next = NULL;
                    // cout<<endl<<"Node Appended";
                    // display_Even();
                }
            }
            else if (ptr->key % 2 == 1)
            {
                Node *odd_ptr = new Node(ptr->key, ptr->data);
                if (Odd_Head == NULL)
                {

                    Odd_Head = odd_ptr;
                    // cout<<endl<<"Node Appended";
                    // display_Odd();
                }
                else
                {
                    Node *ptr2 = Odd_Head;
                    while (ptr2->next != NULL)
                    {
                        ptr2 = ptr2->next;
                    }
                    ptr2->next = odd_ptr;
                    // ptr2->next = NULL;
                    // cout<<endl<<"Node Appended";
                    // display_Odd();
                }
            }
            ptr = ptr->next;
        }
    }

    void merge()
    {
        Node *t_even = Even_Head;
        Node *t_odd = Odd_Head;
        Node *t_head = head;
        while (t_even->next != NULL)
        {
            t_even = t_even->next;
        }
        t_even->next = t_odd;
        // display_Even();
        // cout<<"\n merge";
        head = NULL;
        head = Even_Head;
    }
};

int main()
{
    int op = 0;
    int k, d, z;

    SinglyLinkedList node;
    int number;

    do
    {
        cout << endl
             << endl
             << "Select the option you'd like to perform on your linked list: ";
        cout << endl
             << "1) Clear Screen" << endl
             << "2) Append()" << endl
             << "3) Prepend()" << endl
             << "4) Insert_in_BW()" << endl
             << "5) Delete_Last_Node()" << endl
             << "6) Delete_Specific_Node()" << endl
             << "7) Update_Node()" << endl
             << "8) MDDLE NODE TASK 7A()" << endl
             << "9) IMPLEMENT ARRANGEMENT TASK 7B()" << endl
             << "10) display()" << endl
             << ":::  ";
        cin >> op;
        Node *ptr = new Node();
        switch (op)
        {
        case 1:
            system("cls");
            break;

        case 2:
        {
        // cout<<"\nAppend: \nEnter Key and Data? "; cin>>k>>d;
        //    ptr->data = d;
        //    ptr->key = k;
        // node.Append(ptr);
        here:
            Node *ptr = new Node();
            cout << "\nEnter Key and Data? ";
            cin >> k >> d;
            ptr->data = d;
            ptr->key = k;
            if (node.Append(ptr))
            {
                continue;
            }
            else
            {
                cout << endl
                     << "Re-enter: ";
                goto here;
            }
            break;
        }

        case 3:
        {
            cout << "\nPrepend: \nEnter Key and Data? ";
            cin >> k >> d;
            ptr->data = d;
            ptr->key = k;
            node.Prepend(ptr);
            break;
        }

        case 4:
        {
            cout << "\nInsert_in_BW: ";
            cout << "\nAfter which EXISTING node you want to enter a new node: Enter Key ? ";
            cin >> z;

            cout << "\nEnter Key and Data? ";
            cin >> k >> d;
            node.Insert_in_BW(z, k, d);
            break;
        }

        case 5:
            cout << "\nDelete_Last_Node()";
            node.Delete_Last_Node();
            break;

        case 6:
            cout << "\nDelete_Specific_Node()";
            cout << "\nEnter Key ";
            cin >> k;
            node.Delete_Specific_Node(k);
            break;

        case 7:
            cout << "\nUpdate_Node()";
            cout << "\nEnter Key of node you want to change: ";
            cin >> k;
            cout << "\nEnter new Data for this key: ";
            cin >> d;
            node.Update_Node(k, d);
            break;
        case 8:
            cout << "\n\nThe middle most element of this list is: ";
            node.print_this();
            break;

        case 9:
        {
            cout << endl
                 << "=================================================\n";
            cout << "\n\n**After ARRANGING the list**" << endl;
            node.even_odd();

            node.merge();

            node.display();
        }
        break;

        case 10:
            node.display();
            break;

        default:
            cout << "\nenter good value";
        }

    } while (op != 0);

    return 0;
}