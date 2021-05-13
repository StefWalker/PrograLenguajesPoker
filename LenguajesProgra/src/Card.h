/*
 ============================================================================
 Name        : LenguajesPrograC.c
 Author      : Dylan, Sebastian, Jose, Heyler
 Version     : 1.0
 Description : Probability counter in poker hands
 ============================================================================
 */

#ifndef CARD_H_
#define CARD_H_

typedef enum { F, T } boolean; // Added for the use of booleans

/* Funcion: Struct for the cards
 * Inputs: None
 * Outputs: None
 * */
struct Card{
	int value;
	int type;
	boolean picked;
} card;

/* Funcion: Struct for the data review
 * Inputs: None
 * Outputs: None
 * */
struct Data{
	float DpValue;
	float FhValue;
	float PValue;
	float RFValue;
} data;
#endif /* CARD_H_ */
