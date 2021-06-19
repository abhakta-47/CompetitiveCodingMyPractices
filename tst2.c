#include<stdio.h>
#include<string.h>

int main(){
//	int res;
//	char name[30],prev[30]="test";
//	printf("Enter name: ");
//	fgets(name, sizeof(name), stdin);  // read string
	//printf("Name: ");
//	puts(name);    // display string
	//printf(" = ");
//	puts(prev);
//	res=strcmp(name,prev);
//	printf("%d",res);
//	if( res==0)
//		printf("done");
//	else
//		printf("not done");
//	return 0;
   char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    int resu
    // comparing strings str1 and str2
    result = strcmp(str1, str2);
    printf("strcmp(str1, str2) = %d\n", result);

    // comparing strings str1 and str3
    result = strcmp(str1, str3);
    printf("strcmp(str1, str3) = %d\n", result);

    return 0;
}
