# include "n_queen.h"

extern SEQARR ABC[MAX];  //"ABCDE";

int absval(int ab)
{
	return ((ab < 0)? -ab :ab);
}


bool IsCheck(SEQARR r1, SEQARR c1, SEQARR r2, SEQARR c2)
{
	if (r1 == r2 || c1 == c2 || absval(r1-r2) == absval(c1-c2))
		return true;
	return false;
}


bool IsValidPossibility(SEQPTR seq,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	if(i==j)
				continue;
			if(IsCheck(i,*(seq+i),j,*(seq+j)))
				return false;
		}
	return true;
}

void GenerateSol()
{
	INT i,N;
	int n,count=0;
	std::cout << " Enter the value of n : ";
	std::cin >> n;
//	N = nPowerr(n,n);
	N = nPr(n,n);
	SEQARR  ret[MAX];
	initseq();
	for(i=0;i < N;i++)
	{
//		Repetation(i,ABC,ret,n,n);
		Permutation(i,ret,n,n);
		if (IsValidPossibility(ret,n))
		{
			print(ret,n);
			count++;
		}
	}
	std::cout << " Total number of possibility is : " << count << std::endl;
}


int nqueeenmain()
{
	GenerateSol();
	return 0;
}
