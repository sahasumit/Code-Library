#include<iostream>
using namespace std;
struct node
{

    int data;
    node *next;

};
class list
{

private:
    node *head,*tail;

public:
    list()
    {

        head=NULL;
        tail=NULL;
    }

    //Adding node in LINKED LIST at last
    void  createnode(int value)
    {

        node *temp=new node();
        temp->data=value;
        temp->next=NULL;

        if(head==NULL)
        {

            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;

        }
    }

    // DISPLAYING LINKED LIST
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {

            cout<<temp->data<<"\t";
            temp=temp->next;

        }
        cout<<"\n";
    }

    //Insert from a node
    void insert_start(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;

    }


    // delete from first
    void delete_first()
    {

        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;


    }

    //delete from last
    void delete_last()
    {
        node *cur=new node;
        node *prev=new node;
        cur=head;
        while(cur->next!=NULL)
        {

            prev=cur;
            cur=cur->next;

        }
        tail=prev;
        prev->next=NULL;
        delete cur;


    }
    //delete from pos
    void delete_pos(int pos)
    {
        node *cur=new node;
        node *prev=new node;


        cur=head;
        for(int i=1; i<pos; i++)
        {
            prev=cur;
            cur=cur->next;
        }

       prev->next=cur->next;
       delete cur;
    }






};


int main()
{

    list mylinklist;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int order;
        cin>>order;
        if(order==1)
        {
            int val;
            cin>>val;
            mylinklist.createnode(val);

        }
        else if(order==2)
        {
            int val;
            cin>>val;
            mylinklist.insert_start(val);

        }
        else if(order==3)
        {

            mylinklist.delete_first();

        }
        else if(order==4){
        int pos;
        cin>>pos;
        mylinklist.delete_pos(pos);

        }
        else
        {
            mylinklist.display();

        }
    }


}
 
