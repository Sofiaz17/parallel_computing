#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <math.h>

using namespace std;

double routine1(int n){
    float *a = new float[n];
    float *b = new float[n];
    float* __restrict c = new float[n];

    for(int j=0; j<n; j++){
    	a[j] = (rand()%(51000))/1000.000;
    	b[j] = (rand()%(51000))/1000.000;
	}
    auto start = chrono::high_resolution_clock::now();
    for(int j=0;j<n;j++){
        c[j] = a[j] + b[j];
    } 
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    delete[] a;
    delete[] b;
    delete[] c;

    return duration.count();
}

int main(int argc, char** argv){
	srand(time(NULL));
    int n, i;
    double duration;

   /* cout << "Inserire lunghezza array: ";
    cin >> n;*/
   
    FILE* file;
    file = fopen("dataEx1.csv", "w");
    if(file != NULL){
        cout << "file correctly opened" << endl;
        //fprintf(file, "array_size,time\n");
    } else {
        cout << "error in opening file\n";
        return -2;
    }
    for( i = 16; i <= pow(2,22) ; i*=2){ 

        duration = routine1(i);
        
        if(file != NULL){
            fprintf(file, "%d,%.17g\n",i,duration);
         }
         cout << "n = " << "2^(" << log2f(i) << ")," << " Time: " << duration << " seconds" << endl;
    }
    fclose(file);
    
    return 0;
}
