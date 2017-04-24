// CSListStrDbl.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "string.h"
#include <time.h>
#include "lib.h"
#include <iostream>
#define POBL 200;
#pragma warning(disable:4996)

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	bool repeat = false;
	char * number;
	int randNumber, value;
	char * obj = "";
	CSListStrDbl lCortina, lHijosCortina;
	PNODE	lTemp1,lTemp2,lRand,lSolution;

	for(int p=0; p <= 200 ; p++)
	{
		for (int i=0;i<8;i++)
		{
			sprintf(number, "%d", p);
			randNumber = rand() % 8 + 1;
			switch (randNumber)
			{
			case 1:
				value = 10;
				strcpy(obj,"Botiquin");
				break;
			case 2:
				value = 8;
				strcpy(obj, "cobija");
				break;
			case 3:
				value = 16;
				strcpy(obj, "radio");
				break;
			case 4:
				value = 1;
				strcpy(obj, "chocolate");
				break;
			case 5:
				value = 4;
				strcpy(obj, "Botella de agua");
				break;
			case 6:
				value = 2;
				strcpy(obj, "linterna");
				break;
			case 7:
				value = 7;
				strcpy(obj, "lata de atun");
				break;
			case 8:
				value = 5;
				strcpy(obj, "brujula");
				break;
			default:
					break;
			}
			lCortina.mpInsert(number, obj,value);
		}
	}

	do {
		for (int i = 0;i<200; i=i+2)
		{
			if (lTemp1==NULL||lTemp2==NULL)
			{
				sprintf(number, "%d", i);
				value = lCortina.mfSumaVal(number);
				if (value==25)
				{
					lSolution=lCortina.mfGiveNode(number);
				}
				if (20<=value||value<=30)
				{
					randNumber = rand() % 100 + 1;
					if (randNumber <= 5)
					{
						lRand = lCortina.mfGiveNode(number);
						randNumber = rand() % 8 + 1;
						switch (randNumber)
						{
						case 1:
							value = 10;
							strcpy(obj, "Botiquin");
							break;
						case 2:
							value = 8;
							strcpy(obj, "cobija");
							break;
						case 3:
							value = 16;
							strcpy(obj, "radio");
							break;
						case 4:
							value = 1;
							strcpy(obj, "chocolate");
							break;
						case 5:
							value = 4;
							strcpy(obj, "Botella de agua");
							break;
						case 6:
							value = 2;
							strcpy(obj, "linterna");
							break;
						case 7:
							value = 7;
							strcpy(obj, "lata de atun");
							break;
						case 8:
							value = 5;
							strcpy(obj, "brujula");
							break;
						default:
							break;
						}
							strcpy(lRand->sVal,obj);
							lRand->sValue = value;
					}
					if (lTemp1==NULL)
					{
						lTemp1 = lCortina.mfGiveNode(number);
						lHijosCortina.mpInsert(lTemp1);
					}
					else
					{
						lTemp2 = lCortina.mfGiveNode(number);
						lHijosCortina.mpInsert(lTemp2);
					}
				}
			}
			else
			{
				lHijosCortina.mfBlend(lTemp1->sVal,lTemp2->sVal);

				lTemp1 = NULL;
				lTemp2 = NULL;
			}
			if (lTemp1 != NULL&&i >= 199)
			{
				lHijosCortina.mpInsert(lTemp1);
				lTemp1 = NULL;
			}
		}
		if (lSolution != NULL)
		{
			repeat = true;
		}
		else
		{
			lCortina = lHijosCortina;
			lHijosCortina.mfDeleteAll();
		}
	} while (repeat == false);



	return 0;

}