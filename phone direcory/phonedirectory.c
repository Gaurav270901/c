#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[20],ph_no[10];
    struct node *next,*prev;
}*head=NULL;
void create();
int searchname(char[]);
int searchno(char[]);
void delete();
void display();
void update();
void sort();
void search();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.create a new contact\n2.display all contact \n3.delete contact\n4.update contact\n5.sort contact\n6.search contact\n7.exit\nenter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:display();break;
            case 3:delete();break;
            case 4:update();break;
            case 5:sort();break;
            case 6:search();break;
            case 7:exit(0);
        }
    }
    
}


void create()
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    printf("enter the name :\t");
    scanf("%s",temp->name);
    
        if(searchname(temp->name)==1)
        {
            printf("name already exist.\n");
            return;
        }
    printf("enter the phone number:\t");
    scanf("%s",temp->ph_no);
    if(searchno(temp->ph_no)==1)
        {
            printf("phone number already exist.\n");
            return;
        }

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        q=head;
        while(q->next!=NULL)
            q=q->next;
        q->next=temp;
        temp->prev=q;    
    }
}

void display()
{
    struct node *q;
    if(head==NULL)
    {
        printf("your contact is empty!!!!");
        return;
        
    }
    for(q=head;q!=NULL;q=q->next)
        printf("name :%s\t\tphone :%s\n",q->name,q->ph_no);
}



int searchname(char *a)
{
    struct node *q;
    for(q=head;q!=NULL;q=q->next)
    {
        if(strcmp(a,q->name)==0)
            return 1;
        else 
            return 0;    
    }
}



int searchno(char *a)
{
    struct node *q;
    for(q=head;q!=NULL;q=q->next)
    {
        if(strcmp(a,q->ph_no)==0)
            return 1;
        else 
            return 0;    
    }
}

void delete()
{
    char ch[20];
    if(head==NULL)
    {
        printf("you have no contacts in your list\n");
        return;
    }
    printf("search the name:\t");
    scanf("%s",ch);
    struct node *q,*temp,*p;
    for(q=head;q!=NULL;q=q->next)
    {
        if(strcmp(ch,q->name)==0)
        {
            if(q==head && q->next==NULL)
            {
                head=NULL;
                printf("contact deleted successfully!!!\n");
                return;

            }
            else if(q==head)
            {
                head=head->next;
                head->prev=NULL;
                free(q);
                printf("contact deleted successfully!!!\n");
                return;
            }
            else if(q->next==NULL)
            {
                temp=q;
                q=q->prev;
                temp->prev=NULL;
                q->next=NULL;
                free(temp);
                printf("contact deleted successfully!!!\n");
                return;
            }
            else
            {
                
                temp=q->next;
                p=q->prev;
                p->next=NULL;
                q->prev=NULL;
                q->next=NULL;
                temp->prev=NULL;
                p->next=temp;
                temp->prev=p;
                free(q);
                printf("contact deleted successfully!!!\n");
                return;
            }
        }

    }
    printf("<<<<<CONTACT NOT FOUND>>>>>\n");

}



void update()
{
    struct node *q;
    char ch[20],na[20],ph[20];
    if(head==NULL)
    {
        printf("your contact list is empty...!!!\n");
        return;
    }
    printf("search the name to be updated :\t");
    scanf("%s",ch);
    for(q=head;q!=NULL;q=q->next)
    {
        if(strcmp(ch,q->name)==0)
        {
            printf("\n1.update phone number\n2.update name\nenter your choice:\t");
            int a;
            scanf("%d",&a);
            if(a==1)
            {
                do
                {
                    scanf("%s",q->ph_no);
                    if(searchname(q->ph_no)==1)
                    {
                        printf("the number already exist.....\nenter the other number:\t");
                    }
                }while(searchname(q->ph_no)==1);
                printf("contact updated successfully!!!!");
                return;
            }
            else
            {
                printf("enter the new name for contact:\t");
                do
                {
                    scanf("%s",q->name);
                    if(searchname(q->name)==1)
                    {
                        printf("the name already exist.....\nenter the other name:\t");
                    }
                }while(searchname(q->name)==1);
                printf("contact updated successfully!!!!");
                return;

            }
        }
    }

    printf("<<<<CONTACT NOT FOUND>>>>");
}



void sort()
{
    struct node *temp,*q,*p;
    char na[20],ph[20];
    if(head==NULL)
    {
        printf("you have no contact in your list....\n");
        return;
    }


    q=head;
    while(q!=NULL)
    {
        p=q->next;
        while(p!=NULL)
        {
            if(strcmp(q->name,p->name)>0)
            {
                strcpy(na,q->name);
                strcpy(ph,q->ph_no);
                strcpy(q->name,p->name);
                strcpy(q->ph_no,p->ph_no);
                strcpy(p->name,na);
                strcpy(p->ph_no,ph);

            }
            p=p->next;
        }
        q=q->next;
    }
    printf("......sorted contacts are.....\n");
    display();
}



void search()
{
    char name[20],ch[20],phone[20];
    if(head==NULL)
    {
        printf("you have no contact in your list....\n");
        return;
    }
    printf("1.search by name\n2.search by number\nenter your choice:\t");
    int b;
    do
    {
        scanf("%d",&b);
    } while (b<1 || b>2);
    if(b==1)
    {
        printf("enter the name to be searched:\t");
        scanf("%s",name);
        int size=strlen(name);
        int flag,no=-1;
        struct node *q;
        q=head;
        for(q=head;q!=NULL;q=q->next)
        {
            flag=0;
            for(int i=0;i<size;i++)
            {
                if(name[i]!=q->name[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("name:%s\tnumber:%s\n",q->name,q->ph_no);
                no++;
            }
        }
        if(no==-1)
            printf("search name does not match\n");
    }            
    else
    {
        printf("enter the number to be searched:\t");
        scanf("%s",phone);
        int size=strlen(phone);
        int flag,no=-1;
        struct node *q;
        q=head;
        for(q=head;q!=NULL;q=q->next)
        {
            flag=0;
            for(int i=0;i<size;i++)
            {
                if(phone[i]!=q->ph_no[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("name:%s\tnumber:%s\n",q->name,q->ph_no);
                no++;
            }
        }
        if(no==-1)
            printf("search name does not match\n");
    }            

}