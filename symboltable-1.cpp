#include<iostream>
using namespace std;
int show();

int s=10;
int hash_func(string str)
{
        int hashindex = 0;

        for(int i=0;i<str.size();i++)
        {
           hashindex = hashindex + i*(str[i]);

        }
        hashindex %= s;

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

    void insert(string n)
    {
        int index=hash_func(n);
        symbolinfo *node=new symbolinfo();
        node->name = n;
        node->next=NULL;
        if(head[index]==NULL)
        {
                head[index]=node;
        }
        else
        {
            int check=search(n);
            if(check==1)
            {
                cout<<"Present in table___SO Duplicate are not allowed__"<<endl;
            }
            else
            {
                symbolinfo *temp=new symbolinfo();
                temp=head[index];
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
            int index=hash_func(test);
            temp=head[index];
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
    void lookup(int x)
    {
         int i;
         for(i=0;i<x;i++)
         {

            symbolinfo *temp=new symbolinfo();
            temp=head[i];
            while(temp!=NULL)
            {
                cout<<"["<<temp->name<<"]-->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
         }
    }

};

int main()
{
    symboltable st;

    st.head=new symbolinfo*[s];

    for(int i=0;i<s;++i)
    {
        st.head[i]=new symbolinfo();
    }
    string s1,s2;
    int choice = show();
    while( 1 ){
        switch(choice){
        case 1:
            {
                cout<<"Enter String:";
                cin>>s1;
                st.insert(s1);
                break;
            }
        case 2:
            {
                 st.lookup(s);
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
            //break;
        case 4:
            {
                cout<<"Exit";
            }
        default:

            return 0;
        };
       choice = show();
    }

    return 0;
}

int show()
{
    string message= "1. Insert\n"
                    "2. Lookup \n"
                    "3. Search\n"
                    "4. Exit\n"
                    ;
    cout<<message<<endl;
    cout<<"Enter your choice"<<endl;
    int choice;
    cin>>choice;
    return choice;
}
