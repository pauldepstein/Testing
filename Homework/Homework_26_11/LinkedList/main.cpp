#include <iostream>
#include <string>

using namespace std;
struct Node{
int data;
Node* next;
//bool isFirst; // true if no node links to it and false otherwise.
};

// Counting the number of nodes starting from the head.
int countNodes(Node* head)
{
    int numNodes = 0;
    while(head)
    {
        head = head->next;
        numNodes++;
    }

    return numNodes;
}


// Sorting a linked list.
void sortList(Node* head)
{

   int numNodes = countNodes(head);


   for(int i =0; i < numNodes; i++)
   {
       Node* temp1 = head;
       while(temp1 && temp1->next)
       {


         if(temp1->data > temp1->next->data)
         // Should probably use std::swap from algorithm library here.
         {
           int tmp = temp1->data;
           temp1->data = temp1->next->data;
           temp1->next->data = tmp;
         }
         temp1 = temp1->next;
   }

   }

}

// Delete node in nth position relative to the head
//1 stands for head
void Delete(int n, Node* head)
{
    if(n == 1)
    {
        head = head->next;
        return;
    }

    Node* temp1 = head;


    for(int i = 0; i < n-2; i++)
        temp1 = temp1->next;

     temp1->next = temp1->next->next;


}

/*void deleteNode(Node& node)
{
    if(!node)
      return;

    if(node.isFirst)
    {
        Node nextNode = *(node.next);
        nextNode.isFirst = true;
        node = 0;
    }

}
void removeDuplicateNode(Node& node)
{
    while(node && node->)
}*/

void createList(Node** head) // pointer to a pointer
{
    if(head)
    *head = 0;
}

void addNode(Node** head, int n)
{
    Node* node = new Node();
    node->data = n;
    node->next = 0;

    if(head && !*head)
    {
        *head = node;
        return;
    }

    Node *cur = *head;
    while(cur)
    {
        if(!cur->next)
        {
            cur->next = node;
            return;
        }

        cur = cur->next;
    }

    return;
}

void deleteNode(Node** head, Node* node)
{
    if(!head || !*head)
        return;

    Node *cur = *head;
    Node *prev = *head;

    if(node == *head)
    {
        if( (*head)->next  )
            *head = (*head)->next;

         return;
    }

    while(cur){
                if(cur == node){
                    prev->next = cur->next;
                    return;
                }
                prev = cur;
                cur = cur->next;
    }

}

void removeDuplicateNode(Node** head)
{
    if(!head || !*head  || !((*head)->next))
        return;

    Node* cur = *head;
    Node* iter;

    while(cur){
               iter = cur->next;
               while(iter){
               if(cur->data == iter->data)
                  deleteNode(head, iter);

               iter = iter->next;
               }
               cur = cur->next;

    }
    return;
}

void print(Node* head)
{
    Node* cur = head;
    while(cur){
              cout << cur->data << " ";
              cur = cur->next;
    }
    cout << endl;
}




// My own homemade example.
Node* findNthFromLast(Node* headNode, int n)
{
   int numNodes = countNodes(headNode);

   for(int i = 0; i < n - numNodes; i++)
       headNode = headNode->next;

   return headNode;
}

// Finding the first occurrence of a word.
int Search(string stringArray[], string word)
{
    int i = 0;
    string * s = stringArray;

    while(s && *s != word)
    {
        s++;
        i++;
    }

   return i;

}

int main()
{

    Node* head = new Node();

    createList(&head);
    addNode(&head, 80);
    addNode(&head, 10);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 70);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 90);
    //findNthFromLast(head, 0);
    findNthFromLast(head,1);
    print(head);
    removeDuplicateNode(&head);
    print(head);
    Delete(3, head);
    sortList(head);
    print(head);
    delete head;

    string  stringArray[] = {"at", "","","","ball","","","car","","","dad","",""};
    cout << "\n\n" << Search(stringArray, "ball");
    return 0;
}
