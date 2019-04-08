#ifndef _PERH
#define _PERH


typedef long INT;
typedef int SEQARR;
typedef SEQARR * SEQPTR;
typedef int * ARRAY;
typedef int ERR;

#define MAX 25

extern SEQARR ABC[MAX];  //"ABCDE";

INT factorial(int a);

INT nCr(int n, int r);

INT nPr(int n, int r);

INT nPowerr(int n, int r);

int SQUT(INT);

int SumUp(int *,int);

INT TotalPossibility(int *p,int);

INT TotalRepeatedCombination(int *,int);

void T_thPermutation(INT t,SEQPTR str,int n, int r);

void T_thCombination(INT t,SEQPTR str,SEQPTR ret, int n, int r);

void T_thDistribution(INT t,SEQPTR s,int n, int r);

void T_thOrder(INT,SEQPTR,SEQPTR,ARRAY,int,int&);

void GetRepeatCombination(int t, SEQPTR st, SEQPTR res, int * p,int &n, int ty);

ERR Permutation(INT t,SEQPTR st,int n, int r);

ERR Combination(INT t,SEQPTR st,int n, int r);

ERR Repetation(INT t, SEQPTR st,SEQPTR ret, int n,int r);

ERR SubSet(INT t,SEQPTR st,int n, int &r);

ERR LikeElementOrder(INT t, SEQPTR st, SEQPTR res, int *p, int n,int ty);

ERR RepeatCombination(INT t, SEQPTR st, SEQPTR res, int * p,int &n, int ty);

ERR Distribution(INT t,SEQPTR s,int n, int r);

ERR Grouping(INT t,SEQPTR s, SEQPTR *res, int * a,int r,int n);

void cpy(SEQPTR des,SEQPTR sou,int n);

void initarray(ARRAY p);

void initseq(int n=0);

void print(SEQPTR st,int r);

void cpyseq(SEQPTR,SEQPTR,int);

void remove(SEQPTR,SEQPTR,int);

inline void pagebk(int i)
{
	if(i%24 == 23)
	  ;
}

void PrimeFactors(int, ARRAY,ARRAY,int);

#endif
