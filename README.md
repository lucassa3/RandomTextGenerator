# RandomTextGenerator
A ngram-based random sentences generator implemented in c++ that learns with wikipedia xml dump files.

## Requirements
* Install Boost library;
```
$ sudo apt-get install libboost-all-dev
```
* Install MPI for c++;
```
$ sudo apt-get install libmpich-dev
```
* Download some wikipedia .xml dumps. You can find some [here](https://dumps.wikimedia.org/enwiki/20180401/).

## How to use it
There are two versions, the sequential and the parallel. inside each version folder, there is a makefile. use:
```
$ make
```
to compile everything. then use:
```
$ mpiexec -n {number of processes} ./main
```
where {number of processes} is the number of processes you wan to create (e.g.: 4)
<br><br>
There are some optional environment variables you might want to use: 
* NGRAM_NUM - number of ngrams created when parsing the xml (Default: 4);
* PAGE_LIMIT -  number of pages each process will read from their respective xml. Big numbers will take lnger to parse (Default: 2000).
* TXT_LENGTH - number of words multiplied by NGRAM_NUM that the generatedd text will have (Default: 20)


Change what dump files you want to use for learning by replacing in main.cpp at wiki_files variable the path of each of your dump files. Since the project will route each dump in a separate process, be sure to set {number of processes} to the number of dump files that you're using.
