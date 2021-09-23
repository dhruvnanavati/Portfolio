#include "node.h"

node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}

std::size_t list_index(node * head_ptr, int target) {
  std::size_t count = 0;
  for (const node *p = head_ptr; p != nullptr; p = p->link()) {
    if (p->data() == target) {
      return count;
    }
    count++;
  }
  return -1;
}

node* list_at(node * head_ptr, std::size_t n) {
  std::size_t count = 0;
  for (node *p = head_ptr; p != nullptr; p = p->link()) {
    if (count == n) {
      return p;
    }
    count++;
  }
  return nullptr;
}


















/*
std::size_t list_size(const node * head){//returns the number of items in the linked list
    std::size_t count = 0;
    //head = new node(56, nullptr);//
    //head->setdata_(53);//worse - actually changes the list that was passed in
    for(const node * p = head; p!=nullptr; p = p->link()){
        count++;
    }
     return count;
}
std::size_t list_size_rec(const node * head){
    if(head==nullptr){
        return 0;
    }
    else{
        return 1+ list_size_rec(head->link());
    }
}

void list_head_insert(node * & head, node * & tail, const node::value_type & value){
   // node x(value, head);
   // head = &x;
   //x is local, and so is destroyed at the end of the function call.
    //MUST use new.
    head = new node(value, head);
    if(tail==nullptr){
     tail = head;
    }

}
void list_tail_insert(node * & head, node * & tail, const node::value_type & value){

    node * temp = new node(value, nullptr);
    tail->setlink_(temp);
    tail = temp;
    if(head==nullptr)
        head = tail;

}
std::ostream & operator<<(std::ostream& out, const node* head){
    for(const node * p = head; p!=nullptr; p = p->link()){
        if(p->link()==nullptr)
            out<<p->data()<<std::endl;
        else
            out<<p->data()<<", ";
    }
    return out;
}

void list_head_remove(node * & headptr, node * & tailptr){
    node * temp = headptr;
    if(headptr==nullptr)//there's nothing in the list
        return;
    else if(headptr==tailptr){//There's one thing in the list
        delete headptr;
        headptr = tailptr = nullptr;
    }
    else{
        //reassign head
        headptr = headptr->link();
        delete temp;
    }


}

void list_tail_remove(node * & headptr, node * & tailptr){
    if(headptr==nullptr)//there's nothing in the list
        return;
    else if(headptr==tailptr){//There's one thing in the list
        delete headptr;
        headptr = tailptr = nullptr;
    }
    else{
        //reassign tail
        for(node* p = headptr; p!= nullptr; p=p->link()){
            if(p->link()->link() == nullptr){
                p->setlink_(nullptr);
                delete tailptr;
                tailptr = p;

            }
        }
    }
}

void list_tail_remove_rec(node * & headptr, node * & tailptr){
    if(headptr==nullptr)//there's nothing in the list
        return;
    else if(headptr==tailptr){//There's one thing in the list
        delete headptr;
        headptr = tailptr = nullptr;
    }
    else if(headptr->link()->link() == nullptr){
        headptr->setlink_(nullptr);
        delete tailptr;
        tailptr = headptr;


    }
    else{
        node * temp = headptr->link();//Super-annoying, but you need to do this; can't pass headptr->link() in directly
        list_tail_remove_rec(temp, tailptr);
    }
       }

void list_remove(node * & previous, node * & tailptr){
    //check to see if previous link is  the tailptr
    if(previous->link()==tailptr){
        list_tail_remove(previous, tailptr);
    }
    else{
        node* temp = previous->link();
        previous->setlink_(previous->link()->link());
        delete temp;
    }

}

void list_remove_value(node * & headptr, node * & tailptr, node::value_type value){
    if(headptr==nullptr)//there's nothing in the list
        return;
    else if(headptr==tailptr){//There's one thing in the list
        if(headptr->data()==value){
            delete headptr;
            headptr = tailptr = nullptr;
        }
    }
    else if(headptr->link()->data() == value){
        node* temp = headptr->link();
        headptr->setlink_(headptr->link()->link());
        delete temp;
    }
    else{
        //Super-annoying, but you need to do this; can't pass headptr->link() in directly
        node * temp = headptr->link();
        list_remove_value(temp, tailptr, value);
    }


}


*/
