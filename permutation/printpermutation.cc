# include "permain.h"
# include <stdlib.h>

int main(int argc, char** argv) {
  SEQPTR str;
  if (argc != 3) {
    std::cout << "Error in argument "<< std::endl;
    std::cout << "Usage " << argv[0] << " <total Objects> <to select object>" << std::endl;
    return -1;
  }
  int n = atoi(argv[1]);
  int r = atoi(argv[2]);
  str = new SEQARR[n];
  INT i, npr;
  npr = nPr(n,r); 
  initseq(0);
  for(i=0; i<npr; i++){
    Permutation(i, str, n, r);
    print(str,r);
    pagebk(i);
  } 
  return 0;
}
