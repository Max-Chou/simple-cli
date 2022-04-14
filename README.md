# Simple Command Line Interface in C

## Overview

This is a simple command line interface in C. I've read lots of C projects having complex command line interface(Huge main). I want my command line interface easy to manage when more features are comming. 

## Usage


### Create Root Command 
```c
command_t *rootCmd = calloc(1, sizeof(command_t));
initCommand(rootCmd, "root", rootFunc);
```


### Add Sub Command 

### Execute Root command

### Parse arguments and options

I just use getopt to do the work.

## TODO

* add context 
* free memory


## Reference

[cobra in Go](https://github.com/spf13/cobra)
