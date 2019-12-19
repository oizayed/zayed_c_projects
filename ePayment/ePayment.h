/*
 * ePayment.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Omar Zayed
 */

#ifndef EPAYMENT_H_
#define EPAYMENT_H_

/*=========================================
 * INCLUDES
 =========================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*=========================================
 * CONSTANTS
 =========================================*/


/*=========================================
 * ENUMS
 =========================================*/

typedef enum EN_transStat
{
	DECLINED,
	APPROVED
}EN_transStat;


/*=========================================
 * STRUCTS AND UNIOINS
 =========================================*/


typedef struct ST_cardData
{
	unsigned char cardHolderName[25];
	unsigned char primaryAccountNumber[19];
	unsigned char cardExpirationDate[6];
}ST_cardData;

typedef struct ST_terminalData
{
	unsigned char transAmount[8];
	unsigned char maxTransAmount[8];
	unsigned char transactionDate[11];
}ST_terminalData;

typedef struct ST_serverData
{
	EN_transStat transactionStatus;
	unsigned int receiptReferenceNumber;
}ST_serverData;

typedef struct ST_transaction
{
	ST_cardData cardHolderData;
	ST_terminalData transData;
	ST_serverData transResponse;
}ST_transaction;

typedef struct ST_accountBalance
{
	unsigned char balance[8];
	unsigned char primaryAccountNumber[19];
}ST_accountBalance;



/*=========================================
 * FUNCTIONS PROTOTYPES
 =========================================*/

void fillCardData(ST_transaction *transaction); 	// filling the cardHolderData in the array of structures
void checkAmount(ST_transaction *transaction); 	// checks if the entered amount is less than the maximum amount
void fillTerminalData(ST_transaction *transaction); 	// filling the cardHolderData in the array of structures
void checkExpiryDate(ST_transaction *transaction); 	//checks if the date is before the expiry date
void saveTransactionIntoServer(ST_transaction *transaction); 	// save the data and increament the counter
void checkBalance(ST_transaction *transaction); 	//check the balance






#endif /* EPAYMENT_H_ */
