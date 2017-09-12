#include "DoubleLL.hpp"
#include "node.hpp"
#include "SparseMatrix.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

#define INT_MAX 500

int randomgen(int max, int min)
{
srand(time(NULL));
int random = min + ((rand() * (max - min)) / RAND_MAX);
return random;
}

int main(int argCount, char** args){

clock_t start;

double duration;

int numElems[5] = {100,500,1000,5000,10000};

int x = 1;

double times[11];

tuple<int,int> test;

SparseMatrix* sm1;

SparseMatrix* sm2;

int iter,p1,p2;

while (x < 11)
{

  for (int i = 0; i < 5; i++ )
  {
    test = make_tuple(numElems[i],numElems[i]);

    sm1 = new SparseMatrix(test);

    sm2 = new SparseMatrix(test);

    srand(time(NULL));

    iter = 0;

    while (iter < 4)
    {
      for(int j= 0; j < numElems[i] / 4; j++)
      {
        switch(iter){
        case 1:
        p1 = randomgen(numElems[i]/2,1);
        p2 = randomgen(numElems[i]/2,1);
        test = make_tuple(p1,p2);
        sm1->add(test,rand() % INT_MAX);
        sm2->add(test,rand() % INT_MAX);
        case 2:
        p1 = randomgen(numElems[i]/2,numElems[i]);
        p2 = randomgen(numElems[i]/2,1);
        test = make_tuple(p1,p2);
        sm1->add(test,rand() % INT_MAX);
        sm2->add(test,rand() % INT_MAX);
        case 3:
        p1 = randomgen(numElems[i]/2,numElems[i]);
        p2 = randomgen(numElems[i]/2,numElems[i]);
        test = make_tuple(p1,p2);
        sm1->add(test,rand() % INT_MAX);
        sm2->add(test,rand() % INT_MAX);
        case 4:
        p2 = randomgen(numElems[i]/2,numElems[i]);
        p1 = randomgen(numElems[i]/2,1);
        test = make_tuple(p1,p2);
        sm1->add(test,rand() % INT_MAX);
        sm2->add(test,rand() % INT_MAX);
        }

      }
      iter++;
    }

    start = clock();

    sm1->isEqual(sm2);

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

      delete sm1;
      delete sm2;

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
