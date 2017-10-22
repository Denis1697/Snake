#ifndef __LIST_H__
#define __LIST_H__

typedef unsigned int uint;

template <class T>
struct ListItem
{
    T item;
    ListItem *next;
};

template <class T>
class List
{
private:
    ListItem<T> *head;
    int count;
public:
    List();
    List(const List<T>& l);
    ~List() { Clear(); }

    void Clear();

    List<T>& operator=(const List<T>& q);

    uint GetCount() const { return count; }
    bool IsEmpty() const { return count == 0; }
	ListItem<T> * GetHead() { return head; }

    T& operator[](uint index);
    const T& operator[](uint index) const;

    void AddHead(const T& item);
    void AddTail(const T& item);
    void Insert(uint index, const T& item);
    void Remove(uint index);
};

template <class T>
List<T>::List()
{
    head = 0;
    count = 0;
}

template <class T>
List<T>::List(const List<T>& l)
{
    if (!l.count)
        head = 0;
    else
    {
        ListItem<T> *prev, *temp, *src = l.head;
        for (uint i = 0; i < l.count; i++)
        {
            temp = new ListItem<T>;
            temp->item = src->item;
            temp->next = 0;

            if (!i)
                head = temp;
            else
                prev->next = temp;

            prev = temp;
            src = src->next;
        }
    }
    count = l.count;
}

template <class T>
void List<T>::Clear()
{
    if (count)
    {
        while (head)
        {
            ListItem<T> *temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l)
{
    if (this == &l) return *this;

    Clear();

    if (l.count)
    {
        ListItem<T> *prev, *temp, *src = l.head;
        for (uint i = 0; i < l.count; i++)
        {
            temp = new ListItem<T>;
            temp->item = src->item;
            temp->next = 0;

            if (!i)
                head = temp;
            else
                prev->next = temp;

            prev = temp;
            src = src->next;
        }
        count = l.count;
    }

    return *this;
}

template <class T>
T& List<T>::operator[](uint index)
{
    if (index >= count)
        throw "List<T>::operator[](uint index): Out of bounds!";

    ListItem<T> *temp = head;
    int i = 0;
    while (i++ < index)
        temp = temp->next;

    return temp->item;
}

template <class T>
const T& List<T>::operator[](uint index) const
{
    if (index >= count)
        throw "List<T>::operator[](uint index) const: Out of bounds!";

    ListItem<T> *temp = head;
    int i = 0;
    while (i++ < index)
        temp = temp->next;

    return temp->item;
}

template <class T>
void List<T>::AddHead(const T& item)
{
    Insert(0, item);
}

template <class T>
void List<T>::AddTail(const T& item)
{
    ListItem<T> *temp = new ListItem<T>;
    temp->item = item;
    temp->next = 0;

    if (!count)
        head = temp;
    else
    {
        ListItem<T> *tail = head;
        while (tail->next)
            tail = tail->next;
        tail->next = temp;
    }
    count++;
}

template <class T>
void List<T>::Insert(uint index, const T& item)
{
    if (index > count)
        throw "List<T>::Insert(uint index, const T& item): Out of bounds!";

    ListItem<T> *temp = new ListItem<T>;
    temp->item = item;

    if (!index)
    {
        if (!count)
        {
            head = temp;
            head->next = 0;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    else
    {
        ListItem<T> *prev = head;
        int i = 0;
        while (i++ < index)
            prev = prev->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    count++;
}

template <class T>
void List<T>::Remove(uint index)
{
    if (index >= count)
        throw "List<T>::Remove(uint index): Out of bounds!";

    ListItem<T> *temp;

    if (!index)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        ListItem<T> *prev = head;
        int i = 0;
        while (i++ < index - 1)
            prev = prev->next;
        temp = prev->next;
        prev->next = temp ? temp->next : 0;
        delete temp;
    }
    count--;
}

#endif /* __LIST_H__ */
