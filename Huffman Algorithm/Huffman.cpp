//SERKAN KOÇOÐLU  - HUFFMAN C Implementation with struct nodes
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
class Huffman_Codes
{
 struct New_Node
 {//variables 
  char data;
 int frequence; //Frequency of the letter is the key point in Huffman algorithm to create an optimized result; frequency is inversely proportional to the order of priority !!!
  New_Node* left;  //pointers used to reach nodes.
  New_Node* right;
  New_Node(char data,int frequence) : data(data), frequence(frequence),
left(NULL),  //initialize
right(NULL) {}
 ~New_Node()   //overloaded method to delete
 {}
 };
 
New_Node* top;	

void print(New_Node* root, string str)
{
 if(root->data == 's')  //value in the root node
 {
  print(root->left, str + "0");  // if goes left n tree 
  print(root->right, str + "1"); // if goes right in tree 
 }

 if(root->data != 's')
 {
   cout << root->data <<"  " << str << "\n";
 }
}

public:
  Huffman_Codes() {};
  ~Huffman_Codes()  //overloaded method to delete top to merge leafs!
  {
    delete top;
  }
  
   struct compare  
 {
  bool operator()(New_Node* left, New_Node* right)
  {
    return (left->frequence > right->frequence); // sol leaf büyükse 0 return eder ;deðilse 1 (priority)
  }
};

void Huffman(char data [], int frequence[], int size,string s)  //Structure of huffman !!
  {
   New_Node* left;
   New_Node* right;
     priority_queue<New_Node*, vector<New_Node*>, compare > minHeap;  //priority queue for storing leafs
	
for(int i=0; i<size;i++)
   minHeap.push(new New_Node(data[i], frequence[i]));   //heap filled with all nodes at first !
   
while(minHeap.size() != 1) // size dan bir e düþene kadar ;
    {
      left = minHeap.top();  //queue daki ilk elemaný sol node a ekle
    minHeap.pop();
      right = minHeap.top(); //queue daki ilk elemaný sað node a ekle
    minHeap.pop();

      top = new New_Node('s', left->frequence + right->frequence);
      top->left  = left;
      top->right = right;
      minHeap.push(top); // ÖNEMLÝ NOKTA: LEAFLERÝ BÝRLEÞTÝRÝR ; ESKÝ SOL VE ESKÝ SAÐ LEAFLERÝ TOPLAYIP HEAP E ATAR 
     }
    print(minHeap.top(), "---> "); // to show better
    
    cout <<"\n\nENCODED STRING : " <<s<< "\n";
    cout << "Decoded string : ";
    New_Node* root =minHeap.top();

	struct New_Node* curr = root; 
	
		string result = ""; 
	for (int i=0;i<s.size();i++) //goes one by one untill the end
	{ 
		if (s[i] == '0') //goes left leaf
		curr = curr->left; 
		else              //goes right leaf
		curr = curr->right; 

		if (curr->left==NULL and curr->right==NULL) // IF A Leaf node 
		{ 
			result =result+ curr->data; 
			curr = root; 
		} 
	} 
 cout<< result <<endl; 
 }
};
	
 int main(int argc, char** argv) //O(nlog n)
 {
  Huffman_Codes hc;
  
  char data[]={'A','B','I','M','S','X','Z'};  // I DIDNT ADD END OF FILE BEACUSE IT DIDNT SHOWN IN THE Q1 TABLE PROPERLY
  int frequence []={ 12, 7, 18, 10, 9, 5,2};
     string encodedString1="01100010101010";     // ZAIIII
        string encodedString2="1000100001010 ";  // IAIABI
        string encodedString3="11100100111101";  // MAIXI
        string encodedString4="1000010011100 ";  // IABXA
    
  int size = sizeof(data);
  cout << "Huffman encoding:\n";
  hc.Huffman(data, frequence, size,encodedString1);
}	
