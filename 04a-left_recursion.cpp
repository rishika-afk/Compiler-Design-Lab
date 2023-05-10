#include<iostream>
#include<string>
using namespace std;
int main()
{  string ip,op1,op2,temp;
    int sizes[10] = {};
    char c;
    int n,j,l;
    cout<<"Enter the Parent Non-Terminal : ";
    cin>>c;
    ip.push_back(c);
    op1 += ip + "\'->";
    ip += "->";
    op2+=ip;
    cout<<"Enter the number of productions : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {   cout<<"Enter Production "<<i+1<<" : ";
        cin>>temp;
        sizes[i] = temp.size();
        ip+=temp;
        if(i!=n-1)
            ip += "|";
    }
    cout<<"Production Rule : "<<ip<<endl;
    for(int i=0,k=3;i<n;i++)
    {
        if(ip[0] == ip[k])
        {
            cout<<"Production "<<i+1<<" has left recursion."<<endl;
            if(ip[k] != '#')
            {
                for(l=k+1;l<k+sizes[i];l++)
                    op1.push_back(ip[l]);
                k=l+1;
                op1.push_back(ip[0]);
                op1 += "\'|";
            }
        }
        else
        {
            cout<<"Production "<<i+1<<" does not have left recursion."<<endl;
            if(ip[k] != '#')
            {
                for(j=k;j<k+sizes[i];j++)
                    op2.push_back(ip[j]);
                k=j+1;
                op2.push_back(ip[0]);
                op2 += "\'|";
            }
            else
            {
                op2.push_back(ip[0]);
                op2 += "\'";
            }}}
    op1 += "#";
    cout<<op2<<endl;
    cout<<op1<<endl;
    return 0;}

/* Output
No. of states : 3
No. of transitions : 2
state name : A
path : 0
Enter end state from state A travelling through path 0 : 
B
path : 1
Enter end state from state A travelling through path 1 : 
C
state name : B
path : 1
Enter end state from state B travelling through path 1 : 
B C
path : 0
Enter end state from state B travelling through path 0 : 
C
state name : C
path : 0
Enter end state from state C travelling through path 0 : 

path : 1
Enter end state from state C travelling through path 1 : 

Enter final state of NFA : 
C
Printing NFA table :- 
0       1
A  [B]     [C]
B  [C]  [B, C]
C   []      []
DFA :- 

{'A': {'0': 'B', '1': 'C'}, 'B': {'0': 'C', '1': 'BC'}, 'C': {'0': '', '1': ''}, 'BC': {'0': 'C', '1': 'BC'}, '': {}}

Printing DFA table :- 
0    1
A     B    C
B     C   BC
C           
BC    C   BC
    NaN  NaN

Final states of the DFA are :  ['C', 'BC']
*/
