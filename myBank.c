#include <stdio.h>
#include "myBank.h"
#define OPEN 1
#define STATUS 0
#define CLOSE 0
#define NUM_ACCOUNT 50
#define FIRST_ACCOUNT 901
#define LAST_ACCOUNT 950
double bank[NUM_ACCOUNT][2] = {{0}};

void openAccount(double amount){

    if(amount > 0){
	for(int i = 0;i<NUM_ACCOUNT;i++){
	   if(bank[i][STATUS] == CLOSE){
	      bank[i][STATUS] = OPEN;
	      bank[i][OPEN] = amount;
	      printf("New account number is: %d\n",i+FIRST_ACCOUNT);
	      return;
	}
    }
		printf("bank is full:\n");
  }
    printf("Failed to read the amount:\n");				
}
void balance(int account){
	if(account > LAST_ACCOUNT || account < FIRST_ACCOUNT){
	   printf("Failed to read the account number:\n");
	   return;
	}
	else if(bank[account-FIRST_ACCOUNT][STATUS] == CLOSE){
	   printf("This account is closed:\n");
	   return;
	}
	printf("The balance of account number %d is: %0.2lf\n",account,bank[account-FIRST_ACCOUNT][OPEN]);
}
void deposit(int account, double amount){
	if(account > LAST_ACCOUNT || account < FIRST_ACCOUNT){
	   printf("Failed to read the account number:\n");
	   return;
	}
	else if(amount < 0){
	printf("Failed to read the amount:\n");
		return;
	}
	else if(bank[account-FIRST_ACCOUNT][STATUS] == CLOSE){
	   printf("This account is closed:\n");
	   return;
	}
	bank[account-FIRST_ACCOUNT][OPEN] += amount;
	printf("The new balance is:  %0.2lf\n",bank[account-FIRST_ACCOUNT][OPEN]);
}
void withdrawal(int account, double withdraw){
	if(account > LAST_ACCOUNT || account < FIRST_ACCOUNT){
	printf("Failed to read the account number:\n");
	return;
	}
	else if(bank[account-FIRST_ACCOUNT][STATUS] == CLOSE){
	printf("This account is closed:\n");
	return;
	}
	else if(bank[account-FIRST_ACCOUNT][OPEN] < withdraw){
	printf("Cannot withdraw more than the balance\n");
	return;
	}
	bank[account-FIRST_ACCOUNT][OPEN] -= withdraw;
	printf("The new balance is:  %0.2lf\n",bank[account-FIRST_ACCOUNT][OPEN]);
}
void close(int account){
	if(account > LAST_ACCOUNT || account < FIRST_ACCOUNT){
	printf("Failed to read the account number:\n");
	return;
	}
	else if(bank[account-FIRST_ACCOUNT][STATUS] == CLOSE){
	printf("This account is closed:\n");
	return;
	}
	bank[account-FIRST_ACCOUNT][STATUS] = CLOSE;
	bank[account-FIRST_ACCOUNT][OPEN] = CLOSE;
}
void interest(double inter){
	if(inter < 0 ){
	printf("Failed to read the interest rate:\n");
	return;
	}
	for(int i = 0;i < NUM_ACCOUNT;i++){
	   if(bank[i][STATUS] == OPEN){
	      bank[i][OPEN] += bank[i][OPEN]*(inter/100.0);
	}
    }
}
void printAll(){
	for(int i = 0;i < NUM_ACCOUNT;i++){
	if(bank[i][STATUS] == OPEN){
	printf("The balance of account number %d is:  %0.2lf\n",i+FIRST_ACCOUNT,bank[i][OPEN]);
    }
  }
}
void closeAll(){
	for(int i = 0;i < NUM_ACCOUNT;i++){
	if(bank[i][STATUS] == OPEN){
	   bank[i][STATUS] = CLOSE;
	   bank[i][OPEN] = CLOSE;
     }
  }
}
