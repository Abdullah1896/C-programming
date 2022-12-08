#include<stdio.h>
#include"app.h"


int main()
{
     Stack s;
     StackNode* ptr;
     float amount;
     int ID,i,guardian=0;
     char flag,n = 0 ;
    while(flag==0)
    {
		printf("Admin mode Enter 0\n");
		printf("user mode Enter 1 \n");
		scanf("%d",&i);
		switch(i)
        {
			
			case 0 :
            /***********************************ADMIN MODE*********************************/                                  
			printf("Admin mode\n");
			printf("1-Create new account\n");
			printf("2-open existing account\n");
			printf("3- EXIT\n");fflush(stdout);
			scanf("%d", &n);
			switch(n)
            {
				case 1 :
				Create_Stack(&s);
				guardian=Create_New_Account(&s);
                if(guardian==1)puts("age is less than 21 can not create account");
				break;
				case 2 :
                printf("Enter account ID\n");
                scanf("%d",&ID);
                ptr=Traverse_List(&s,ID);
                printf("please choose the action from the list :\n");
                printf("(1)Change Account Staus\n(2)Get Cash\n(3)Make A Deposite\n(4)Make A Transaction\n(5)Display ACCOUNT iNFO\n(6)Return to Main Menu\n");
                scanf("%d", &n);
                switch(n)
                {
                    case 1:
                    Change_Account_Status(ptr);
                    break;
                    case 2:
                    printf("Enter the amount in EGYP\n");
                    scanf("%f", &amount);
                    Get_Cash(ptr,amount);
                    break;
                    case 3:
                    printf("Enter the amount in EGYP\n");
                    scanf("%f", &amount);
                    Deposite(ptr,amount);
                    break;
                    case 4:
                    Transaction(&s,ID);
                    break;
                    case 5 :
                    Display_Exisiting_Account(ptr);
                    case 6 :
                    break;
                }
                case 3 :
                break;
            }
            break;
            /******************END OF ADMIN MODE******************************/

            /*****************CLIENT MODE***********************************/
            case 1:
            printf("Client Mode\n");
            puts("************************************************************************************************");
                printf("Enter account ID\n");
                scanf("%d",&ID);
                ptr=Traverse_List(&s,ID);
                printf("please choose the action from the list :\n");
                printf("(1)Change Account Password\n(2)Get Cash\n(3)Make A Deposite\n(4)Make A Transaction\n(5)Display ACCOUNT iNFO\n(6)Return to Main Menu\n");
                scanf("%d", &n);
                switch(n)
                {
                    case 1:
                    Change_Account_Password(ptr);
                    break;
                    case 2:
                    printf("Enter the amount in EGYP\n");
                    scanf("%f", &amount);
                    Get_Cash(ptr,amount);
                    break;
                    case 3:
                    printf("Enter the amount in EGYP\n");
                    scanf("%f", &amount);
                    Deposite(ptr,amount);
                    break;
                    case 4:
                    Transaction(&s,ID);
                    break;
                    case 5 :
                    Display_Exisiting_Account(ptr);
                    case 6 :
                    break;
                }
                /*****************CLIENT MODE***********************************/
                break;

        }
    }

                
    
    return 0;
}