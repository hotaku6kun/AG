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

	for(int p=0; p <= 200 ; p++)
	{
		for (int i=0;i++;)
		{
			sprintf(number, "%d", p);
			randNumber = rand() % 8 + 1;
			switch (randNumber)
			{
			case 1:
				value = 0;
				strcpy(obj,"");
				break;
			case 2:
				value = 0;
				strcpy(obj, "");
				break;
			case 3:
				value = 0;
				strcpy(obj, "");
				break;
			case 4:
				value = 0;
				strcpy(obj, "");
				break;
			case 5:
				value = 0;
				strcpy(obj, "");
				break;
			case 6:
				value = 0;
				strcpy(obj, "");
				break;
			case 7:
				value = 0;
				strcpy(obj, "");
				break;
			case 8:
				value = 0;
				strcpy(obj, "");
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
			randNumber = rand() % 100 + 1;
			if (randNumber<=5)
			{

			}
			else
			{
			
			}
		}
	} while (repeat == false);

	lCortina.mpShowII();
	lCortina.mfDeleteAll("10", "Roberto");
	lCortina.mpShowII();
	lCortina.mfDeleteAll("10", "Coy");
	lCortina.mpShowII();


	return 0;

}