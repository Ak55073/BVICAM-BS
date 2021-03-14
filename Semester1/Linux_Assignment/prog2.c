#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

void main(){
	char bufi[20]="abcdefghij1234567890";
	char bufo[20];

	int fd, szw , szr;
	fd = open("Hello.txt",O_RDWR);

	// Writing in File
	//szw = write(fd,bufi,10);
	//printf("\nTotal Written count = %d", szw);
	//printf("\n");

	// Reading from File
	szr = read(fd,bufo,5);
	printf("\nRead Count = %d", szr);
	printf("\nData = ");
	for(int i = 0; i<5 ; i++)
	{
		printf("-> %c",bufo[i]);
	}
	printf("\n");
	close(fd);
	
	// Checking file permission
	printf("\nBEFORE CHMODE\n");
	printf("\n File existence = %d",access("Hello.txt",F_OK));
	printf("\n File Read = %d",access("Hello.txt",R_OK));
	printf("\n File Write = %d",access("Hello.txt",W_OK));
	printf("\n File Execute = %d",access("Hello.txt",X_OK));
	printf("\n");

	// Changing file permission
	chmod("Hello.txt",S_IRWXO|S_IRWXU);

	// Checking file permission
	printf("\nAFTER CHMODE\n");
	printf("\n File existence = %d",access("Hello.txt",F_OK));
	printf("\n File Read = %d",access("Hello.txt",R_OK));
	printf("\n File Write = %d",access("Hello.txt",W_OK));
	printf("\n File Execute = %d",access("Hello.txt",X_OK));
	printf("\n");
}