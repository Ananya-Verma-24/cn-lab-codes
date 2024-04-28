#include <stdio.h>
#include <string.h>

#define N strlen(gen_poly)

char data[28];
char check_crc[28];
char gen_poly[28];
int data_len, i,j;


void XOR(){
    for(j=0; j<N; j++){
        check_crc[j] = (check_crc[j] == gen_poly[j]) ? '0' : '1' ;
    }
}


void crc(){
    for(i=0; i<N ; i++){
        check_crc[i] = data[i];
    }

    do{
        if(check_crc[0] == '1'){
            XOR();
        }

        for(j=0; j<N-1; j++){
            check_crc[j] = check_crc[j+1];
        }
        check_crc[j] = data[i++];

    } while(i<= data_len+N-1);
}

void receiver(){

    printf("Enter the received data: ");  
    scanf("%s", data);  
    printf("\n-----------------------------\n");  
    printf("Data received: %s", data);  
 
    crc();  

    for(i=0;(i<N-1) && (check_crc[i]!='1');i++);  
        if(i<N-1)  
            printf("\nError detected\n\n");  
        else  
            printf("\nNo error detected\n\n");  

}


int main(){
    printf("Enter the data to be transmitted: ");
    scanf("%s",data);

    printf("Enter the generated polynomial: ");
    scanf("%s",gen_poly);

    data_len = strlen(data);

    for(i=data_len; i< data_len+N-1; i++){
        data[i] = '0';
    }

    printf("\n ----------------------- \n");

    printf("Data padded with N-1 zero added : %s", data);

    printf("\n ----------------------- \n");

    crc();

    printf("\nCRC or Check value is : %s",check_crc);  
 
    for(i=data_len;i<data_len+N-1;i++)  
        data[i]=check_crc[i-data_len];  
    printf("\n----------------------------------------");  

    printf("\n Final data to be sent : %s",data);  
    printf("\n----------------------------------------\n");  

    receiver();  
}