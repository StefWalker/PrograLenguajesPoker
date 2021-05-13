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
#include <time.h>

// Main variables created for the probabilities data
static int m = 100, n = 1000000;			// Parameters for the code

struct Card cards[52];
struct Data DataArray[100];

float DosParejas = 0;
float Poker = 0;
float Full = 0;
float EscaleraReal = 0;

float CicleDP = 0;
float CicleP = 0;
float CicleFH = 0;
float CicleER = 0;

/* Funcion: Filler de deck of cards
 * Inputs: None
 * Outputs: None
 * */
void DeckFiller(){
	int card = 1; // Card number
	int type = 1; // Card group
	for(int i = 0; i < 52; i++){ // For in charge of filling the data for each card
		cards[i].value = card ;
		cards[i].type = type ;
		cards[i].picked = F;	 // Value used to know if it was picked or not
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
	size_t n = sizeof(cards)/sizeof(cards[0]); // Size of the deck
    if (n > 1)								   // Main structure
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);	// Selects random card
          int t = cards[j].value;
          int k = cards[j].type;
          cards[j].value = cards[i].value;					// In witch the data is swaped with another one
          cards[j].type = cards[i].type;
          cards[i].value = t;
          cards[i].type = k;
        }
    }
}

/* Funcion: Used only to check the data of the cards
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

/* Funcion: Important function of the system this one will check the cards data to verify the hand and what type it is
 * Inputs: Cards array
 * Outputs: None
 * */
void HandCheck(struct Card hand[5]){
	int data = 0; //Used as a boolean
	int count1 = 0, count2 = 0, counter = 0;										   // Counters used to keep track of the data
	if (hand[0].type == hand[1].type == hand[2].type == hand[3].type == hand[4].type ) // Verification process for the search of a Royal Flush
	{
		if ((hand[0].value == 13) && (hand[1].value ==12) && (hand[2].value ==11) && (hand[3].value == 10) && (hand[4].value == 1))
		{
			EscaleraReal++;
			CicleER++;
		}
	}
	if(hand[0].value != hand[1].value){							// Validation in the entry of data
		counter++;
	}
	if (hand[counter].value == hand[counter+1].value){			// If with a while for the search of a trio or poker in hand
		count1++;
		counter++;
		while(data == 0){
			if(hand[counter].value == hand[counter+1].value){
				count1++;
				counter++;
			}
			else{
				data = 1;
				counter++;
			}
		}
	}
	if(1 <= count1 && count1 < 3){							   // Used only for a search of a second duo or a trio
		if(hand[counter].value == hand[counter+1].value){
			count2++;
			counter++;
		}else{
			counter++;
		}

		if(hand[counter].value == hand[counter+1].value){
			count2++;
			counter++;
		}
	}
									// Conditions directed for the adiction in the counter for hands searched
	if (count1== 1 && count2 == 1)
	{
		DosParejas++;
		CicleDP++;
	}
	if ((count1 == 2 && count2 == 1) || (count1 == 1 && count2 == 2))
	{
		Full++;
		CicleFH++;
	}
	if (count1 == 3)
	{
		Poker++;
		CicleP++;
	}
}

/* Funcion: Function with the objective of sorting the cards throgh bubble sort
 * Inputs: Cards array
 * Outputs: None
 * */
