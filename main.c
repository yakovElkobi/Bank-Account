#include <stdio.h>
#include "myBank.h"
#include "myBank.c"


int main(){
	
	char choice;
	double amount,inter;
	int account;
	
	do{
	    printf("\nPlease choose a transaction type: \n");
	    printf("O-open account\n");
	    printf("B-Balance Inquiry\n");
	    printf("D-Deposit\n");
	    printf("W-Withdrawal\n");
	    printf("C-Close Account\n");
	    printf("I-Interest\n");
	    printf("P-Print\n");
	    printf("E-Exit\n");
	    
	    if(scanf("%c",&choice) == 1){
	    
        switch(choice){
			
	  case 'O':
	     printf("Please enter amount for deposit:\n");
	     if(scanf("%lf", &amount) == 1){
		 openAccount(amount);
		}	
		else{
	         printf("Failed to read the amount:\n");
	         }	 
		 break;
						
	  case 'B':
             printf("Please enter account number:\n");
	     if(scanf("%d", &account) == 1){
	        balance(account);
		}		
		else{
		  printf("Failed to read the account number:\n");
		}				
		 break;
						
	  case 'D':
	    printf("Please enter account number\n");
	    if(scanf("%d", &account) != 1){
	       printf("Failed to read the account number:\n");
		break;
	   }
		printf("Please enter amount for deposit:\n");
	        if(scanf("%lf", &amount) == 1){
		     deposit(account,amount);
		}		   
		else{
		  printf("Failed to read the amount:\n");	
		   }  
	       break;
						   
	   case 'W':
	     printf("Please enter account number\n");
	     if(scanf("%d", &account) != 1){
		printf("Failed to read the account number:\n");
	      break;
	    }
	     printf("Please enter the amount to withdraw:\n");
	      if(scanf("%lf", &amount) == 1){
		withdrawal(account,amount);
		}					   
		else{
		printf("Failed to read the amount:\n");
		}					   
	     break;
							   
	   case 'C':
	     printf("Please enter account number:\n");
	     if(scanf("%d", &account) == 1){
		 close(account);
		}					   
		else{
		 printf("Failed to read the account number:\n");
		 }		   
	     break;
							   
           case 'I':
	       printf("Please enter interest rate:\n");
		if(scanf("%lf", &inter) == 1){
		interest(inter);
		}					   
		else{
		  printf("Failed to read the interest rate:\n");
		}					   
	     break;
							   
	   case 'P':
	     printAll();
	     break;
							   
	   case 'E':
	     closeAll();
	     break;
							   
	   default:
	   printf("Invalid transaction type:\n");
	     break;
          }
        }
      }
        while(choice != 'E');			
	
	return 0;
	}
