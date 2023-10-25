# Exercise 1
To run the experiments on the cluster we need to request an interactive session with the following instruction:
    qsub -I -q short_cpuQ
There are other public queues that can be used. For further information about cluster and queues, visit the site 
  https://sites.google.com/unitn.it/hpc/home

## Compilation
To compile serial code we use the following instruction. Our code is written in C++, so we need to use g++ compiler.
```bash
  g++ -o <executable_name> <file_name>.cpp -std=c++11
```

To compile so that vectorization is enabled we use the following instruction:
```bash
 g++ -ftree-vectorize [-ftree-vectorizer-verbose=2] -O3 -o <executable_name> <file_name>.cpp -std=c++11
 ```
The flag `-ftree-vectorizer-verbose=2` is only needed to check if vectorization has been successful.

## Running
To run .cpp files we need to type
```bash
./<executable_name>
```
To run Python .py files we first need to load Python module
```
module load Python-3.8.13
```
and then run with
```
python3 <python_script>.py
```
