/*
 * ePaymentMain.c
 *
 *  Created on: Dec 3, 2019
 *      Author: Omar Zayed
 */

#include "ePayment.h"

int ePaymentmain(void)
{


	/*==================SCANF==================*/

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	ST_transaction CIBtransaction;
	ST_transaction *ptrTransaction = &CIBtransaction;

	printf("Please Enter Card Data: \n");
	printf("Please Enter the Card Holder Name: \n");
	gets((char*)(CIBtransaction.cardHolderData.cardHolderName));
	printf("Please Enter the Primary Account Number: \n");
	gets((char*)(CIBtransaction.cardHolderData.primaryAccountNumber));
	printf("Please card Expiry Date: \n");
	gets((char*)(CIBtransaction.cardHolderData.cardExpirationDate));

	fillCardData(ptrTransaction);

	printf("Please Enter Terminal Data: \n");
	printf("Please Enter the transaction Amount: \n");
	gets((char*)(CIBtransaction.transData.transAmount));

	checkAmount(ptrTransaction);

	printf("Please Enter transaction Date: \n");
	gets((char*)(CIBtransaction.transData.transactionDate));

	fillTerminalData(ptrTransaction);

	checkExpiryDate(ptrTransaction);

	saveTransactionIntoServer(ptrTransaction);

	checkBalance(ptrTransaction);

	return 0;


}