void SortCards(struct Card hand[5]){
	for(int i = 0; i < 5; i++){					// Main structure for a bubble sort
	   for(int j = 0; j < 5; j++){
	        if(hand[i].value > hand[j].value){	// Consisting in sorting the value and type of the card
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

	HandCheck(hand);
}

/* Funcion: Reset for the boolean state in the cards
 * Inputs: None
 * Outputs: None
 * */
void ResetCards(){
	for (int i = 0; i < 52; i++)
	{
		cards[i].picked = F;
	}
}

/* Funcion: In charge of generating a new random card from the shuffled deck
 * Inputs: None
 * Outputs: None
 * */
void HandGenerator(){
	struct Card hand[5];					// Array of cards for the new hand to generate
	int gen = 0;
	for(int i = 0; i < 5; i++){
		gen = rand() % 52;					// Random card in the deck
		hand[i].value = cards[gen].value;	// Copy of the data of the card
		hand[i].type = cards[gen].type;

		if(cards[gen].picked == T){			// If to check if the card was or not alredy picked
			i--;
		}else{
			cards[gen].picked = T;
		}
	}
	ResetCards();
	SortCards(hand);
}

/* Funcion:
 * Inputs:
 * Outputs:
 * */
float varianza(float media_aritmetica, int type) {
	float media = media_aritmetica;
	float var = 0;
	if(type == 0){
		for (int i = 0; i < m; i++) {
			var += pow(DataArray[i].DpValue - media, 2);
		}
	}
	if(type == 1){
		for (int i = 0; i < m; i++) {
			var += pow(DataArray[i].FhValue - media, 2);
		}
	}
	if(type == 2){
		for (int i = 0; i < m; i++) {
			var += pow(DataArray[i].PValue - media, 2);
		}
	}
	else{
		for (int i = 0; i < m; i++) {
			var += pow(DataArray[i].RFValue - media, 2);
		}
	}
	var /= m;
	return var;
}

/* Funcion: Main function of the system in charge of showing all the data about the probabilities of the Poker hands
 * Inputs: None
 * Outputs: None
 * */
int main(void) {

    srand(time(NULL));				// Seed to generate the best random escenario

    DeckFiller();					// Start of the filling process


    int cycles = 0;
    int hands = 0;
    float testvariable = 0;
    float tryes = m;

    while (cycles<m)			// Main cycle of the code
    {
    	CicleDP = 0;
    	CicleP = 0;
    	CicleFH = 0;
    	CicleER = 0;
        Shuffle();				// Deck Shuffle
        while (hands<n)
        {
            HandGenerator();	// Generate new hand
            hands++;
        }
        ResetCards();			// Resest picked state of the cards
        cycles++;
        hands = 0;

        DataArray[cycles].DpValue = CicleDP;
		DataArray[cycles].FhValue = CicleP;
		DataArray[cycles].PValue = CicleFH;
		DataArray[cycles].RFValue = CicleER;
    }

    testvariable = DosParejas/tryes;
    printf("Media Generada para Doble Pareja: ");
    printf("%.6f", testvariable);
    printf("  Probabilidad teorica para este caso: ");
    printf("%.6f", n/20.0 );
    printf("\n");
    printf("Varianza: ");
    printf("%.6f", varianza(testvariable, 0));
    printf("\n");
    printf("\n");

    testvariable = Full/tryes;
    printf("Media Generada para Full House: ");
    printf("%.6f", testvariable);
    printf("  Probabilidad teorica para este caso: ");
    printf("%.6f", n/693.17 );
    printf("\n");
    printf("Varianza: ");
    printf("%.6f", varianza(testvariable, 1));
    printf("\n");
    printf("\n");

    testvariable = Poker/tryes;
    printf("Media Generada para Poker: ");
    printf("%.6f", testvariable);
    printf("  Probabilidad teorica para este caso: ");
    printf("%.6f", n/4165.0 );
    printf("\n");
    printf("Varianza: ");
    printf("%.6f", varianza(testvariable, 2));
    printf("\n");
    printf("\n");

    testvariable = EscaleraReal/tryes;
    printf("Media Generada para Escalera Real: ");
    printf("%.6f", testvariable);
    printf("  Probabilidad teorica para este caso: ");
    printf("%.6f", n/649739.0 );
    printf("\n");
    printf("Varianza: ");
    printf("%.6f", varianza(testvariable, 3));
    printf("\n");
    printf("\n");

    printf("Dos Parejas: ");
    printf("%.0f", DosParejas);
    printf("\n");
    printf("Fulls: ");
    printf("%.0f", Full);
    printf("\n");
    printf("Pokers: ");
    printf("%.0f", Poker);
    printf("\n");
    printf("Escaleras Reales: ");
    printf("%.0f", EscaleraReal);

    return EXIT_SUCCESS;
}
