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

void CPPList::append(int number){
    ListNode * newNode = new ListNode;
    newNode->data()=number;
    if (ListHead == 0) {
        ListHead = newNode;
        newNode->next = 0;
    }
    else {
        ListEnd->next = newNode;
        newNode->next = 0;
    }
    ListEnd = newNode;
    ListSize++;
}


    

