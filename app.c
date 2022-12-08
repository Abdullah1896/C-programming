#include<stdlib.h>
#include<stdio.h>
#include"app.h"

#define ACTIVE 1
#define RESTRICTED 0
#define CLOSED 0

static int i=0;

void Create_Stack(Stack*ps)
{
    ps->top=NULL;
    ps->size=0;
}

/*to PUSH new Account */
char Create_New_Account (Stack*ps)
{
   StackNode*pn=(StackNode*)malloc(sizeof(StackNode));
    
    puts("Enter your name");                                              // assign client name
    scanf("%s",pn->Name);
    puts("Please Enter your Address");                                    // assign address
    scanf("%s",pn->Address);
    puts("Enter Your Age");                                               //assign age
    scanf("%d",&pn->Age);
    if (pn->Age<21)                                                       // gardian on age eligiblity
    {               
        return 1;
    }
    puts("National ID consist of 14 Digits");
    scanf("%d",&pn->NationalID);                                           // assign national ID
    puts("enter amount to be deposited");
    scanf("%f",&pn->Balance);                                              //assign deposite amount
    pn->Password=(1234+i);                                                 //generate password Randomly
    pn->AccountID=(122000+i);                                              //generate account ID Randomly
    pn->Status=ACTIVE;                                                     //set account active
    pn->next=ps->top;
    ps->top=pn;
    (ps->size)++;
    i++;
    
    puts("*****************************************************************************");        // welcoming message and declaring new password and account id
    puts("Welcome and Thanks for choosing our bank");
    printf("Your New Password is:%d\nYour Account ID is:%d\n",pn->Password,pn->AccountID);
    puts("***************************************************************************\n");
    return 0;
}

StackNode* Traverse_List (Stack*ps, int id)
{
    for (StackNode* pn=ps->top; pn ;  pn=pn->next)
    {
        if(pn->AccountID==id)
        return pn;
    }

}

void Display_Exisiting_Account (StackNode* pn)
{
    puts("**********************************************");
    printf("CLIENT:%d INFORMATION\n",pn->AccountID);
    if(pn->Status==ACTIVE)printf("Account Status is Active\n");
    puts(pn->Name);
    puts(pn->Address);
    printf("AGE :%d\n",pn->Age);
    printf("National ID is:%d\n",pn->NationalID);
    printf("Current Balance is:%f\n",pn->Balance);
    puts("**********************************************");                       
}

void Get_Cash (StackNode* pn,float amount)
{
    puts("********//////////////************");
    pn->Balance-=amount;
    printf("Successful Process\nCurrent Balance is=%f\n",pn->Balance);
}

void Deposite (StackNode* pn,float amount)
{
    puts("Enter the amount");
    pn->Balance+=amount;
    printf("Successful Process\nCurrent Balance is=%f",pn->Balance);
}

void Change_Account_Status (StackNode*pn)
{
    printf("choose account status\n(A)ACTIVE\n(R)RESTRICTED\n(C)CLOSED\n");
    int state;
    scanf("%c",&state);
    switch (state)
    {
    case 'A' :
        pn->Status=ACTIVE;
        printf("Account State is ACTIVE");
        break;
    case 'R':
        pn->Status=RESTRICTED;
        printf("Account State is RESTRICTED");
        break;    
    case 'X':
        pn->Status=CLOSED;
        printf("Account State is CLOSED");
        break;
    }
}

void Change_Account_Password(StackNode* pn)
{
    int password=0;
    printf("enter the new password 4 digits\n");
    scanf("%d",&password);
    pn->Password=password;
    password=0;
    printf("enter the new password one more time\n");
    scanf("%d",&password);
    if(pn->Password==password)
    {
        printf("new password confirmed\n");
    }
    else
    {
        printf("try again");
    }
}

void Transaction (Stack*ps,int ID)
{
    int idR=0;
    float amount;
    StackNode* pt;;

    printf("enter the tranaction amount\n");
    scanf("%d",&amount);
    printf("Enter the account id u wanna transfer to\n");
    scanf("%d",&idR);
    pt=Traverse_List(ps,ID);
    pt->Balance-=amount;
    printf("current Balance is =%d\n",pt->Balance);
    pt=Traverse_List(ps,idR);
    pt->Balance+=amount;
    printf("Transaction is done successfully>>\n");
}





