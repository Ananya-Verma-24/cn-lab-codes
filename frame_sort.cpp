#include<iostream>
#include<string.h>

using namespace std;

int count = 0,i,j,total,size,num,tsize;
char val[100];

struct frame
{
    int seq;
    int len;
    int flag;
    char data[20];
}n[20], m[20], temp;

void frames()
{
    int ch = 0;
    total = 0;
    cout << "\nSegmented Frames and Transmitting order at sender: \n";

    while(total < tsize)
    {
        n[count].seq = count+1;
        size = rand()%10+1;
        n[count].len = size;
        n[count].flag = 0;
        j = 0;
        if((total+size)<tsize)
        {
            for(i=total,j=0; i<total+size,j<size; i++,j++)
                n[count].data[j] = val[i];
            n[count].data[j] = '\0';
        }
        else
        {
            n[count].len = tsize-total;
            j = 0;
            while(total<tsize)
            {
                n[count].data[j++] = val[total];
                total++;
            }
            // for(i=total,j=0; i<tsize; i++,j++)
            //     n[count].data[j] = val[i];
            n[count].data[j] = '\0';
        }
        total+=size;
        count++;
        //cout << "Total : " << total << endl <<"Count : " << count << endl;
    }

    cout << "\nFreq No.\tFlen\tFlag\tFData\n";
    for(int i = 0; i<count; i++)
    {
        cout << n[i].seq<<"\t\t"<<n[i].len<<"\t"<<n[i].flag<<"\t";
        for(j = 0; j<n[i].len; j++)
            cout << n[i].data[j];
        cout << "\n";
    }
    num = count;
    cout << "\nEnter 1/0 to continue: ";
    cin >> ch;

    if(ch == 0)
        exit(0);
}

void trans()
{
    int ch;
    count = 0;
    cout << "\nBegins: \n";
    while(count < num)
    {
        i = rand()%num;
        if(n[i].flag == 0)
            m[count++] = n[i];
        n[i].flag = 1;
    }
    cout << "\nThe order of frames received at receiving terminal: \n";
    cout << "\nFreq No.\tFlen\tFlag\tFData\n";
    for(i = 0; i<count; i++)
    {
        cout << m[i].seq <<"\t\t"<<m[i].len<<"\t"<<m[i].flag<<"\t";
        for(j=0; j<m[i].len;j++)
            cout << m[i].data[j];
        cout << "\n";
    }
    cout << "\nTotal no. of frames: " << count;
    cout << "\nEnter 1/0 to continue: ";
    cin >> ch;
    if(ch == 0)
        exit(0);
}

void sort()
{
    for(i=0; i<count; i++)
        for(j=i+1; j<count; j++)
            if(m[i].seq>m[j].seq)
            {
                temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
    cout << "\nSorted Frames at Receiving Terminal: \n";
    cout << "\nFSeq No.\tFLen\tFlag\tFData\n";
    for(i=0; i<count; i++)
    {
        cout << m[i].seq <<"\t\t"<<m[i].len<<"\t"<<m[i].flag<<"\t";
        for(j=0; j<m[i].len;j++)
            cout << m[i].data[j];
        cout << "\n";
    }
}

int main()
{
    system("CLS");
    cout << "\nEnter the data: ";
    cin.get(val,100);
    tsize = strlen(val);
    frames();
    trans();
    sort();

}