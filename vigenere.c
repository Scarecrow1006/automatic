#include<stdio.h>
#include<string.h>
//#include<cs50.h>
#include <ctype.h>

int gettxt(char a[]);
int primeKey(char* a,char b[]);
void encrypt(char a[],char key[],char cprtxt[1000],int len1,int len2);

int main(int argc,char* argv[]){ 
    if(argc!=2){
        printf("Error\n");
        return 1;
    }
    int i;
    char plntxt[1000],cprtxt[1000];
    char key[1000];
    int key_len=primeKey(argv[1],key);
    //printf("key_len: %d\n",key_len);
    int len=gettxt(plntxt);
    //printf("len: %d\n",len);
    encrypt(plntxt,key,cprtxt,len,key_len);
    printf("ciphertext: ");
    for(i=0;i<len;i++){
        printf("%c",cprtxt[i]);
    }
    printf("\n");
    return 0;
}

int gettxt(char plntxt[1000]){
    printf("plaintext: ");
    scanf(" %[^\n]s",plntxt);
    int len=strlen(plntxt);
    printf*("len = %d\n",len);
    return len;
}

int primeKey(char* in_key,char key[1000]){
    int len=strlen(in_key);
    int i;
    for(i=0;i<len;i++){
        if(in_key[i]>96&&in_key[i]<123){
            key[i]=toupper(in_key[i]);
        }
        else{
            key[i]=in_key[i];
        }
    }
    return len;
}

void encrypt(char plntxt[1000],char key[1000],char cprtxt[1000],int len,int key_len){
    int i,j;
    for(i=0;i<len;i++){
        j=i%key_len;
        if((plntxt[i]>64)&&(plntxt[i]<91)){
            cprtxt[i]=(plntxt[i]+key[j]-65);
            if(cprtxt[i]>=91){
                cprtxt[i]=cprtxt[i]-26;
            }
        }
        else if((plntxt[i]>96)&&(plntxt[i]<123)){
            cprtxt[i]=(plntxt[i]+key[j]-65);
            if(cprtxt[i]>=123){
                cprtxt[i]=cprtxt[i]-26;
            }
        }
        else{
            cprtxt[i]=plntxt[i];
        }
    }
    cprtxt[len]='\0';
    //printf("1: %c\n2: %c\n3: %c\n4: %c\n5: %c\n",cprtxt[0],cprtxt[1],cprtxt[2],cprtxt[3],cprtxt[4]);
    //return cprtxt;
}
