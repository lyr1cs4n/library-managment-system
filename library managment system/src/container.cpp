#include "container.h"
#include <vector>
#include <iostream>
using namespace std;
template <typename T>
LinkedList<T>:: LinkedList()
{
    head = nullptr;
    size = 0;
}
template <typename T>
LinkedList<T>::~ LinkedList()
{
    while(head!=NULL)
    {
        Node <T>* temp = head;
        head = head->next;
        delete temp;
    }
}
template <typename T>
void LinkedList<T>:: push_back(const T& element)
{
    Node<T>* newNode = new Node<T>(element);
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node<T>* it = head;
        while(it->next != NULL)
        {
            it = it->next;
        }
        it->next = newNode;
    }
    size++;
}
template <typename T>
void LinkedList<T>:: insertStart(const T& element)
{
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;
}
template <typename T>
void LinkedList<T>:: insertPosition(const T& element, const int index)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid index" << endl;
        return;
    }
    if(index == 0)
    {
        insertStart(element);
        return;
    }
    Node<T>* newNode = new Node<T>(element);
    Node<T>* it = head;
    for (int i = 0; i < index-1; i++)
    {
        it = it->next;
    }
    newNode->next = it->next;
    it->next = newNode;
    size++;
}
template <typename T>
void LinkedList<T>:: removeIndex(const int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    Node<T>* curr ;
    if(index == 0)
    {
        curr = head;
        head = head->next;
    }
    else
    {
        Node<T>* it = head;
        for (int i = 0; i < index - 1; i++)
        {
            it = it->next;
        }
        curr = it->next;
        it->next = it->next->next;
    }
    delete curr;
    size--;
}
template <typename T>
void LinkedList<T>:: removeValue(const T& item)
{
    Node<T>* it = head;
    Node<T>* prev = NULL;
    while(it!=NULL)
    {
        if(it->data == item)
        {
            if(prev != NULL)
            {
                prev->next = it->next;
            }
            else
            {
                head = it->next;
            }
            delete it;
            size--;
            cout<<"Removal Success";
            return;
        }
        prev = it;
        it = it->next;
    }
    cout<<"Element Not Found"<<endl<<endl;
}
template <typename T>
T* LinkedList<T>:: find(const T element)
{
    Node<T>* curr  = head;
    while(curr!=NULL)
    {
        if(curr->data == element)
        {
            return &curr->data;
        }
        curr = curr->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::sortElements()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node<T>* curr = head;
    vector<T>temp;
    while(curr != NULL)
    {
        temp.push_back(curr->data);
        curr = curr->next;
    }
    sort(temp.begin(),temp.end());
    curr = head;
    while(head!=NULL)
    {
        Node <T>* temp = head;
        head = head->next;
        delete temp;
    }
    for(const T& i: temp)
    {
        push_back(i);
    }
}

