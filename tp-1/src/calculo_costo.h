/*
 * calculo_costo.h
 *
 *  Created on: 3 abr. 2022
 *      Author: ojose
 */

#ifndef CALCULO_COSTO_H_
#define CALCULO_COSTO_H_
int ingresoDeKilometros(char* pTexto1, float* pNumero);
int ingresoPrecio(char* pTexto1, float* pNumero);
int tarjetaDeDebito(float* pKm, float* pPrecio,float* pResultado);
int tarjetaDeCredito(float* pKm, float* pPrecio,float* pResultado);
int diferenciaDePrecios(float* pPrecio1, float* pPrecio2,float* pResultado);
int precioPorKm(float* pKm, float* pPrecio,float* pResultado);
int precioConBitcoin(float* pPrecio, float* pPrecioBitcoin,float* pResultado);


#endif /* CALCULO_COSTO_H_ */
