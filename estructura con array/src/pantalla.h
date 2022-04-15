/*
 * pantalla.h
 *
 *  Created on: 7 oct. 2021
 *      Author: ojose
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

typedef struct {
	int type;
    float price;
    int id;
    char name[128];
    char address[128];
    int flagEmpty; // 0 ocupado y 1 vacio

}eDisplay;

int disp_isFree(eDisplay Display[], int len, int* spacefree);
int disp_initList(eDisplay displaysList[], int len );
int disp_loadDisplay(eDisplay Display[]);
int searchIdDisplays(eDisplay displaysList[], int len, int auxId);
int disp_modiDateDisp(eDisplay displaysList[], int len);
int unsubDisplay(eDisplay displaysList[], int len);
int printDisplays(eDisplay displaysList[], int len);
int printOneDisp(eDisplay display[]);
int listarId(eDisplay displaysList[], int len);
#endif /* PANTALLA_H_ */
