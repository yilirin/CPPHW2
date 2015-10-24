//#include "stdafx.h"

#include "List.h"
////////////////////////////////////////////////////////////////////////////////////
//ListNode类的成员函数定义：
int &ListNode::data(){
    return value;
}

const int ListNode::data() const{
    return value;
}

////////////////////////////////////////////////////////////////////////////////////
//CPPList类的成员函数与析构函数定义：

CPPList::~CPPList(){
    clear();
}

bool CPPList::is_empty(){
    if (begin() == end()) {
        return 1;
    }
    else
        return 0;
}

//不通过定义成员变量来标记size，而改用遍历的方式，便于检验程序的安全性。
int CPPList::size(){
    int size=0;
    for (ListNode *tmp = ListHeader; tmp != ListTrailer; tmp = tmp->next) {
        size++;
    }
    return size;
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

//
void CPPList::append(int number){
    ListNode * newNode = new ListNode();
    newNode->data() = number;
    if (is_empty()) {
        ListHeader = newNode;
        ListEnd = newNode;
    }
    else {
        ListEnd->next = newNode;
        ListEnd = ListEnd->next;
    }
    newNode->next = ListTrailer;
}

//找到current前面一个的节点
ListNode *CPPList::findPreNode(ListNode *current){
    for (ListNode * tmp = ListHeader; tmp != ListTrailer; tmp = tmp->next) {
        if(current == tmp->next){
            return tmp;
        }
    }
    return 0;
}

void CPPList::insert(ListNode *current, int number){
    if (!is_empty()){                               //do not insert if the list is empty
        ListNode *tmp = new ListNode;
        tmp->data() = number;
        if (current == ListHeader) {
            tmp->next = current;
            ListHeader = tmp;
        }
        else {
            tmp->next = current;
            findPreNode(current)->next = tmp;
        }
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
}

void CPPList::clear(){
    ListNode * tmp;
    while(!is_empty()) {
        tmp = ListHeader;
        ListHeader = ListHeader->next;
        delete tmp;
    }
}




    

