//#include "stdafx.h"

#include "List.h"
////////////////////////////////////////////////////////////////////////////////////
int &ListNode::data(){
    return value;
}

const int ListNode::data() const{
    return value;
}

////////////////////////////////////////////////////////////////////////////////////

bool CPPList::is_empty(){
    if (begin() == end()) {
        return 1;
    }
    else
        return 0;
}

int CPPList::size(){
    return ListSize;
}


ListNode *CPPList::begin(){
    return ListHead;
}

ListNode *CPPList::end(){
    return ListEnd;
}

const ListNode *CPPList::begin() const{
    return ListHead;
}

const ListNode *CPPList::end() const{
    return ListEnd;
}

ListNode * CPPList::next(const ListNode *current){
    return current->next;
}

const ListNode * CPPList::next(const ListNode *current) const{
    return current->next;
}
//ListHead ListEnd全都定义为哨兵。
void CPPList::append(int number){
    ListNode * newNode = new ListNode;
    newNode->data()=number;
    if (ListHead == 0) {
        ListHead = newNode;
        newNode->next = ListEnd;
    }
    else {
        ListEnd = newNode;
        newNode->next = ListEnd;
    }
    ListSize++;
}

int CPPList::find(ListNode *current){
    for (ListNode * tmp = ListHead; tmp != ListEnd; tmp = tmp->next) {
        if(current == tmp){
            return 1;
        }
    }
    return 0;
}

void CPPList::insert(ListNode *current, int number){
    if (find(current)) {
        ListNode *tmp = new ListNode;
        tmp->next = current;
        current = tmp;
        current->data() = number;
    }
}

void CPPList::remove(ListNode *current){
    if (find(current)){
        ListNode *tmp;
        tmp = current;
        current = current->next;
        delete tmp;
        /*How about changing the above two lines to
         tmp = current->next;
         delete current.
         */
    }
}




    

