#include "DoubleLL.hpp"
#include "node.hpp"
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

#define INT_MAX 500

int main(int argCount, char** args){

clock_t start;

double duration;

int numElems[9] = {10,50,100,500,1000,5000,10000,50000,100000};

int x = 0;

double times[9][11];

int ran,check;

while (x < 10)
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

    times[i][x] = duration;


    delete myDLL;

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
       printf("input size(ascending):%i\ntest num:%i\ntime:%.10f\n",i,j,times[i][j]);
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
