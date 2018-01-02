struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {
        }
};


void print_listnode(ListNode *A){

        while (A!=NULL)
        {
                cout<<A->val<<"\n";
                A=A->next;

        }
        puts("");
}

int length(ListNode *A){
        int kount=0;
        while (A!=NULL)
        {
                A=A->next;
                kount+=1;
        }
        return kount;
}

//Ans of problem
//Author: sumit saha
//problem link: https://www.interviewbit.com/problems/partition-list/

ListNode* merge(ListNode *A,ListNode *B){
        ListNode *temp=new ListNode(0);
        ListNode *head=temp;
        while (A!=NULL && B!=NULL) {
                if(A->val<B->val)
                {
                        temp->next=A;
                        temp=temp->next;
                        A=A->next;
                }
                else{
                        temp->next=B;
                        temp=temp->next;
                        B=B->next;

                }

        }
        if(A!=NULL) temp->next=A;
        if(B!=NULL) temp->next=B;
        //print_listnode(head);
        head=head->next;
        return head;
}
ListNode* mergesort(ListNode *A){

        ListNode *head=A,*p;
        int len=length(head);
        if(len==1) return head;
//        cout<<len<<"\n";
        int first=len/2;
        head=A;
        p=A;
        //cout<<"FF "<<first<<"\n";
        ListNode *pre=NULL;
        while (first--) {
                pre=p;
                p=p->next;
        }
        pre->next=NULL;
/*
        puts("OKK");
        print_listnode(head);
        puts("OKK");
        print_listnode(p);
        puts("END\n\n\n");
 */
        head=mergesort(head);
        p=mergesort(p);
        return merge(head,p);

}
