#include<stdio.h>
#include<fcntl.h>

void main(){
	int fd = creat("Hello.txt",0765);
}