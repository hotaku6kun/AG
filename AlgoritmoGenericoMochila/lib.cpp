#include "stdafx.h"
#include "string.h"
#include "lib.h"
#include <iostream>

#pragma warning(disable:4996)

using namespace std;


CSListStrDbl::CSListStrDbl(void)
{
	aHead = NULL;
	aTail = NULL;
} // Constructor

CSListStrDbl::~CSListStrDbl(void)
{
	PNODE	lTemp;

	while (aHead) {
		lTemp = aHead->sNxt;
		delete aHead->sVal;
		delete aHead->sList;
		delete aHead;
		aHead = lTemp;
	}
	aHead = NULL;
	aTail = NULL;
} // Destructor

void CSListStrDbl::mpInsert(char *pVal)
{
	PNODE lTemp;
	if (aHead == NULL)
	{
		aHead = mfInit(pVal,0);
		aTail = aHead;
	}
	else {
		lTemp = mfInit(pVal,0);
		aTail->sNxt = lTemp;
		aTail = lTemp;
	}
} // mpInsert

void CSListStrDbl::mpInsert(char *pVal, int pValue)
{
	PNODE lTemp;
	if (aHead == NULL)
	{
		aHead = mfInit(pVal, pValue);
		aTail = aHead;
	}
	else {
		lTemp = mfInit(pVal, pValue);
		aTail->sNxt = lTemp;
		aTail = lTemp;
	}

} // mpInsert

void CSListStrDbl::mpInsert(char *pCat, char *pName, int pValue)//Se encarga de llenar padres e hijos
{
	PNODE lTemp;
	if (aHead == NULL)
	{
		aHead = mfInit(pCat, 0);
		aTail = aHead;
		aHead->sList->mpInsert(pName, pValue);
	}
	else {
		lTemp = aHead;
		while (lTemp && (strcmp(lTemp->sVal, pCat) != 0))
		{
			lTemp = lTemp->sNxt;
		}
		if (lTemp == NULL)
		{
			lTemp = mfInit(pCat,0);
			aTail->sNxt = lTemp;
			aTail = lTemp;
			aTail->sList->mpInsert(pName, pValue);
		}
		else
		{

			aTail->sList->mpInsert(pName, pValue);
		}
	}
}// mpInsert(todo)

bool CSListStrDbl::mfDeleteAll(char *pMes, char *pPers)
{
	PNODE lTemp;
	bool lBand = false;
	lTemp = mfSearch(pMes);
	if (lTemp == NULL)
	{

		if (aHead != NULL)
		{

			if (strcmp(aHead->sVal, pMes) == 0)
			{
				aHead->sList->mfDelete(pPers);
				lBand = aHead->sList->mfIsEmpty(pMes);
				if (lBand == true)
				{
					mfDelete(pMes);
				}
				return true;
			}
		}
		return false;
	}
	else
	{
		if (lTemp->sNxt == NULL)
			return false;
		else
		{
			if (strcmp(lTemp->sNxt->sVal, pMes) == 0)
			{
				lTemp->sNxt->sList->mfDelete(pPers);
				lBand = lTemp->sNxt->sList->mfIsEmpty(pMes);
				if (lBand == true)
				{
					mfDelete(pMes);
				}
				return true;

			}
		}
	}
	return false;
}

bool CSListStrDbl::mfIsEmpty(char *pMes)
{
	if (aHead == NULL)
	{
		return true;
	}
	return false;
}

bool CSListStrDbl::mfDelete(char *pVal)
{
	PNODE lTemp, lT01;

	lTemp = mfSearch(pVal);
	if (lTemp == NULL)
	{

		if (aHead != NULL)
		{
			if (strcmp(aHead->sVal, pVal) == 0)
			{
				lTemp = aHead;
				if (aHead == aTail)
					aTail = NULL;
				if (aHead && aHead->sNxt)
				{
					aHead->sNxt->sPrev = NULL;
				}
				aHead = aHead->sNxt;
				delete lTemp->sVal;
				delete lTemp;
				return true;
			}
		}
		return false;
	}
	else
	{
		if (lTemp->sNxt == NULL)
			return false;
		else
		{
			if (strcmp(lTemp->sNxt->sVal, pVal) == 0)
			{
				lT01 = lTemp->sNxt;
				lTemp->sNxt = lT01->sNxt;
				if (lT01->sNxt)
					lT01->sNxt->sPrev = lTemp;
				if (lT01 == aTail)
					aTail = lTemp;
				delete lT01->sVal;
				delete lT01;
				return true;

			}
		}
	}
	return false;
}//mfDelete

