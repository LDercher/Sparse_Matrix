#include "DoubleLL.hpp"
#include "node.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

#define INT_MAX 500

int main(int argCount, char** args){

clock_t start;

double duration;

DoubleLL* temp;

int numElems[9] = {10,50,100,500,1000,5000,10000,50000,100000};

int x = 0;

double times[9][11];

int ran;

while (x < 10)
{

  for (int i = 0; i < 9; i++ )
  {
    DoubleLL* myDLL = new DoubleLL();

    srand(time(NULL));

    for(int j= 0; j < numElems[i]; j++)
    {
      ran = rand();

      myDLL->add(ran,0,myDLL->getSize() );
    }

    DoubleLL* posList = new DoubleLL();

    for(int k = 0; k < (1 + ( rand() %  100  )); k++)
    {

      posList->addBack(rand(), 0, 0);

    }

    start = clock();

    temp = myDLL->getPositionList(posList);

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    times[i][x] = duration;




    delete myDLL;
    delete posList;

  }

  x++;
  }

  for(int i = 0; i < 9; i++)
  {
      for(int j = 0; j <  10; j++)
      {

        times[i][10]+=times[j][i];

      }

  }

  for(int i = 0; i < 9; i++)
  {
      for(int j = 0; j <  11; j++)
      {
        if ( j < 10 )
        {

        printf("input size(ascending):%i\ntest num:%i\ntime:%.20f\n",i,j,times[i][j]);
      }
      else
      {
        if(times[i][10]/10 < 0)
        {
          printf("ave = %i\n\n",0);
        }
        else
        {
        printf("ave = %f\n\n",times[i][10]/10);
        }
      }

      }

  }

return 0;
}
