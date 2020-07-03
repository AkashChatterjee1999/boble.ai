#include <bits/stdc++.h> 
using namespace std; 
const int no_of_alphabets = 26; 
#define getIndex(a) (a-'a')
#define BOOST ios::sync_with_stdio(0)cin.tie(0);cout.tie(0)
char getCharacter(int a){
    return a+97;    
}
// Upto this part contains basic intializations and for future use

// Basic node structure of our tree
class Node{
    public:
    class Node *links[no_of_alphabets];
    bool endOfWord;

    //This function creates a tree based on strings array input
    Node *Create_Tree(string *strings,int length){
        Node *root = this->initialize_node();
        for (int i = 0; i < length; i++) 
            this->insertNode(root, strings[i]);
        return root; 
    } 

    //This function inserts a node in the tree
    void insertNode(Node *root, string Word){ 
        Node *ptr = root;   
        for (int i = 0; i < Word.length(); i++) { 
            int index = getIndex(Word[i]);
            if (ptr->links[index]==NULL) 
                ptr->links[index] = initialize_node(); 
            ptr = ptr->links[index]; 
        } 
        ptr->endOfWord = true; 
    }

    //This function basically allocates the meemory for the node
    Node* initialize_node() { 
        Node *ptr =  new Node; 
        for (int i = 0; i < no_of_alphabets; i++)  ptr->links[i] = NULL; 
        ptr->endOfWord = false;  
        return ptr; 
    } 

    //This function serializes a tree
    void serialize(Node* root, char str[], int level) { 
    if (root->endOfWord){ 
        str[level] = '\0'; 
        cout << str << endl; 
    } 
    int i; 
    for (i = 0; i < no_of_alphabets; i++)  { 
        if (root->links[i])  { 
                str[level] = getCharacter(i); 
                serialize(root->links[i], str, level + 1); 
            } 
        } 
    } 

    //This function quickly builds a tree based on the serialized object
    Node *deserialize(string path){
        ifstream file(path);
        string str;
        int cnt = 0;
        string res1[20000];
        while(getline(file,str)){
            res1[cnt] = (str);
            ++cnt;
            cout<<str<<endl;
        }
        file.close();
        Node *root = this->Create_Tree(res1,cnt);
        return root;
    }

}ob;
int main() {
    char st[2000];
    //freopen("serialized.bin","w",stdout);    This needs to be uncommented when serializations is done
    string keys[] = {"hello", "a", "there", "answer", "any", "by", "bye", "their" }; //INputs of a file
    Node *root = ob.Create_Tree(keys,8);
    //ob.serialize(root,st,0);
    //Node *root = ob.deserialize("serialized.bin");
    //ob.search(root, "the")? cout << "Yes\n" : cout << "No\n"; 
    //ob.search(root, "lola")? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
} 
