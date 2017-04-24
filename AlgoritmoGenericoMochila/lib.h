#pragma once
#ifndef  __lib_h_
#define __lib_h_

typedef class CSListStrDbl *PLIST;

typedef struct NODE *PNODE;
typedef struct NODE {
	char* sVal;
	int sValue;
	PLIST sList;
	PNODE sNxt;
	PNODE sPrev;
};


class CSListStrDbl {
protected:
	PNODE aHead, aTail;

public:
	CSListStrDbl(void);
	~CSListStrDbl(void);

	void mpInsert(char *pVal);
	void mpInsert(PNODE pVal);
	void mpInsert(char *pVal,int pValue);
	void mpInsert(char *pCat, char *pName, int pValue);
	void mpShow(bool pBack = false);
	void mpShowII(bool pBack = false);
	bool mfDelete(char *pVal);
	bool mfDeleteAll(char *pMes, char *pPers);
	bool mfIsEmpty(char *pMes);
	bool mfBlend(char *pInd1, char *pInd2);
	int mfSumaVal(char *pInd);
	PNODE mfGiveNode(char *pInd);
private:
	PNODE mfInit(char *pVal,int pValue);
	PNODE mfSearch(char *pval);
};

#endif //__lib_h_