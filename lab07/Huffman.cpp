#include <iostream>
#include <queue>

using namespace std;
struct Node{
  char alpha;
  int freq;
  Node *left;
  Node *right;

  Node(){};
  Node(char letter, int freq){
    this->alpha = letter;
    this->freq = freq;
    left = right = NULL;
  };
  ~Node(){};
};
struct comp{
  bool operator()(Node* l, Node* r){
    return (l->freq >r->freq);
  }
};

void print(Node* root, string str, char A){
    if (root == NULL)
        return;
    if (root->alpha == A)
        cout << root->alpha << ":" << str <<endl;
    print(root->left, str + "0",A);
    print(root->right, str + "1",A);
}

int main(int argc,char **argv) {
  int size = 6;
  priority_queue<Node*, vector<Node*>, comp> Q;
  Node *z, *y, *x;
  int freq; 

  for (int i = 0; i < size; i++){
    cin >> freq;
    Q.push(new Node(i+'A', freq));
  }
//  print(Q.top(),"");
  for(int i = 0; i < size-1; i++){
    z = new Node;

    z->left = x = Q.top();
    Q.pop();

    z->right = y = Q.top();               
    Q.pop();

    z->freq = x->freq + y->freq;
    Q.push(z);
  }
  for( int i = 0; i < size; i++)
    print(Q.top(),"",'A'+i);
}
