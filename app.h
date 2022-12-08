/************STRUCT DECLARATION********************/
typedef struct stacknode
{
    char Status;
    char Name [30];
    char Address [50];
    int Age;
    int Password;
    int NationalID;
    int AccountID;
    float Balance;
    struct Stacknode* next;

}StackNode;

typedef struct
{
    StackNode* top;
    int size;                 
}Stack;

/*******************FUNCTION PROTOTYPE***************/
char Create_New_Account (Stack*ps);
StackNode* Traverse_List (Stack*ps, int id);
void Display_Exisiting_Account (StackNode* pn);
void Get_Cash (StackNode* pn,float amount);
void Deposite (StackNode* pn,float amount);
void Change_Account_Status (StackNode*pn);
void Transaction (Stack*ps,int);
void Change_Account_Password(StackNode* pn);