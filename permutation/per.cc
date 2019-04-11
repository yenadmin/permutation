# include <string.h>
# include <math.h>

# include "per.h"
# include <iostream>
# include<ostream>

int SQUT(INT a)
{
	return ((int)ceil( sqrt(a)));
}
SEQARR ABC[MAX];


bool IsPrime(INT a)
{
	if( a== 2 || a == 3)
		return true;
	if( a%2 == 0 || a ==1 )
		return false;
	int n = SQUT(a)+1;
	for(int i=3;i<n;i+=2)
		if( a%i == 0)
			return false;
	return true;
}

ERR PrimeFactors(INT k,ARRAY fact, ARRAY power,int &n)
{
	int i;
	n=0;
	if(k%2 == 0)
		fact[n++]=2;
	if(IsPrime(k))
	{
		fact[0]=k;
		power[0]=1;
		return 0;
	}
	for(i=3;i<k;i++)
		if(IsPrime(i) && k%i==0)
			fact[n++]=i;
	for(i=0;i<n;i++)
	{
		while(k%fact[i] == 0)
		{
			k/=fact[i];
			power[i]++;
		}
	}
	return 0;
}


int GCD(int a,int b)
{
	int t;
	if(b==0)
	{
	//	cout << "Error in b ";
		return -1;
	}
	t=a;
	while((a%b)!=0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return t;
}

int GCDArray(int *A,int ty)
{
	int n=A[0];
	for(int i=1;i<ty;i++)
		 n=GCD(n,A[i]);
	return n;
}

int LCM(int a,int b)
{
	return( a/GCD(a,b)*b);
}


int LCMArray(int *A,int ty)
{
	int n=A[0];
	for(int i=1;i<ty;i++)
		 n=LCM(n,A[i]);
	return n;
}


void cpy(SEQPTR des,SEQPTR sou,int n)
{
	for(int i=0;i<n;i++)
		*(des+i)= *(sou+i);
}

void initseq(int n)
{
        std::cout<<"init.."<<std::endl;
	for(int i=0;i<MAX;i++)
		ABC[i] = i+n;
        std::cout<<"init.. complete"<<std::endl;
}


void print(SEQPTR st,int r)
{
	if ( r==0) 
		std::cout << " Nothing is Selected ";
	
	for(int i=0;i<r;i++)
		std::cout << *(st+i) << " ";
	std::cout << std::endl;
}

INT factorial(int a)
{
	if(a<2)
		return 1;
	INT r=a;
	for(int i=a-1;i>1;i--)
		r*=i;
	return r;
}

INT nCr(int n, int r)
{
	if (r < 0 || n <0 || n < r)
		return -1;
	INT nu=1,de =1;
	if(r == 0 || r == n)
		return (1);
	if(r > n - r)
		r = n - r;
	for (int i =1; i <= r;i++)
	{
		nu*=n--;
		de*=i;
	}
	return (nu/de);

}

INT nPr(int n, int r)
{
	if (r < 0 || n <0 || n < r)
		return -1;
	INT d=n--;
	for(int i=1; i <r ;i++)
		d*=n--;
	return d;
}

INT nPowerr(int n, int r)
{
	if ( r == 0)
		return 1;
	INT re =n;
	for(int i=1;i<r;i++)
		re *=n;
	return re;
}

INT TotalPossibility(int *p,int ty)
{
	int n= SumUp(p,ty);
	INT s,res=factorial(n);
	for(int i=0;i<ty;i++)
	{
		s=factorial(p[i]);
		if(s==0)
		{
			//cout << "error div ";
			return -1;
		}
		res/=s;
	}
	return res;
}


void T_thPermutation(INT t,SEQPTR str,int n, int r)
{
	if(r==1 ) {
          str[0] = str[t];
          return;
        }
	int q,re,d;
	d= nPr(n-1,r-1);
	q=t/d;
	re=t%d;
	SEQARR C= str[q];
	for(int j=q;j>0;j--)
		str[j] =str[j-1];
	str[0] = C;
	T_thPermutation(re,str+1,n-1,r-1);
}

ERR Permutation(INT t,SEQPTR st,int n, int r)
{
	if (r>n || t> nPr(n,r))
		return (-1);
	cpy(st,ABC,n);
	T_thPermutation(t,st,n,r);
	*(st+r)=0;
	return 0;
}

void T_thCombination(INT t,SEQPTR str,SEQPTR ret, int n, int r)
{
	if(n==0 || r ==0)
		return;
	int d = nCr(n-1,r-1);

	if( t < d)
	{
		ret[0] = str[0];
		T_thCombination(t,str+1,ret+1,n-1,r-1);
	}
	else
	{
		T_thCombination(t-d,str+1,ret,n-1,r);
	}
}


ERR Combination(INT t,SEQPTR st,int n, int r)
{
	if (r>n || t> nCr(n,r))
		return (-1);
	T_thCombination(t,ABC,st,n,r);
	return 0;
}

ERR Repetation(INT t, SEQPTR st,SEQPTR ret, int n,int r)
{
	if(t >= nPowerr(n,r))
		return -1;
	for(int i=r-1;i>=0;i--)
	{
		int d = t%n;
		t=(t-d)/n;
		*(ret+i) = *(st+d);
	}
	return 1;
}

ERR SubSet(INT t,SEQPTR st,int n, int &r)
{
	if(t==0)
	{
		r=0;
		return 0;
	}
	INT d =nPowerr(2,n);
	if(t==d-1)
	{
		r=n;
		cpy(st,ABC,r);
		return 0;
	}
	if(t >= d )
		return(-1);
	INT i,ncr, Sncr =0;
	for( i=1; i<n; i++)
	{
		ncr =nCr(n,i);
		if(t > Sncr && t<=Sncr+ncr)
		{
			Combination(t-Sncr-1,st,n,i);
			r=i;
			return 0;
		}
		Sncr += ncr;
	}
	return(-2);
}

void T_thOrder(INT t, SEQPTR st, SEQPTR res, int *p, int n,int &ty)
{
	int *ptr = new int[ty];
	SEQPTR s= new SEQARR[ty];
	for(int i=0;i<ty;i++)
	{
		ptr[i]=p[i];
		s[i]=st[i];
	}
	LikeElementOrder(t,s,res,ptr,n,ty);
	delete[] ptr;
	delete[] s;
}

void initarray(ARRAY a)
{
	for(int i=0;i<MAX;i++)
		a[i]=0;
}

void cpyseq(SEQPTR d,SEQPTR s,int n)
{
	for(int i=0;i<n ;i++)
		d[i]=s[i];
}

void Delete(SEQPTR d,int t,int n)
{
	for(int i=t;i<n-1;i++)
		d[i]=d[i+1];
}

void remove(SEQPTR d,SEQPTR s,int n,int r)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[j]==s[i])
			{
				Delete(d,j,n);
				n--;
			}
		}
	}
}




