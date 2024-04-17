/************************************************************

    Following is the linked list node structure.

    class Node
    {
        public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

************************************************************/

Node *removeDuplicateUnsortedList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = NULL;
    Node *prev = NULL;
    Node *curr = head;
    unordered_map<int, bool> visited;

    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }

        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next
        }
    }
}