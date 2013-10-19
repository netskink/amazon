#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define DEBUG_MAIN
#if defined(DEBUG_MAIN)
int Debug=1;
#else
int Debug=0;
#endif
#define PRINT(x...) do{if(Debug){fprintf(stderr, "%s [%d]:",__FILE__, __LINE__); fprintf(stderr, x);}} while(0)
// then use  DPRINT("testing %s\n", "foo");


char *pchBuffer;


int find_2nd_largest(int *p, int len) {
    int largest;
    int i;
    int nextlargest;
    
    largest = nextlargest = p[0];
    for (i=1;i<len;i++) {
        if (p[i] > largest) {
            nextlargest=largest;
            largest = p[i];
        } else if (p[i] > nextlargest) {
            nextlargest = p[i];
        }
    }

	return nextlargest;

}


void append(char *s, int len) {

   if (NULL == pchBuffer) {
	   pchBuffer = malloc(len+1);
	   pchBuffer[0]=0;
	   if (NULL == pchBuffer) {
		   printf("error\n");
		   return;
	   }
   } else {
	   pchBuffer = realloc(pchBuffer,len+strlen(pchBuffer)+1);
	   if (NULL== pchBuffer ) {
		   printf("error\n");
		   return;
	   }
   }
   
   strncat(pchBuffer, s, len);
}

void insert(char *s, int len, int pos) {
   char *pchBufferNew;

   pchBufferNew = malloc(len+strlen(pchBuffer)+1);
   strncpy(pchBufferNew,pchBuffer,pos);
   strncpy((char *) &(pchBufferNew[pos]),s,len);
   strcat(pchBufferNew, (char *) &(pchBuffer[pos]));

	strcpy(pchBuffer,pchBufferNew);
	free(pchBufferNew);
   
}




int test1(void) {
	int p[] = {1,2,3,4};
	
	if (3 == find_2nd_largest(p, 4) ) {
		return 0;
	} else {
		return 1;
	}
}

int test2(void) {
	int p[] = {1,2,4,3};
	
	if (3 == find_2nd_largest(p, 4) ) {
		return 0;
	} else {
		return 1;
	}
}


int test3(void) {
	int p[] = {1,3,4,3};
	
	if (3 == find_2nd_largest(p, 4) ) {
		return 0;
	} else {
		return 1;
	}
}


int test4(void) {
	char p[] = {'o','n','e',0};

	append(p,4);

	if (0 == strcmp("one",p) ) {
		return 0;
	} else {
		PRINT("pchBuffer = %s\n",pchBuffer);
		return 1;
	}
}


int test5(void) {
	char p[] = {'1','2','3',0};

	append(p,4);

	if (0 == strcmp("one123",pchBuffer) ) {
		return 0;
	} else {
		PRINT("pchBuffer = %s\n",pchBuffer);
		return 1;
	}
}


int test6(void) {
	char p[] = {'x','y','z'};


//  insert(char *s, int len, int pos) {
	insert(p,3,3);

	if (0 == strcmp("onexyz123",pchBuffer) ) {
		return 0;
	} else {
		PRINT("pchBuffer = %s\n",pchBuffer);
		return 1;
	}
}





int main(int argc, char *argv[]) {

	int iRC;

	iRC=EXIT_SUCCESS;

	if (argc != 1) {
		fprintf(stderr, "Usage: %s \n", argv[0]);
		iRC=EXIT_FAILURE;
		exit(iRC);
	}


	
	if ( test1() ) {
		PRINT("fail in test 1\n");
	}
		
	if ( test2() ) {
		PRINT("fail in test 2\n");
	}

	if ( test3() ) {
		PRINT("fail in test 3\n");
	}


	if ( test4() ) {
		PRINT("fail in test 4\n");
	}

	
	if ( test5() ) {
		PRINT("fail in test 5\n");
	}

		
	if ( test6() ) {
		PRINT("fail in test 6\n");
	}

	
	

	exit(iRC);

}





