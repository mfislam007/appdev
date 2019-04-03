// thid is main.c
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"	// for user-defined header, use double quotes
#include "sound.h"
int main(){

	FILE *f;
	short sd[RATE];	// for all samples in 1 sec
	
	while(1){
	int ret = system(CMD);
	if (ret == SIGINT) break;
	f = fopen("test.wav", "r");	// open the file for read only
//	int i, arr[80];	//just for making a bar chart
//	for(i=0; i<80; i++)
//		arr[i]= rand()%70 + 30;

	clearScreen();
	setColors(YELLOW, bg(RED));
//	printf("Printed from main.\n");
//	barChart(arr);
	if(f == NULL){
		printf("can not open the wave file\n");
		return 1;
	}
	struct WAVHDR h;	// instance of wav header
	fread(&h, sizeof(h), 1, f);	// read wav header to h
	displayWAVHDR(h);	// show wav  header infformation
	fread(&sd, sizeof(sd), 1, f);
	displayWAVDATA(sd);
	fclose(f); 	// close the opened file 
	}
	resetColors();
}

