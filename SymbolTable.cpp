#include<iostream>
using namespace std;
int s=10;
int hash_func(string str)
{
        int hashindex = 0;

        for(int i=0;i<str.size();i++)
        {
            hashindex = hashindex + (str[i]);
            hashindex %= s;
        }
        return hashindex;
}

class symbolinfo
{
    public:
    string name;
    symbolinfo *next;

};

class symboltable
{
    public:
    symbolinfo **head;

    void insrt(string n)
    {
        int ind=hash_func(n);
        symbolinfo *node=new symbolinfo();
        node->name = n;
        node->next=NULL;
        if(head[ind]==NULL)
        {
                head[ind]=node;
        }
        else
        {
            int check=search(n);
            if(check==1)
            {
                cout<<"Present in table.. Duplicate are not allowed..\n";
            }
            else
            {
                symbolinfo *temp=new symbolinfo();
                temp=head[ind];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=node;
            }
        }
    }
    int search(string test)
    {
            int c=0;
            symbolinfo *temp=new symbolinfo();
            int ind=hash_func(test);
            temp=head[ind];
             while(temp!=NULL)
            {
                if(temp->name==test)
                {
                    c++;
                    break;
                }
                temp=temp->next;
            }
            if(c==0)
            {
                return 0;
            }
            else
            {
                return c;

            }
    }
    void display(int x)
    {
         int i;
         for(i=0;i<x;i++)


         {

            symbolinfo *temp=new symbolinfo();
            temp=head[i];
            while(temp!=NULL)
            {
                cout<<"["<<temp->name<<"]"<<endl;
                temp=temp->next;
            }
         }
    }
};
int main()
{
    symboltable st;

    st.head=new symbolinfo*[s];

    for(int i=0;i<s;i++)
    {
        st.head[i]=new symbolinfo();
    }
    int ch=0;
    string s1,s2;
    while(ch!=4)
    {
        cout<<"\nPLEASE CHOOSE YOUR OPTION.\n";
        cout<<"Press 1 for Insert\n";
        cout<<"Press 2 for Display\n";
        cout<<"Press 3 for Search\n";
        cout<<"Press 4 for Exit\n";
        cout<<"Enter Your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter String:";
                cin>>s1;
                st.insrt(s1);
                break;
            }
            case 2:
            {
                st.display(s);
                break;
            }
            case 3:
            {
                cout<<"Enter your search key:";
                cin>>s2;
                int chk = st.search(s2);
                if(chk != 0)
                {
                    cout<<"Found in Table\n";
                }
                else
                {
                    cout<<"Not Found in Table\n";
                }
                break;
            }
        }
     }
    return 0;
}
