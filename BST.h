#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct treeNode{
    string strNode;
    treeNode* left;
    treeNode* right;
    treeNode(string str){
        strNode = str;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    treeNode* root;

public:
    BST(){
        root = nullptr;
    }
    ~BST(){

    }
    treeNode* getRoot(){return root;}
    void addBST(treeNode* _root, string str){
        //cout << "HERE\n";
        if(root == nullptr){
            //cout << "root == nullptr" << endl;
            treeNode* newTN = new treeNode(str);
            root = newTN;
        }
        else if(_root->strNode.length() == str.length()){
            //replace with new string
            _root->strNode = str;
        }
        else if(_root->strNode.length() < str.length()){
            if(_root->right == nullptr){
                treeNode* newTN = new treeNode(str);
                _root->right = newTN;
            }
            else{
                addBST(_root->right, str);
            }
        }
        else if(_root->strNode.length() > str.length()){
            if(_root->left == nullptr){
                treeNode* newTN = new treeNode(str);
                _root->left = newTN;
            }
            else{
                addBST(_root->left, str);
            }
        }
    }
    void orderToPrint(string order, ofstream& fo){
        if(order == "Preorder"){
            preorder(root, fo);
        }
        else if(order == "Inorder"){
            inorder(root, fo);
        }
        else if(order == "Postorder"){
            postorder(root, fo);
        }
    }
    void preorder(treeNode* _root, ofstream& fo){
        if(_root == nullptr){
            return;
        }
        cout << _root->strNode << endl;
        fo << _root->strNode << endl;

        preorder(_root->left, fo);
        preorder(_root->right, fo);
    }
    void inorder(treeNode* _root, ofstream& fo){
        if(_root == nullptr){
            return;
        }
        inorder(_root->left, fo);

        cout << _root->strNode << endl;
        fo << _root->strNode << endl;

        inorder(_root->right, fo);
    }
    void postorder(treeNode* _root, ofstream& fo){
        if(_root == nullptr){
            return;
        }
        cout << _root->strNode << endl;
        fo << _root->strNode << endl;

        postorder(_root->left, fo);
        postorder(_root->right, fo);
    }

};