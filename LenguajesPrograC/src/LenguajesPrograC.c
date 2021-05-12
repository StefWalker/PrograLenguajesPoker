/*
 ============================================================================
 Name        : LenguajesPrograC.c
 Author      : Dylan, Sebastian, Jose, Heyler
 Version     : 1.0
 Description : Probability counter in poker hands
 ============================================================================
 */

#include "Card.h"
#include <stdio.h>
#include <stdlib.h>

struct Card cards[52];

/* Funcion: Filler de deck of cards
 * Inputs: None
 * Outputs: None
 * */
void DeckFiller(){
	int card = 1; // Card number
	int type = 1; // Card group
	for(int i = 0; i < 52; i++){
		cards[i].value = card ;
		cards[i].type = type ;
		cards[i].picked = F;
		card++;
		if(card == 14){
			card = 1;
			type ++;
		}
	}
}

/* Funcion: Shuffle of the cards, making them all end in random locations
 * Inputs: None
 * Outputs: None
 * */
void Shuffle(){
	size_t n = sizeof(cards)/sizeof(cards[0]);
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = cards[j].value;
          int k = cards[j].type;
          cards[j].value = cards[i].value;
          cards[j].type = cards[i].type;
          cards[i].value = t;
          cards[i].type = k;
        }
    }
}

/* Funcion:
 * Inputs: None
 * Outputs: None
 * */
void PrintTest(){
	for(int i = 0; i < 52; i++){
		printf("\n Card number: ");
		printf("%d", cards[i].value);
		printf(" type: ");
		printf("%d", cards[i].type);
	}
}

/* Funcion:
 * Inputs:
 * Outputs:
 * */
void HandCheck(struct Card hand[5]){ // Second number can't count to 3 or 4 in second value
	int data = 0; //Used as a boolean
	int count1 = 0, count2 = 0, counter = 0;
	if (hand[0].type == hand[1].type == hand[2].type == hand[3].type == hand[4].type )
	{
		if ((hand[0].value == 13) && (hand[1].value ==12) && (hand[2].value ==11) && (hand[3].value == 10) && (hand[4].value == 1))
		{
			//EscaleraReal++;
		}
	}
	else{
		while(data == 0){
			if(hand[counter].value == hand[counter+1].value){
				count1++;
				counter++;
			}
			if(count1 == 0 && counter == 0){
				counter++;
			}
			else{
				counter++;
				data = 1;
			}
		}
		if(count1 != 3){
			data = 0;
			while(data == 0){
				if(hand[counter].value == hand[counter+1].value){
					count2++;
					counter++;
				}
				if(counter >= 3){
					data = 1;
				}
				counter++;
			}
		}
	}/*
	if (count1== 1 && count2 == 1)
	{
		DosParejas++;

	}
	if (count1== 2 && count2 == 1)
	{
		Full++;

	}
	if (count1== 3)
	{
		Poker++;

	}*/
	printf("%d", count1);
	printf("  ");
	printf("%d", count2);
	printf("\n");
}

/* Funcion:
 * Inputs:
 * Outputs:
 * */
/*void SortCardss(){
	for(int i = 0; i < 5; i++){
	   for(int j = 0; j < 5; j++){
	        if(cards[i].value > cards[j].value){
	              // swap
	              int tmp = cards[j].value;
	              cards[j].value = cards[i].value;
	              cards[i].value = tmp;
	         }
	     }
	 }
}
*/

/* Funcion:
 * Inputs:
 * Outputs:
 * */
void SortCards(struct Card hand[5]){
	for(int i = 0; i < 5; i++){
	   for(int j = 0; j < 5; j++){
	        if(hand[i].value > hand[j].value){
	              // swap
	              int tmpV = hand[j].value;
				  int tmpT = hand[j].type;
	              hand[j].value = hand[i].value;
	              hand[i].value = tmpV;
				  hand[j].type = hand[i].type;
	              hand[i].type = tmpT;
	         }
	     }
	 }



	for(int i = 0; i < 5; i++){
		printf("%d", hand[i].value);
		printf("  ");
	}
	printf("\n");
	for(int i = 0; i < 5; i++){
		printf("%d", hand[i].type);
		printf("  ");
	}
	printf("\n");

	HandCheck(hand);
}

/*
void SortCards(struct Card hand[5]){
	for(int i = 0; i < 5; i++){
	   for(int j = 0; j < 5; j++){
	        if(hand[i].value > hand[j].value){
	              // swap
	              int tmp = hand[j].value;
	              hand[j].value = hand[i].value;
	              hand[i].value = tmp;
	         }
	     }
	 }

	for(int i = 0; i < 5; i++){
		printf("%d", hand[i].value);
		printf("  ");
	}
	printf("\n");

	HandCheck(hand);
}*/

/* Funcion:
 * Inputs:
 * Outputs:
 * */
void HandGenerator(){
	struct Card hand[5];
	int gen = 0;
	for(int i = 0; i < 5; i++){
		gen = rand() % 52;
		printf("%d", gen);
		printf("  ");
		hand[i].value = cards[gen].value;
		hand[i].type = cards[gen].type;

		if(cards[gen].picked == T){
			i--;
		}else{
			cards[gen].picked = T;
		}
	}
	printf("\n");
	for(int i = 0; i < 5; i++){
		printf("%d", hand[i].value);
		printf("  ");
	}
	printf("\n");


	SortCards(hand);
}

/* Funcion:
 * Inputs:
 * Outputs:
 * */
int main(void) {

	srand(time(NULL));
	/*int m, n;

	printf("Enter value for M (Cycles): ");
	scanf("%d", &m);
	printf("\nEnter value for N (hands per cycle): ");
	scanf("%d", &n);

	for(int i = 0; i < 52; i++){

	}*/

	DeckFiller();
	Shuffle();
	HandGenerator();

	return EXIT_SUCCESS;
}



