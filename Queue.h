#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
//#include "ArgumentManager.h"

using namespace std;

struct decode{
    string code;
    decode* next;
    decode(string str){
        code = str;
        next = nullptr;
    }
};

class Queue
{
private:
    decode* front;

public:
    Queue(){
        front = nullptr;
    }
    decode* getFront(){return front;}
    string getFrontCode(){return front->code;}
    bool isEmpty(){return front == nullptr;};
    void enqueue(string str){
        if(front == nullptr){
            decode* node = new decode(str);
            front = node;
            //front->code = str;
            //front->next = nullptr;
        }
        else{
            addToQueueRecursive(front, str);
        }
    }
    void addToQueueRecursive(decode* _front, string str){
        if(_front->next == nullptr){
            decode* dc = new decode(str);
            // dc->code = str;
            // dc->next = nullptr;
            _front->next = dc;
            return;
        }
        else{
            addToQueueRecursive(_front->next, str);
        }
    }
    void dequeue(){
        if(front == nullptr){
            return;
        }
        else{
            decode* temp = front;
            front = front->next;
            delete temp;

            // decode* temp = front;
            // front = front->next;
            // decode* cu = front;
            // while(cu->next != nullptr){
            //     cu = cu->next;
            // }
            // cu->next = temp;
            // temp->next = nullptr;
        }
    }
    void printQueue(){
        if(front == nullptr){
            cout << "q is empty" << endl;
            return;
        }
        decode* cu = front;
        do{
            cout << cu->code << endl;
            cu = cu->next;
        }while(cu != nullptr);
    }

    void replace(char bf, char af, int s){
        if(s > front->code.length()){
            return;
        }
        else{
            if(front->code[s] == bf){
                front->code[s] = af;
            }
            replace(bf, af, ++s);
        }
    }
    void add(char bf, char af, int s){
        // if(s > front->code.length()){
        //     return;
        // }
        // else{
        //     if(front->code[s] == bf){
        //         front->code[s] = af;
        //     }
        //     add(bf,af, ++s);
        // }
        string temp;
        for(int i = 0; i < front->code.length(); i++){
            temp += front->code[i];
            if(front->code[i] == bf){
                temp += af;
            }
        }
        front->code = temp;
    }
    void remove(char c){
        string temp;
        for(int i = 0; i < front->code.length(); i++){
            if(front->code[i] != c){
                temp += front->code[i];
            }
        }
        front->code = temp;
    }
    void swap(char a, char z, int s){
        if(s < front->code.length()){
            if(front->code[s] == a){
                front->code[s] = z;
            }
            else if(front->code[s] == z){
                front->code[s] = a;
            }
            swap(a, z, ++s);
        }
    }
};