PNODE CSListStrDbl::mfSearch(char *pVal)
{
	PNODE	lTemp, lT01, lT02;

	if (aHead == NULL) {
		return NULL;
	}
	else {
		//-- buscar a la izq de la lista
		if (strcmp(pVal, aHead->sVal) <= 0) {
			return NULL;
		}
		else
			//-- Buscar a la derecha
			if (strcmp(pVal, aTail->sVal) > 0) {
				return aTail;
			}
			else
				//-- Buscar enmedio
			{
				lT01 = aHead;
				lT02 = lT01;
				while ((lT01 != NULL) &&
					(strcmp(lT01->sVal, pVal) < 0)) {
					lT02 = lT01;
					lT01 = lT01->sNxt;
				}
				if (lT01 == NULL) {
					return aTail;
				}
				else {
					return lT02;
				}
			}
	}
} // mfSearch

void CSListStrDbl::mpShow(bool pBack)
{
	PNODE lTemp;

	lTemp = aHead;
	while (lTemp)
	{
		if (pBack)
		{
			printf("[%s] \n", lTemp->sVal);
			lTemp->sList->mpShow(false);
		}
		else
			printf("%s, %s", lTemp->sVal, lTemp->sValue);
		lTemp = lTemp->sNxt;
	}
	printf("\n");
} // mpShow

int CSListStrDbl::mfSumaVal(char *pInd)
{
	PNODE lTemp;
	int sumaVal;
	lTemp= mfSearch(pInd);
	lTemp = lTemp->sList->aHead;
	for (int i = 0; i < 8; i++)
	{
		sumaVal = lTemp->sValue;
		lTemp= lTemp->sNxt;
	}
	return sumaVal;
}


bool CSListStrDbl::mfBlend(char *pInd1, char *pInd2)
{
	PNODE lTemp1,lTemp2;
	int burbuja;
	char * bubble="";
	lTemp1 = mfSearch(pInd1);
	lTemp2 = mfSearch(pInd2);
	lTemp1 = lTemp1->sList->aHead;
	lTemp2 = lTemp2->sList->aHead;
	for (int i = 0; i < 4; i++)
	{
		burbuja = lTemp1->sValue;
		lTemp1->sValue = lTemp2->sValue;
		lTemp2->sValue = burbuja;

		strcpy(bubble, lTemp1->sVal);
		strcpy(lTemp1->sVal, lTemp2->sVal);
		strcpy(lTemp2->sVal, bubble);

		lTemp1 = lTemp1->sNxt->sNxt;
		lTemp2 = lTemp2->sNxt->sNxt;
		
	}

}

void CSListStrDbl::mpShowII(bool pBack)//muestra desde el mes hasta los nombres de las personas
{
	PNODE	lTemp;
	if (pBack == false)
	{
		lTemp = aHead;
		while (lTemp) {
			cout << "[" << lTemp->sVal << "]" << " ";//imprime el padre entre corchetes
			lTemp->sList->mpShow(pBack);//imprime a los hijos
			lTemp = lTemp->sNxt;
		}
	}
	else
	{
		lTemp = aTail;
		while (lTemp)
		{
			cout << "[" << lTemp->sVal << "]" << " ";//imprime el padre entre corchetes
			lTemp->sList->mpShow(pBack);//imprime a los hijos
			lTemp = lTemp->sPrev;
		}
	}


} // mpShowII

PNODE CSListStrDbl::mfInit(char *pVal, int pValue)
{
	PNODE lNode = new NODE;
	if (lNode) {
		lNode->sVal = new char[strlen(pVal) + 1];
		strcpy(lNode->sVal, pVal);
		lNode->sValue = pValue;
		lNode->sList = new CSListStrDbl();
		lNode->sNxt = NULL;
		lNode->sPrev = NULL;
	}
	return lNode;
} // mfInit