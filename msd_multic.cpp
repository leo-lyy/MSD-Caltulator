#include <bits/stdc++.h>
using namespace std;
struct mol{
    int chain;
    double x;
    double y;
    double z;
};
#define MAX_Atom 200005
mol dump0[MAX_Atom];
mol dumpi[MAX_Atom];
double msd[1100005];
long int timestep[20000];
double dis(long int k)
{
    double ans;
    ans=pow(dumpi[k].x-dump0[k].x,2)+pow(dumpi[k].y-dump0[k].y,2)+pow(dumpi[k].z-dump0[k].z,2);
    //ans=sqrt(ans);
    return ans;
}
int main()
{
    long long num, maxstep;
    int tarchain,tarnum,endchain;

    cout << "Please enter dump file name:" << endl;
    string name;
    cin >> name;
    string inputSource = "file"; // start by reading from file
    ifstream inputFile(name);

    if (!inputFile.is_open()) {
        cerr << "Failed to open file for reading." << endl;
        return 1;
    }

    string x;
    int tt;
    getline(inputFile,x);
    getline(inputFile,x);
    getline(inputFile,x);
    inputFile>>num;
    getline(inputFile,x);
    cout<<"The number of total atom in this dump file is"<<endl<<num<<endl
        <<"Please enter the number of total steps"<<endl;
    cin>>maxstep;
    cout<<endl<<"Please enter the start and the end chain number to track:"<<endl;
    cin>>tarchain;
    cin>>endchain; 
    cout<<"Cauculating... "<<endl<<"Step"<<"    "<<"MSD"<<endl;
    long long step,a;
  
    int t=1,p=1;
    double sum;

    for(int i=1;i<=5;i++) 
    {
        getline(inputFile,x);
    }
    for(long int i=0;i<num;i++)
    {
        inputFile>>a;
        inputFile>>dump0[a].chain>>dump0[a].x>>dump0[a].y>>dump0[a].z;
    }
    step=1;
    getline(inputFile,x);//回车输入掉
    while(step!=maxstep+1)
    {
        sum=0;
        tarnum=0;
        getline(inputFile,x);
        inputFile>>timestep[p];
        p++;
        for(int i=1;i<=8;i++)
        {
            getline(inputFile,x);
        }
        for(long int i=0;i<num;i++)
        {
            inputFile>>a;
            inputFile>>dumpi[a].chain>>dumpi[a].x>>dumpi[a].y>>dumpi[a].z;
        }
        if(step!=0)
        {
            for(long int i=1;i<=num;i++)
            {
                if(dumpi[i].chain>=tarchain&&dumpi[i].chain<=endchain)
                {
                    sum+=dis(i);//计算第i个珠子与原始位置的距离
                    tarnum++;
                }
                
            }
            msd[step]=sum/tarnum;
            if (step%10==0)
            {
                cout<<step<<"       "<<msd[step]<<endl;//每十个step输出一次到控制台
            }
        }
        step++;
        getline(inputFile,x);//回车输入掉
    }
    inputFile.close(); // close the input file when finished
    freopen("msd.txt","w",stdout);
    for(long int i=1;i<=maxstep;i++)
    {
        cout<<timestep[i+1]<<"      ";
        printf("%.6f",msd[i]);
        cout<<endl;
    }
    return 0;

}