int SumUp(int *A,int ty)
{
	int n=0;
	for(int i=0;i<ty;i++)
		 n+=A[i];
	return n;
}

ERR LikeElementOrder(INT t, SEQPTR st, SEQPTR res, int *p, int n,int ty)
{
	int i;
	if( n == 0)
		return 0;
	if(n==1)
	{
		res[0] = st[0];
		return 0;
	}
	if(n == ty)
	{
		cpy(res,st,n);
		T_thPermutation(t,res,n,n);
		return 0;
	}
	if(t == 0)
	{
		int i=0,j=0;
		while(i<n)
		{
			if(p[j] == 0)
				j++;
			res[i] = st[j];
			i++;
			p[j]--;
		}
		return 0;
	}

	INT tot,sum=0;
	tot = TotalPossibility(p,ty);
	if(t > tot)
		return (-1);
	for(i=0;i<ty;i++)
	{
		if(sum+tot*p[i]/n <= t )
			sum+=tot*p[i]/n;
		else
			break;
	}
	if(i==ty)
		return -1;
	res[0]=st[i];
	p[i]--;
	return(LikeElementOrder(t-sum,st,res+1,p,n-1,ty));
}

INT TotalRepeatedCombination(int *p,int n)
{
	INT r=1;
	for(int i=0;i<n;i++)
		r*=p[i]+1;
	return r;
}

void GetRepeatCombination(INT t, SEQPTR st, SEQPTR res, int * p,int &n, int ty)
{
	int * A =new int [ty];
	for(int i=0;i<ty;i++)
		A[i] = p[i];
	RepeatCombination(t,st,res,A,n,ty);
}

ERR RepeatCombination(INT t, SEQPTR st, SEQPTR res, int * p,int &n, int ty)
{
	if(t==0)
	{
		n=0;
		return 0;
	}
	if( ty == 0)
	{
		//cout << " Error with ty ";
		return -1;
	}

	if(t==1)
	{
		res[0] = st[0];
		n=1;
		return 0;
	}
	p[0]--;
	INT k=TotalRepeatedCombination(p,ty);
	if(t<=k)
	{
		res[0]=st[0];
		if(p[0]==0)
			RepeatCombination(t-1,st+1,res+1,p+1,n,ty-1);
		else
			RepeatCombination(t-1,st,res+1,p,n,ty);
		n++;
	}
	else
		RepeatCombination(t-k,st+1,res,p+1,n,ty-1);
	return 0;
}

void T_thDistribution(INT t,SEQPTR s,int n, int r)
{
	for(int i=0;i<n;i++)
		s[i]=0;
	Distribution(t,s,n,r);
}

ERR Distribution(INT t,SEQPTR s,int n, int r)
{
	int N=n+r-1;
	int p[3]= {r,n-1}, ty=2;
	SEQARR A[3] ={0,1};
	SEQPTR R = new SEQARR[N];
	T_thOrder(t,A,R,p,N,ty);
	int j=0;
	for(int i=0;i<N;i++)
	{
		if(R[i]==0)
			s[j]++;
		else
			j++;
	}
	delete[] R;
	return 0;
}

ERR Grouping(INT t,SEQPTR s, SEQPTR *res, int * a,int r,int n)
{
	INT k,N;
	SEQPTR re=new SEQARR[n];

	for(int i=0;i<r;i++)
	{
		N=TotalPossibility(a+i,r-i);
		k=TotalPossibility(a+i+1,r-i-1);
		INT Q=N/k;
		INT P=Q;
		while(P+Q<t)
			P+=Q;
		T_thCombination(P,s,re,n,a[i]);
		t-=P;
		cpyseq(res[i],re,a[i]);
		remove(s,re,a[i],n);
		n-=a[i];
	}
	delete[] re;
	return 0;
}

