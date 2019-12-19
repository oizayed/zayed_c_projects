/*
 * ePayment.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Omar Zayed
 */

#include "ePayment.h"

/*=========================================
 * CONSTANTS
 =========================================*/

const unsigned char maxiumumTransAmount[8] = "5000.00";
const int amountSize = 7;
char gu8_continueResponse[1];
unsigned char gu8_currentDate[6];
unsigned char gu8_exDate[6];
ST_accountBalance gau8_BankAccounts[10] =
{{{"0100.00"} ,  {"123456789"}} ,
		{{"6000.00"} ,  {"234567891"}} ,
		{{"3250.25"} ,  {"567891234"}} ,
		{{"1500.12"} ,  {"456789123"}} ,
		{{"0500.00"} ,  {"258649173"}} ,
		{{"2100.00"} ,  {"654823719"}} ,
		{{"0000.00"} ,  {"971362485"}} ,
		{{"0001.00"} ,  {"793148625"}} ,
		{{"0010.12"} ,  {"123123456"}} ,
		{{"0000.55"} ,  {"456789321"}}};

ST_transaction gau8_financial_transaction_structures[255];
unsigned char gu8_transactions_counter = 0;
int main(void);






void fillCardData(ST_transaction *transaction)
{
	// filling the cardHolderData in the array of structures

	strncpy((char*)(gau8_financial_transaction_structures[gu8_transactions_counter].cardHolderData.cardHolderName), (char*)(transaction->cardHolderData.cardHolderName), 25);
	strncpy((char*)(gau8_financial_transaction_structures[gu8_transactions_counter].cardHolderData.primaryAccountNumber), (char*)(transaction->cardHolderData.primaryAccountNumber), 19);
	strncpy((char*)(gau8_financial_transaction_structures[gu8_transactions_counter].cardHolderData.cardExpirationDate), (char*)(transaction->cardHolderData.cardExpirationDate), 6);


}



void checkAmount(ST_transaction *transaction)
{
	// checks if the entered amount is less than the maximum amount

	strncpy((char*)(transaction->transData.maxTransAmount), (char*)(maxiumumTransAmount), amountSize);
	strncpy((char*)(gau8_financial_transaction_structures[gu8_transactions_counter].transData.maxTransAmount), (char*)(transaction->transData.maxTransAmount), 8);
	transaction->transResponse.transactionStatus = APPROVED;
	for(int i = 0; i < amountSize; i++)
	{
		if(transaction->transData.transAmount[i] > maxiumumTransAmount[i])
		{
			transaction->transResponse.transactionStatus = DECLINED;
			break;
		}
		else if (transaction->transData.transAmount[i] == maxiumumTransAmount[i])
		{
			continue;
		}
		else
		{
			transaction->transResponse.transactionStatus = APPROVED;
			break;
		}

	}

	if(transaction->transResponse.transactionStatus == DECLINED)
	{
		printf("The Transaction is DECLINED. \n");

		// if amount is large we return to the place where we enter the amount again

		printf("Do you want to continue (y/n)?: \n");
		gets((char*)(gu8_continueResponse));

		if(gu8_continueResponse[0] == 'y')
		{
			printf("Please Enter Terminal Data: \n");
			printf("Please Enter the transaction Amount: \n");
			gets((char*)(transaction->transData.transAmount));

			checkAmount(transaction);

		}
	}
}





void fillTerminalData(ST_transaction *transaction)
{
	// filling the cardHolderData in the array of structures

	strncpy((char*)(gau8_financial_transaction_structures[gu8_transactions_counter].transData.transAmount), (char*)(transaction->transData.transAmount), 8);
	strncpy((char*)(gau8_financial_transaction_structures[gu8_transactions_counter].transData.transactionDate), (char*)(transaction->transData.transactionDate), 11);

}




void checkExpiryDate(ST_transaction *transaction)
{
	//checks if the date is before the expiry date

	gu8_currentDate[0] = transaction->transData.transactionDate[8];
	gu8_currentDate[1] = transaction->transData.transactionDate[9];
	gu8_currentDate[2] = transaction->transData.transactionDate[3];
	gu8_currentDate[3] = transaction->transData.transactionDate[4];

	gu8_exDate[0] = transaction->cardHolderData.cardExpirationDate[3];
	gu8_exDate[1] = transaction->cardHolderData.cardExpirationDate[4];
	gu8_exDate[2] = transaction->cardHolderData.cardExpirationDate[0];
	gu8_exDate[3] = transaction->cardHolderData.cardExpirationDate[1];

	for(int i = 0; i < 4; i++)
	{
		if(gu8_currentDate[i] > gu8_exDate[i])
		{
			transaction->transResponse.transactionStatus = DECLINED;
			break;
		}
		else if (gu8_currentDate[i] == gu8_exDate[i])
		{
			continue;
		}
		else
		{
			transaction->transResponse.transactionStatus = APPROVED;
			break;
		}
	}
	if(transaction->transResponse.transactionStatus == DECLINED)
	{
		printf("The Transaction is DECLINED. \n");

		// if date is after expiry date we return to the place where we enter the date again

		printf("Do you want to continue (y/n)?: \n");
		gets((char*)(gu8_continueResponse));

		if(gu8_continueResponse[0] == 'y')
		{
			printf("Please Enter transaction Date: \n");
			gets((char*)(transaction->transData.transactionDate));

			fillTerminalData(transaction);
			checkExpiryDate(transaction);
		}
	}
}



void saveTransactionIntoServer(ST_transaction *transaction)
{
	// save the data and increament the counter

	if(gu8_transactions_counter < 265)
	{
		gu8_transactions_counter++;
	}

}


void checkBalance(ST_transaction *transaction)
{

	//check the balance

	printf("Verifying Data from the server… \n");
	transaction->transResponse.transactionStatus = DECLINED;
	int i;
	for(i = 0; i < 10; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(transaction->cardHolderData.primaryAccountNumber[j] != gau8_BankAccounts[i].primaryAccountNumber[j])
			{
				break;
			}
			if(j == 8)
			{
				transaction->transResponse.transactionStatus = APPROVED;
			}

		}
		if(transaction->transResponse.transactionStatus == APPROVED)
		{
			break;
		}
	}
	if(transaction->transResponse.transactionStatus == APPROVED)
	{
		for (int k = 0; k < 7; k++)
		{

			if(transaction->transData.transAmount[k] > gau8_BankAccounts[i].balance[k])
			{
				transaction->transResponse.transactionStatus = DECLINED;
				break;
			}
			else if (transaction->transData.transAmount[k] == transaction->transData.maxTransAmount[k])
			{
				continue;
			}
			else
			{
				transaction->transResponse.transactionStatus = APPROVED;
				break;
			}
		}
	}
	gau8_financial_transaction_structures[gu8_transactions_counter - 1].transResponse.transactionStatus = transaction->transResponse.transactionStatus;
	gau8_financial_transaction_structures[gu8_transactions_counter - 1].transResponse.receiptReferenceNumber = gu8_transactions_counter;
	if(transaction->transResponse.transactionStatus == APPROVED)
	{
		printf("The Transaction is APPROVED. \n");
	} else
	{
		printf("The Transaction is DECLINED. \n");
	}

	printf("Do you want to continue (y/n)?: \n");
	gets((char*)(gu8_continueResponse));

	//if yes we return to the begining of the program

	if(gu8_continueResponse[0] == 'y')
	{
		main();
	}


}


