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
double times[11];
int x = 1;


while (x < 11)
{

for (int i = 0; i < 9; i++ )
{
  DoubleLL* myDLL = new DoubleLL();

  srand(time(NULL));

  start = clock();

  for(int j= 0; j < numElems[i]; j++)
  {
    myDLL->add(rand()% INT_MAX;,0,myDLL->getSize() );
  }

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

printf("\naverage time: %f \n\n", times[11]/10);

return 0;
}
