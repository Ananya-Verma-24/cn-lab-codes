#include<iostream>
using namespace std;

int a[100], b[100], i, j, len, k, count=0;

int gp[] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};


void div(){
	for(i=0; i<k; i++){
		if(a[i] == gp[count]){
			for(j=i; j< 17+i; j++){
				a[j] = a[j] ^ gp[count++];
			}
		}
		count = 0;
	}
}

int main(){

cout<<"Enter the length of data frame: ";
cin>>len;
cout<<endl<<"Enter the message: ";
for(i=0;i<len;i++){
	cin>>a[i];
}

for(i=0; i<16; i++){
	a[len++] = 0;
}

for(i=0; i<len; i++){
	b[i] = a[i];
}

k = len-16;

div();

for(i=0; i<len ; i++){
	b[i] = b[i] ^ a[i];
}

cout<<endl<<"Data to be transmitted: ";
for(i=0; i<len;i++){
	cout<<b[i]<<" ";
}

cout<<endl<<"Enter the received data: ";
for(i=0; i<len; i++){
	cin>> a[i];
}

div();

for(i=0; i<len; i++){
	if(a[i] != 0){
		cout<<"\n ERROR! in received data";
		goto END;
	}
}

cout<<"\n Data received is ERROR FREE";
END: cout<<"\n Remainder is: ";

for(i=(len-16); i<len; i++){
	cout<<a[i]<<" ";
}

cout<<endl;

}
