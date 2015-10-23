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
    return ListHeader;
}

ListNode *CPPList::end(){
    return ListTrailer;
}

const ListNode *CPPList::begin() const{
    return ListHeader;
}

const ListNode *CPPList::end() const{
    return ListTrailer;
}

ListNode * CPPList::next(const ListNode *current){
    return current->next;
}

const ListNode * CPPList::next(const ListNode *current) const{
    return current->next;
}
//ListHeader ListTrailer全都定义为哨兵。
void CPPList::append(int number){
    ListNode * newNode = new ListNode();
    newNode->data() = number;
    if (ListHeader == 0) {
        ListHeader = newNode;
        ListEnd = newNode;
    }
    else {
        ListEnd->next = newNode;
        ListEnd = ListEnd->next;
    }
    newNode->next = ListTrailer;
    ListSize++;
}

ListNode *CPPList::findPreNode(ListNode *current){
    for (ListNode * tmp = ListHeader; tmp != ListTrailer; tmp = tmp->next) {
        if(current == tmp->next){
            return tmp;
        }
    }
    return 0;
}

void CPPList::insert(ListNode *current, int number){
    ListNode *tmp = new ListNode;
    tmp->data() = number;
    if (current == ListHeader) {
        tmp->next = current;
        ListHeader = tmp;
    }
    else {
        tmp->next = current;
        findPreNode(current)->next = tmp;
        ListSize++;
    }
}

void CPPList::remove(ListNode *current){
    if (current == ListHeader) {
        ListHeader = current->next;
    }
    else{
        findPreNode(current)->next = current->next;
    }
    delete current;
    ListSize--;
}




    

