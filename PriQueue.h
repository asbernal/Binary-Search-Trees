#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
//#include "ArgumentManager.h"

using namespace std;

struct node{
    string command;
    string key;
    int prioNum;
    node* next;
    node(string cmd, string k, int pNum){
        command = cmd;
        key = k;
        prioNum = pNum;
        next = nullptr;
    }
};

class PriQueue
{
private:
    node* front;

public:
    PriQueue(){
        front = nullptr;
    }
    ~PriQueue(){
        if(front == nullptr){
            return;
        }
        else{
            node* temp;
            node* cu = front;
            while(cu != nullptr){
                temp = cu;
                cu = cu->next;
                delete temp;
            }
        }
    }
    string getFrontCommand(){return front->command;}
    string getFrontKey() {return front->key;}
    void PriorityEnqueue(string cmd, string k, int pNum){
        node* nd = new node(cmd, k, pNum);
        //prioEnqueueRecursive(front, nd);  // didn't complete, so i deleted the function
        if(front == nullptr){
            front = nd;
            return;
        }

        if(front->prioNum > nd->prioNum){ // >=
            nd->next = front;
            front = nd;
        }
        else{
            node* cu = front->next;
            node* prev = front;
            while(cu != nullptr){
                if(cu->prioNum > nd->prioNum){ //>=
                    nd->next = cu;
                    prev->next = nd;
                    return;
                }
                prev = cu;
                cu = cu->next;
            }
            prev->next = nd;
        }
    }
    void prioDequeue(){
        if(front == nullptr){
            return;
        }
        else{
            //node* cu = front;
            node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool isEmpty(){
        if(front == nullptr){
            return true;
        }
        return false;
    }
    void printPriorityQueue(){
        if(front == nullptr){
            cout << "EMPTY PRIORITY QUEUE" << endl;
        }
        else{
            node *cu = front;
            while(cu != nullptr){
                cout << cu->command << ":[" << cu->key << "](" << cu->prioNum << ")" << endl;
                cu = cu->next;
            }
        }
    } 
};