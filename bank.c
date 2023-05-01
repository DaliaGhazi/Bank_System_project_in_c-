#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "q.h"
//================================================================
void delay()
{
    for (int i = 0; i < 200000000; i++) {
        i++;
        i--;
    }
}
//---------------------------------------------------------------
u8 randomPassword()
{
  u16 i = 0;
  srand((unsigned int)(time(NULL)));
  u8 numbers[] = "0123456789";
  u8 password[8];
  for (i = 0; i < 10; i++) 
  {
    password[i] = numbers[rand() % 10];
	return password[i];

  }
}
//================================================================
void ChangePassword()
{
	u16 i;
	printf("Old Password : %d\n",person[N].Passward);
	u8 new[8];
	printf("Enter New Password :");
	for ( i = 0; i < 10; i++) 
	{
		scanf("%c",&new[i]);
	}
	person[N].Passward[8] = new[8];
	printf("New Password : %d\n",person[N].Passward);

}
//================================================================
void CreateNewAccount(void)
{	system("cls");
   loop:
    if(N==Num)
    {
        printf("The number of bank users has reached the upper limit, and no more accounts can be opened");
        return;
    }
	printf("\n*******************************************\n");
    printf("\t\tWELCOME TO BANK ACCOUNT SYSTEM\t\t\n");
    printf("\n\t\tCreate New Account\t\t\n");
    printf("\n*******************************************\n");
    printf("Enter your Full Name : "); 
	scanf("%s",&(person[N].FullName));
	printf("Enter your Full Address : ");
	scanf("%s",&(person[N].FullAddress));
	printf("Enter your Age : ");
	scanf("%d",&(person[N].Age));
    printf("Enter your National ID : ");
    scanf("%d",&(person[N].National_ID));
	if(person[N].Age > 21)
	{
	    person[N].GuardianNationalID=0;
	}
	else
    {
        printf("Enter Your Guardian National ID : ");
        scanf("%d",&(person[N].GuardianNationalID));    
    }
	printf("Enter the Balance of The Client: ");
    scanf("%f",&(person[N].Balance));
	person[N].AccountStatus=Active;
	printf("\nBank Account is Active\n",person[N].AccountStatus);
	person[N].BankAccountID = 1000+N;
	printf("Bank Account ID of The Client : %d\n",person[N].BankAccountID);
	
	person[N].Passward[8] = randomPassword();
	printf("Bank Account Password : %d\n",person[N].Passward);
	N++;
	delay();
	delay();
	printf("Successful account opening!\n");
  
}
//================================================================

void AdminWindow(void)
{
	while(1)
	{
	system("cls");
	printf("\n*******************************************\n");
    printf("            WELCOME TO ADMIN WINDOW            ");
    printf("\n*******************************************\n");
    printf("+-------------------------------------------+\n");
    printf("+                                           +\n");
    printf("+       [1]  Creat New  Account             +\n");
	printf("+       [2]  Open Existing Account          +\n");
	printf("+       [3]  Exit System.                   +\n");
    printf("+-------------------------------------------+\n");
	printf("\n\n\n\t Enter your choice :\t");
	u16 choice;
    scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		      CreateNewAccount();
			  break;
		case 2:
		      OpenExistingAccount();
			  break;
		case 3: 
		      exit(0);
		      break;
		default:   break;
		
	}
	}
}
//**************---------------------------************************
//================================================================
void UserWindow(void)
{
	while(1)
	{
	system("cls");
	printf("\n*******************************************\n");
    printf("             WELCOME TO USER WINDOW            ");
    printf("\n*******************************************\n");
    printf("+-------------------------------------------+\n");
    printf("+                                           +\n");
    printf("+       [1]  Make Transaction               +\n");
	printf("+       [2]  Change Account Password        +\n");
	printf("+       [3]  Get Cash                       +\n");
	printf("+       [4]  Deposit In Account             +\n");
    printf("+       [5]  Return to Main Menu            +\n");
    printf("+-------------------------------------------+\n");
	printf("\n\n\n\t Enter your choice :\t");
    printf("\n*******************************************\n");
	u16 choice;
    scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		     Make_Transaction(); 		      
			  break;
		case 2:ChangePassword();
			  break;
		case 3:Get_Cash();
         	  break;
		case 4:Deposit_InAccount();
		      break;
		case 5:AdminWindow();
		      break;
		default:   break;
		
	}
		delay();
	delay();
	}

}
//================================================================
void welcomeMenu(void)
{
	system("cls");
    int i;
    while(1)
    {
	printf("\n*******************************************\n");
    printf("       WELCOME TO BANK Management SYSTEM       ");
    printf("\n*******************************************\n");
    printf("+-------------------------------------------+\n");
    printf("+                                           +\n");
    printf("+       [1]  Admin Window                   +\n");
	printf("+       [2]  Client Window                  +\n");
    printf("+-------------------------------------------+\n");
    printf("please Enter your Choice : ");
    fflush(stdin);
    scanf("%d",&i);
    if(i>=1 &&i<=3)
	{
	   switch(i)
	   {
		case 1:
		    AdminWindow();
			break;
		case 2:
		    UserWindow();
			break;
		default:   break;
	   }
	}
    else
	{
		printf("Incorrect input, please try again\n\n");
	} 		
    }
}

