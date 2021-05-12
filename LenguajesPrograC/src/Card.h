/*
 * Card.h
 *
 *  Created on: 2 may. 2021
 *      Author: dylan
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
