
#ifndef Q_h_
#define Q_h_
typedef unsigned char                u8 ;
typedef unsigned short int           u16;
typedef unsigned long int            u32;
typedef unsigned long long int       u64;
typedef signed char                  s8 ;
typedef signed short int             s16;
typedef signed long int              s32;
typedef float                        f32;
typedef double                       f64;

#define Num             500 
#define Active          0U
#define Restricted      1U
#define Closed          2U

typedef struct{
 	u8  FullName[50];
	u8  FullAddress[50];
	u16 National_ID;      
	u16 Age;
	u16 BankAccountID;  
	u16 GuardianNationalID;
	u8  AccountStatus;
	f32 Balance;
	u8  Passward[8]; 
}Client_t;
Client_t person[Num];
u16 N;

void delay();
void welcomeMenu(void);
void AdminWindow(void);
void UserWindow(void);
void CreateNewAccount(void);
s16 search(u16 id);
void OpenExistingAccount(void);
void Make_Transaction(void);
void Get_Cash(void);
void Deposit_InAccount(void);
void Change_AccountStatus(void);
void readData(void);
void writeData(void);
u8 randomPassword(void);
void ChangePassword(void);

#endif