//*********************************************************************//
void OpenExistingAccount()
{
	system("cls");
    u16 id, account;
    printf("\nEnter The Client Bank Account ID :");
    scanf("%d", &id);
    account = search(id);  
   if(account<0)   
    {
        printf(" User Not Found!\n");
    }
    else
    {	
	printf("Full Name :%s\n", person[account].FullName);
    printf("Full Address :%s\n", person[account].FullAddress);
    printf("Balance Of The Client :%f \n",person[account].Balance);
    printf("Age: %d\n",person[account].Age);
    printf("National ID : %d\n",person[account].National_ID);
    printf("Guardian National ID : %d\n",person[account].GuardianNationalID);
    printf("The Bank Account ID Of The Client  : %d\n",person[account].BankAccountID);
	printf("\nBank Account is Active\n",person[account].AccountStatus);
  
	printf("\n*******************************************\n");
    printf("          Open   Existing   Account            ");
    printf("\n*******************************************\n");
    printf("|-------------------------------------------|\n");
    printf("|       [1]  Make Transaction               |\n");
	printf("|       [2]  Change Account Status          |\n");
    printf("|       [3]  Get Cash                       |\n");
	printf("|       [4]  Deposit In Account             |\n");
	printf("|       [5]  Return to Main Menu            |\n");
    printf("|-------------------------------------------|\n");	
	u16 ch;
    scanf("%d", &ch);
	switch(ch)
	{
		case 1: Make_Transaction();    		
		        break;
		case 2: Change_AccountStatus(); 
         		break;
		case 3: Get_Cash();             
        		break;
		case 4: Deposit_InAccount();     
		        break;
		case 5: AdminWindow();         
		        break;
		default :  break;		
	}
	}
}

//*********************************************************************//
s16 search(u16 id)
{
    u16 index = -1;
    u16 low=0, high=N-1, mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(person[mid].BankAccountID==id)
        {
            index=mid;
            break;   
        }
        else if (person[mid].BankAccountID>id)
            high=mid-1;
        else
            low=mid+1;
    }
    return index; 
}
//*********************************************************************//
void Make_Transaction()
{
	u16 x ,j,money ,y,z;
	printf("\nEnter The Client Bank Account ID you Want to Transfer Money to.:");
    scanf("%d",&x);
	y = search(x);
	if(y<0)
	{
		printf("\nUser  Not Found.");
	}
	else
	{
		if((person[N].AccountStatus == Active)&& (person[y].AccountStatus == Active))
		{
			printf("\nEnter The Amount of Money to Transfer it  to The This Account. :");
            scanf("%d",&money);
			if(person[N].Balance < money)
			{
				printf("\nFaild Transaction Operation..");
			}
			else
			{
				person[N].Balance -= money;
		        person[y].Balance += money;
		        printf("After Transaction, there are still %f $.\n",person[N].Balance);
		        printf("After Transaction, other person have: %f $.\n",person[y].Balance);
				delay();
			}
	    }
		else
		{
			printf("\nAccount Status Not Active.");
		}
	
	}
	delay();
	delay();
	
}
//*********************************************************************//
void Get_Cash()
{
	f32 Amount;
    u16	r;
	printf("\nEnter The Cash Amount you Want  :");
    scanf("%d",&Amount);
	if(Amount < person[r].Balance)
	{
		person[r].Balance -= Amount;
		printf("After withdrawal, there are still %.2f $.\n",person[r].Balance);
	} 
	else
	{
		printf("\nSorry , The withdrawal process failed");
	}
	delay();
	delay();
	
}
//*********************************************************************//
void Deposit_InAccount()
{
	f32 Amount;
	u16 u;
	printf("\nEnter The Cash Amount you Want to Add to This Account :");
    scanf("%d",&Amount);
	person[u].Balance += Amount;
	printf("After depositing, you have %.2f $.\n",person[u].Balance );	
	delay();
	delay();
}
//*********************************************************************//
void Change_AccountStatus()
{
	u16 option,i;
	printf("|-------------------------------------------|\n");
    printf("|         Change Account Status             |\n");
    printf("|       [1]  Active                         |\n");
	printf("|       [2]  Restricted                     |\n");
	printf("|       [3]  Closed                         |\n");
    printf("|-------------------------------------------|\n");
	printf("\nEnter The Bank Account Status, you Want for This Account :");
    scanf("%d",&option);
	switch(option)
	{
		case 1: person[i].AccountStatus = Active;
   		        printf("\nBank Account is Active",person[i].AccountStatus);
                break;
		case 2: person[i].AccountStatus = Restricted; 
		       	printf("\nBank Account is Restricted",person[i].AccountStatus);
				break;
		case 3: person[i].AccountStatus = Closed; 
                printf("\nBank Account is Closed",person[i].AccountStatus);
				break;
		default      :                               break;
	}
	delay();
	delay();
}

//*********************************************************************//
void readData()
{
    FILE *fp;  
    int i = 0;
    if ((fp=fopen("Record.txt", "a+"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    while(fscanf(fp,"%s %s %d %d %d %f %d",&person[i].FullName,&person[i].FullAddress,&person[i].Age,&person[i].National_ID,&person[i].GuardianNationalID,&person[i].Balance,&person[i].BankAccountID) != EOF)
    {
        i++;
    }
    N = i; 
    fclose(fp);
    return;
}
//*********************************************************************//
void writeData()
{
    FILE *fp;  
    int i=0;
    if ((fp=fopen("Record.txt", "w"))==NULL)
    {
        printf("data file cannot open!");
        exit(0);
    }
    for(i=0; i<N; i++)
        fprintf(fp,"%s %s %d %d %d %f %d",person[i].FullName,person[i].FullAddress,person[i].Age,person[i].National_ID,person[i].GuardianNationalID,person[i].Balance,person[i].BankAccountID);
    fclose(fp);
}
//*********************************************************************//
void main(void)
{
	readData();
	welcomeMenu();
   writeData();
}


