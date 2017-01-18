#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>

int DEBUG = 0;

int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
void print1d(int *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) printf(" ");
    printf("%d", vec[i]);
  }
  printf("\n");
}

using namespace std;
struct NODE {
  char name[30];
  int size;
  int ntaxi;
  int npizza;
  int ngirl;
  NODE () {
    ntaxi = npizza = ngirl = 0;
  }
  void getType(char *num) {
    int c = num[0];
    if(num[0] == c &&
       num[1] == c &&
       num[3] == c &&
       num[4] == c &&
       num[6] == c &&
       num[7] == c) ntaxi++;
    else if(num[0]>num[1] &&
	    num[1]>num[3] &&
	    num[3]>num[4] &&
	    num[4]>num[6] &&
	    num[6]>num[7]) npizza++;
    else ngirl++;
    return;
  }
  void scan() {  
    char num[100];
    scanf("%d%s", &size, name);
    for(int j=0; j<size; j++) {
      scanf("%s", num);
      getType(num);
    }
  }
};

int compare_NODE_dec1 (const void * a, const void * b) {
  return ( (*(NODE*)b).ntaxi - (*(NODE*)a).ntaxi );
}
int compare_NODE_dec2 (const void * a, const void * b) {
  return ( (*(NODE*)b).npizza - (*(NODE*)a).npizza );
}
int compare_NODE_dec3 (const void * a, const void * b) {
  return ( (*(NODE*)b).ngirl - (*(NODE*)a).ngirl );
}

main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;

  int nFr;
  scanf("%d", &nFr);
  NODE fr[nFr];
  int maxtaxi=0, maxpizza=0, maxgirl=0;
  for(int i=0; i<nFr; i++) {
    fr[i].scan();
    maxtaxi = Max(maxtaxi, fr[i].ntaxi);
    maxpizza = Max(maxpizza, fr[i].npizza);
    maxgirl = Max(maxgirl, fr[i].ngirl);
  }

  int cnt;
  cnt = 0; cout << "If you want to call a taxi, you should call:";
  for(int i=0; i<nFr; i++) {
    if(fr[i].ntaxi == maxtaxi) {
      if(cnt > 0) cout << ",";
      cout << " " << fr[i].name; 
      cnt++;
    }
  }
  cout << "." << endl;
  cnt = 0; cout << "If you want to order a pizza, you should call:";
  for(int i=0; i<nFr; i++) {
    if(fr[i].npizza == maxpizza) {
      if(cnt > 0) cout << ",";
      cout << " " << fr[i].name; 
      cnt++;
    }
  }
  cout << "." << endl;
  cnt = 0; cout << "If you want to go to a cafe with a wonderful girl, you should call:";
  for(int i=0; i<nFr; i++) {
    if(fr[i].ngirl == maxgirl) {
      if(cnt > 0) cout << ",";
      cout << " " << fr[i].name; 
      cnt++;
    }
  }
  cout << "." << endl;



  exit(0);
}

/*

g++ 151B.cpp; cat 151B.in1 | ./a.out 1

g++ 151B.cpp; cat 151B.in2 | ./a.out 1


*/


