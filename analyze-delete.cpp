#include "DoubleLL.hpp"
#include "node.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

#define INT_MAX 500

int main(int argCount, char** args){

clock_t start;

double duration;

int numElems[9] = {10,50,100,500,1000,5000,10000,50000,100000};

int x = 1;

double times[11];

int ran,check;

while (x < 11)
{

  for (int i = 0; i < 9; i++ )
  {
    DoubleLL* myDLL = new DoubleLL();

    srand(time(NULL));



    for(int j= 0; j < numElems[i]; j++)
    {
      ran = rand()% INT_MAX;;
      if(j == numElems[i]/2)
      {
        check = ran;
      }
      myDLL->add(ran,0,myDLL->getSize() );
    }

    start = clock();

    myDLL->deleteAll(check);

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;



    delete myDLL;

  }
  times[x-1] = duration;
  x++;
 }

 printf("times:" );

 for (int j = 0; j < 10; j++)
 {
   times[11] += times[j];

   printf(" %f ", times[j]);

 }

 printf("\naverage time: %f\n\n", times[11]/10);

return 0;
}
