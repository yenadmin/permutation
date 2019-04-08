# include "permain.h"

SEQARR ABC[MAX];

void DisplayPrimeFactor(ARRAY f,ARRAY p,int n)
{
	int i;
	for(i=0;i<n-1;i++)
		std::cout << f[i] << " Occuress " << p[i] << " Times, ";
	std::cout << f[i] << " Occuress " << p[i] << " Times " ;
}

void PrintDis(SEQPTR p,int n)
{
	char a='A';
	int i;
	for( i=0;i<n-1;i++)
	{
		a='A'+i;
		std::cout << a << " Gets " << p[i] << ",  ";
	}
	a='A'+i;
	std::cout << a << " Gets " << p[i] << std:: endl;
}

int main()
{
	void main6();
	initseq(0);
	// main1();
	// main2();
	// main3();
	// main4();
	// main5();
	main6();
	return 0;
}

void main6()
{
	SEQARR B[MAX],C[MAX][MAX];
	int  A[10]={2,2,1,3,4};
	int r=3;
	INT n=TotalPossibility(A,r);
	for(INT i=0;i<n;i++)
	{
		cpyseq(B,ABC,n);
		Grouping(i,B,(SEQPTR *)C,A,r,n);
		std::cout << " The " << i <<"   Group is \n\n";
		for(int j=0;j<r;j++)
		{
			std::cout << "The " << j << " Group is : ";
			print(C[j],A[j]);
		}
		std::cout << std::endl << std::endl;
	}

}


				 /*
void main5()
{
	INT a;
	std::cout << " Enter the Number ";
	std::cin >> a;
	int f[MAX],p[MAX],n;
	initarray(f);
	initarray(p);
	PrimeFactors(a,f,p,n);
	DisplayPrimeFactor(f,p,n);
}
				   */



void main4()
{
	int n,r;
	std::cout << " Enter number of Children : " ; std::cin >> n;
	std::cout << " Enter the number of Apples :"; std::cin >> r;
	INT ncr;
	ncr= nCr(n+r-1,r);
	SEQARR str[MAX];
	for(INT i=0;i<ncr;i++)
	{
		T_thDistribution(i,str,n,r);
		PrintDis(str,n);
		pagebk(i);
	}
}
						/*
void main3()
{
	SEQARR ret[MAX];
	int r,A[10] = {2,3,1};
	int ty=3;
	INT tot =TotalRepeatedCombination(A,ty);
	for(INT i=0;i<tot;i++)
	{
		GetRepeatCombination(i,ABC,ret,A,r,ty);
		print(ret,r);
		pagebk(i);
	}
}
					 **/

void main1 ()
{
	SEQARR str[MAX];
	SEQPTR ret;
	INT i,npr,ncr,npor;
	int n =6, r=3;
	npr=nPr(n,r);
	ncr=nCr(n,r);
	npor = nPowerr(n,r);
	for (i=0;i<npr;i++)
	{
		Permutation(i,str,n,r);
		print(str,r);
		pagebk(i);
	}
	std::cout << "Total Permutations are " << npr <<std::endl;
	for(i=0;i<ncr;i++)
	{
		Combination(i,str,n,r);
		print(str,r);
		pagebk(i);
	}
	ret = new SEQARR[r];
	std::cout<< "Total Combinations are " << ncr << std ::endl;
	for(i=0;i<npor;i++)
	{
		Repetation(i,ABC,ret,n,r);
		print(ret,r);
		pagebk(i);
	}
	delete(ret);
	std::cout<< "Total Repetations are " << npor << std::endl;
	npor=nPowerr(2,n);
	for(i=0;i<npor;i++)
	{
		SubSet(i,str,n,r);
		print(str,r);
		pagebk(i);
	}
	delete(ret);
	std::cout<< "Total Sub Sets are " << i << std::endl;
}
void main2()
{
	SEQARR ret[MAX];
	int A[10] = {4,4,2,2,2,1};
	int n=0,ty=3;
	n=SumUp(A,ty);
	int tot=TotalPossibility(A,ty);
	for(int i=0;i<tot;i++)
	{
		T_thOrder(i,ABC,ret,A,n,ty);
		std::cout << i << "    ";
		print(ret,n);
		pagebk(i);
	}
	std::cout << " Total Posibility is : " << tot << " n = " << n;
}
