#Exercise 1 <br>
To run the experiments on the cluster we need to request an interactive session with the following instruction:<br>
    qsub -I -q short_cpuQ <br>
There are other public queues that can be used. For further information about cluster and queues, visit the site <br>
  https://sites.google.com/unitn.it/hpc/home <br><br>

##Compilation <br>
To compile serial code we use the following instruction. Our code is written in C++, so we need to use g++ compiler. <br>
  g++ -o <executable_name> <file_name>.cpp -std=c++11 <br> <br>
  
To compile enabling vectorization we use the following instruction: <br>
 g++ -ftree-vectorize [-ftree-vectorizer-verbose=2] -O3 -o <executable_name> <file_name>.cpp -std=c++11 <br>
The flag -ftree-vectorizer-verbose=2 is only needed to check if vectorization has been successful. <br> <br>

##Running <br>
To run .cpp files we need to type <br>
    ./<executable_name> <br>
To run Python .py files we first need to load Python module <br>
    module load Python-3.8.13 <br>
and then run with <br>
    python3 <python_script>.py
