// Queue.h
template <typename S>
struct node{
    S data;
    node<S> *link;
};

template <class T>
class Queue
{
private:
    int len;
    bool first;
    node<T> *head;
    node<T> *tail;
public:
    Queue(){
        head = new node<T>;
        tail = head; 
        len = 1;
        first = true;
    }
    void push(T a){
        if (!first){
            node<T> *ptr;
            ptr = new node<T>;
            ptr->data = a;
            tail->link = ptr;
            tail = ptr;
            ptr->link = nullptr;
            len++;
        } else {
            head->data = a;
            first = false;
        }
    }
    bool empty(){
        if (len <= 1) return true;
        return false;
    }
    int size(){
        return len;
    }
    void pop(){
        node<T> *ptr;
        ptr = head;
        head = head->link;
        delete ptr;
        len--;
    }
    T front(){
        return head->data;
    }
    T back(){
        return tail->data;
    }
    // please add necessary function members
};
