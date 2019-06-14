#include<iostream>
using namespace std;
int s=10;
int hash_func(string str) {
        int hashindex = 0;

        for(int i=0;i<str.size();i++){
            hashindex += ((str[i]*13) % 23) * ((str[str.size()-1-i]*19) % 29) + 11;

            hashindex %= s;
        }
        return hashindex;
}

class symbolinfo{
    public:
    string name;
    string type;
    symbolinfo *next;

};

class symboltable{
public:
    symbolinfo **head;

    void insrt(string n,string t){
        string s=n;
        int ind=hash_func(s);
        symbolinfo *node=new symbolinfo();
        node->name = n;
        node->type = t;
        node->next=NULL;
        if(head[ind]==NULL){
                head[ind]=node;

        }
        else{
            int check=lookup(s);
            if(check==1)
            {
                cout<<"Error In Code\n";
            }
        else{
            symbolinfo *temp=new symbolinfo();
            temp=head[ind];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=node;
            }
        }
    }

    int lookup(string test)
    {
            int c=0;
            symbolinfo *temp=new symbolinfo();
            int ind=hash_func(test);
            temp=head[ind];
             while(temp!=NULL)
            {
                if(temp->name==test){
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
        void dump(int x)
    {
         int i;
         for(i=0;i<x;i++)
         {

            symbolinfo *temp=new symbolinfo();
            temp=head[i];



                while(temp!=NULL)
                {
                    cout<<"["<<temp->name<<"]"<<"["<<temp->type<<"]"<<endl;
                //cout<<"working"<<endl;

                    temp=temp->next;
                }
            //cout<<endl;


        }
    }
};
int main()
{
    symboltable st;

    st.head=new symbolinfo*[s];

    for(int i=0;i<s;i++){
            st.head[i]=new symbolinfo();
    }
    int ch=0;
    string s1,s2,s3;
     while(ch!=4){
    cout<<"\nPLEASE CHOOSE YOUR OPTION.\n";
    cout<<"PRESS 1 FOR ADDING ELEMENT\n";
    cout<<"PRESS 2 FOR DUMP\n";
    cout<<"PRESS 3 TO LOOK UP\n";
    cout<<"PRESS 4 TO EXIT\n";
    cin>>ch;
    //cout<<"Enter Your Table Size\n";
    //cin>>s;

    if(ch==1){
    cin>>s1>>s2;

    st.insrt(s1,s2);
    }
    else if(ch==2){

            st.dump(s);
    }
    else if(ch==3)
    {
        cin>>s3;
        int chk = st.lookup(s3);
        if(chk != 0)
        {
            cout<<"Found\n";
        }
        else
        {
            cout<<"Not Found\n";
        }
    }


     }



    return 0;
}

