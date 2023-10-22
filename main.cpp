#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "ArgumentManager.h"
#include "PriQueue.h"
#include "Queue.h"
#include "BST.h"
using namespace std;

string getCommand(string& str){
    if(str == "Inorder" || str == "Preorder" || str == "Postorder"){
        return str;
    }
    else{
        int index = str.find(':');
        string temp;
        for(int i = 0; i < index; i++){
            temp += str[i];
        }
        if(temp == "DECODE"){
            return temp;
        }
        else if(temp == "REPLACE"){
            return temp;
        }
        else if(temp == "ADD"){
            return temp;
        }
        else if(temp == "REMOVE"){
            return temp;
        }
        else if(temp == "SWAP"){
            return temp;
        }
        else if(temp == "BST"){
            return temp;
        }
    }
}
bool travereBST(string str){
    if(str == "Inorder" || str == "Preorder" || str == "Postorder"){
        return true;
    };
    return false;
}
int getPriority(string str){
    int i;
    for(i = str.length()-1; i >= 0; i--){
        if(str[i] == '('){
            i++;
            break;
        }
    }
    return stoi(str.substr(i, str.length()- 1 - i));
}
string getKey(string cmd, string str){
    if(cmd == "BST"){
        return "-1";
    }
    else{
        string key;
        for(int i = str.find('[') + 1; i < str.find(']'); i++){
            key += str[i];
        }
        return key;
    }
}
char getBeforeChar(string str){
    return str[0];
}
char getAfterChar(string str){
    return str[2];
}
int main(int argc, char *argv[]){
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    ifstream fin(input);
    ofstream fout(output);

    // ifstream fin("input3.txt");
    // ofstream fout("output3.txt");

    PriQueue pq;

    string command;
    string key;
    int prioNum;

    string line;
    while(getline(fin, line)){
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());

        command = getCommand(line);
        if(travereBST(command)){

            break;
        }
        key = getKey(command, line);
        prioNum = getPriority(line);
        
        pq.PriorityEnqueue(command, key, prioNum);

    }
    pq.printPriorityQueue();
    Queue q = Queue();
    BST bst;

    int instruct = 0;
    cout << "\nWorking on the priority queue" << endl;
    while(!pq.isEmpty()){
        cout << "\n\tInstruction line: " << ++instruct << " -> " << pq.getFrontCommand() << ":[" << pq.getFrontKey() << "]\n";
        if(pq.getFrontCommand() == "REPLACE" && !q.isEmpty()){
            cout << q.getFrontCode() << endl;
            //pass the cmd's key
            char bf = getBeforeChar(pq.getFrontKey());
            char af = getAfterChar(pq.getFrontKey());
            q.replace(bf, af, 0);
            string temp = q.getFrontCode();
            q.dequeue();
            q.enqueue(temp);
            cout << temp << endl;        
        }
        else if(pq.getFrontCommand() == "ADD" && !q.isEmpty()){
            cout << q.getFrontCode() << endl;
            char bf = getBeforeChar(pq.getFrontKey());
            char af = getAfterChar(pq.getFrontKey());
            q.add(bf, af, 0);
            string temp = q.getFrontCode();
            q.dequeue();
            q.enqueue(temp);
            cout << temp << endl; 
        }
        else if(pq.getFrontCommand() == "REMOVE" && !q.isEmpty()){
            cout << q.getFrontCode() << endl;
            char re = getBeforeChar(pq.getFrontKey());
            q.remove(re);
            string temp = q.getFrontCode();
            q.dequeue();
            q.enqueue(temp);
            cout << temp << endl;
        }
        else if(pq.getFrontCommand() == "SWAP" && !q.isEmpty()){
            char s1 = getBeforeChar(pq.getFrontKey());
            char s2 = getAfterChar(pq.getFrontKey());
            cout << q.getFrontCode() << endl;
            q.swap(s1, s2, 0);
            string temp = q.getFrontCode();
            q.dequeue();
            q.enqueue(temp);
            cout << temp << endl;
        }
        else if(pq.getFrontCommand() == "BST" && !q.isEmpty()){
            cout << q.getFrontCode() << endl;
            string temp = q.getFrontCode();
            q.dequeue();
            bst.addBST(bst.getRoot(), temp);
        }
        else if(pq.getFrontCommand() == "DECODE"){
            q.enqueue(pq.getFrontKey());
        }

        pq.prioDequeue();
    }
    cout << "\nPriority Queue is supposedly empty" << endl;
    //q.printQueue();
    cout << "\nThe way the BST should be printed: " << command << endl << endl;
    bst.orderToPrint(command, fout);
    cout << endl;


    fin.close();
    fout.close();
    return 0;
}
