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

    for (int i = 0; i < 9; i++ )
    {

    //s  cout << "*****At iteration of elems list " << i << endl;

      DoubleLL* myDLL = new DoubleLL();

      srand(time(NULL));

        start = clock();
      for(int j= 0; j < numElems[i]; j++)
      {
        myDLL->addBack(rand()% INT_MAX,0,0);
        //printf("\n\n duration was %e \n\n size of doubleLL is %i", duration,numElems[i]);

      }

        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

        times[i][x] = duration;


      delete myDLL;




      }
x++;
}




      for(int i = 0; i < 9; i++)
      {
          for(int j = 0; j <  11; j++)
          {

            times[i][11]+=times[j][i];

          }

      }

      for(int i = 0; i < 9; i++)
      {
          for(int j = 0; j <  12; j++)
          {

            printf("input size(ascending):%i\ntest num:%i\ntime:%.10f\nave:%.10f\n",i,j,times[i][j],times[i][11]/10);


          }

      }

return 0;
}
