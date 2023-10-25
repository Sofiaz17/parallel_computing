#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <math.h>

using namespace std;

double routine1(int n, int b){
    float M[n][n];
    float O[n][n];
    int D = n/b;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i][j] = (rand()%(51000))/1000.000;
           // cout << M[i][j] << " ";
        }
        //cout << endl;
	}
    cout << endl;
    auto start = chrono::high_resolution_clock::now();
   
    for(int i=0; i<b; i++){
        for(int j=0; j<b; j++){
            for(int m=0; m<D; m++){
                for(int o=0; o<D; o++){
                    O[D*(i)+m][D*(j)+o] = M[D*(b-i-1)+m][D*(b-j-1)+o];
                }
            }
        }
    }

  /*  for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << O[i][j] << " ";
        }
        cout << endl;
	}
    cout << endl;*/
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

int main(int argc, char** argv){
	srand(time(NULL));
    int n, i;
    double duration;

    FILE* file;
    file = fopen("dataMatrix_vectorized.csv", "w");
    if(file != NULL){
       // fprintf(file, "b_size,time\n");
       cout << "file correctly opened" << endl;
    } else {
        cout << "error in opening file\n";
        return -2;
    }
    for( i = 4; i <= pow(2,8) ; i*=2){ 

        duration = routine1(pow(2,12),i);
        
        if(file != NULL){
            fprintf(file, "%d,%.17g\n",i,duration);
         }
         cout << "n = " << "2^(" << log2f(i) << ")," << " Time: " << duration << " seconds" << endl;
     
    }
    fclose(file);
    
    return 0;
}