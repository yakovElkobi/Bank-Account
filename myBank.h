#pragma once
extern double bank[50][2];

void openAccount(double amount);
void balance(int account);
void deposit(int account, double amount);
void withdrawal(int account, double withdraw);
void close(int account);
void interest(double inter);
void printAll();
void closeAll();
