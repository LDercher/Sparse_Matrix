#include "DoubleLL.hpp"
#include "node.hpp"
#include "SparseMatrix.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

#define INT_MAX 500

int randomgen(int max, int min)
{

//int random = min + ((rand() * abs(max - min)));
return rand()%max+min;
}

int main(int argCount, char** args){

clock_t start;

srand(time(NULL));

double duration;

int numElems[5] = {100,500,1000,5000,10000};

int x = 0;

double times[9][11];

tuple<int,int> test;

SparseMatrix* sm1;

SparseMatrix* sm2;

int addcount = 0;

int iter,p1,p2;

while (x < 11)
{

  for (int i = 0; i < 5; i++ )
  {
    test = make_tuple(numElems[i],numElems[i]);

    sm1 = new SparseMatrix(test);

    sm2 = new SparseMatrix(test);

    iter = 0;


    while (iter < 4)
    {
//      for(int j= 0; j < numElems[i] / 4; j++)
    //  {
       while( addcount < numElems[i]/4)
         {
            switch(iter){
            case 0:
            p1 = randomgen(numElems[i]/2 - 1,0);
            p2 = randomgen(numElems[i]/2 - 1,0);
            if(p1 >= numElems[i])
            {
              p1 = p1 - (numElems[i] -1);
            }
            if(p2 >= numElems[i])
            {
              p2 = p2 - (numElems[i]-1);
            }
            test = make_tuple(p1,p2);
    //        cout << "***p1 and p2 = " << p1 << p1 << endl;
            sm1->add(test,rand() % INT_MAX);
            sm2->add(test,rand() % INT_MAX);
            addcount++;
            break;
            case 1:
            p1 = randomgen(numElems[i]/2 - 1,numElems[i] - 1);
            p2 = randomgen(numElems[i]/2 - 1,0);
            if(p1 >= numElems[i])
            {
              p1 = p1 - numElems[i];
            }
            if(p2 >= numElems[i])
            {
              p2 = p2 - numElems[i];
            }
    //        cout << "****p1 and p2 = " << p1 << p1 << endl;
            test = make_tuple(p1,p2);
            sm1->add(test,rand() % INT_MAX);
            sm2->add(test,rand() % INT_MAX);
            addcount++;
            break;
            case 2:
            p1 = randomgen(numElems[i]/2 - 1,numElems[i] - 1);
            p2 = randomgen(numElems[i]/2 - 1,numElems[i] - 1);
            if(p1 >= numElems[i])
            {
              p1 = p1 - numElems[i];
            }
            if(p2 >= numElems[i])
            {
              p2 = p2 - numElems[i];
            }
      //      cout << "****p1 and p2 = " << p1 << p1 << endl;

            test = make_tuple(p1,p2);
        //    cout << "****p1 and p2 = " << p1 << p1 << endl;

            sm1->add(test,rand() % INT_MAX);
            sm2->add(test,rand() % INT_MAX);
            addcount++;
            break;
            case 3:
            p2 = randomgen(numElems[i]/2 - 1,numElems[i] - 1);
            p1 = randomgen(numElems[i]/2 - 1,0);
            if(p1 >= numElems[i])
            {
              p1 = p1 - numElems[i];
            }
            if(p2 >= numElems[i])
            {
              p2 = p2 - numElems[i];
            }
        //  cout << "****p1 and p2 = " << p1 << p1 << endl;

            test = make_tuple(p1,p2);
            sm1->add(test,rand() % INT_MAX);
            sm2->add(test,rand() % INT_MAX);
            addcount++;
            break;
            default:break;
          }
      }
    //}
    iter++;
    addcount = 0;
  }

    start = clock();

    sm1->transpose();

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    printf("\n\n***DURATION = %.10f for test: %i with input size %i \n",duration ,x,numElems[i] );

    times[i][x] = duration;

  //  printf("\n\n***times at %i, %i set to %f\n",i,x, times[i][x] );

      delete sm1;
      delete sm2;

  }

x++;
}

/*for(int i = 0; i < 9; i++)
{
    for(int j = 0; j <  10; j++)
    {

      times[i][10]+=times[i][j];

    }

}

for(int i = 0; i < 9; i++)
{
    for(int j = 0; j <  11; j++)
    {
      if ( j < 10 )
      {

      printf("input size(ascending):%i\ntest num:%i\ntime:%f\n",i,j,times[i][j]);
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

} */

return 0;
}
