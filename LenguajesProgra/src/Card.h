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

typedef enum { F, T } boolean;

/* Funcion:
 * Inputs:
 * Outputs:
 * */
struct Card{
	int value;
	int type;
	boolean picked;
} card;


#endif /* CARD_H_ */
