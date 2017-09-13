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
double times[9][12];
int x = 1;


while (x < 11)
{
  //printf("entered 12 x test while loop \n\n");

for (int i = 0; i < 10; i++ )
{
  DoubleLL* myDLL = new DoubleLL();

  srand(time(NULL));

//printf("input sizes for loop \n\n");

  for(int j= 0; j < numElems[i]; j++)
  {
    start = clock();
    myDLL->add(rand()% INT_MAX,0,myDLL->getSize() );
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    times[i][x] = duration;

  }




  delete myDLL;

}

x++;
}

for(int i = 0; i < 9; i++)
{
  for(int j = 0; j <  11; j++)
  {

    times[i][12]+=times[j][i];

  }

}

for(int i = 0; i < 9; i++)
{
  for(int j = 0; j <  12; j++)
  {

    printf("input size(ascending):%i\ntest num:%i\ntime:%f",i,j,times[i][j]);

  }

}

return 0;
}
