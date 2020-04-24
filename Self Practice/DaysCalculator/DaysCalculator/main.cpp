#include<iostream>
using namespace std;

int leap[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int nleap[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int ly = 366;
int nly = 365;
int Sum(int a[13],int start = 0 , int end = 13)
{
    int sum=0;
    for(int i=start;i<end;i++)
    {
        sum+=a[i];
    }
    return sum;
}

int ted(int d,int m,int y)
{
    int sum=0;
    if(m!=2)
    {
        for(int i=d+1;i<=leap[m];i++)
        {
            sum+=1;
        }
    }
    else
    {
        if(y%4==0)
        {
            for(int i=d+1;i<=leap[m];i++)
            {
                sum+=1;
            }
        }
        else
        {
            for(int i=d+1;i<=nleap[m];i++)
            {
                sum+=1;
            }
        }
    }
    return sum;
}

int tem(int d,int m,int y)
{
    int sum=0;
    if(y%4==0)
    {
        for(int i=m+1;i<13;i++)
        {
            sum+=leap[i];
        }
    }
    else
    {
        for(int i=m+1;i<13;i++)
        {
            sum+=nleap[i];
        }
    }
    return sum;
}

int tgd(int d,int m,int y)
{
    return d;
}

int tgm(int d,int m,int y)
{
    int sum=0;
    if(y%4==0)
    {
        for(int i=1;i<m;i++)
        {
            sum+=leap[i];
        }
    }
    else
    {
        for(int i=1;i<m;i++)
        {
            sum+=nleap[i];
        }
    }
    return sum;
}

int MidCalYear(int sy,int ey)
{
    int sum=0;
    if(sy==ey)
    {
        return 0;
    }
    else
    {
        for(int i=sy+1;i<ey;i++)
        {
            if(i%4==0)
            {
                sum+=ly;
            }
            else
            {
                sum+=nly;
            }
        }
        return sum;
    }
}

int MidCalMonth(int sm,int em,int sy)
{
    int sum = 0;
    if(sy%4==0)
    {
        for(int i=sm+1;i<em;i++)
        {
            sum+=leap[i];
        }
    }
    if(sy%4!=0)
    {
        for(int i=sm+1;i<em;i++)
        {
            sum+=nleap[i];
        }
    }
    return sum;
}

 class Date
{
    int sd,sm,sy,ed,em,ey;
public:
    void Set();
    bool Valid();
    long long Calculate();
    long long calculate;
};


void Date::Set()
{
    cout<<"\nEnter Start Date\n";
    cout<<"Day : ";
    cin>>sd;
    cout<<"Month : ";
    cin>>sm;
    cout<<"Year : ";
    cin>>sy;
    cout<<"\nEnter End Date\n";
    cout<<"Day : ";
    cin>>ed;
    cout<<"Month : ";
    cin>>em;
    cout<<"Year : ";
    cin>>ey;
}

bool Date::Valid()
{
    if(ey<sy)
    {
        cout<<"\nwrong input";
        return false;
    }
    if(ey==sy&&em<sm)
    {
        cout<<"\nwrong input";
        return false;
    }
    if(ey==sy&&em==sm&&ed<sd)
    {
        cout<<"\nwrong input";
        return false;
    }
    if(em<1||em>12||sm<1||sm>12)
    {
        cout<<"\nwrong input";
        return false;
    }
    if(ey%4==0)
    {
        if(ed<1||ed>leap[em])
        {
            cout<<"\nwrong input";
            return false;
        }
    }
    if(ey%4!=0)
    {
        if(ed<1||ed>nleap[em])
        {
            cout<<"\nwrong input";
            return false;
        }
    }
    if(sy%4==0)
    {
        if(sd<1||sd>leap[sm])
        {
            cout<<"\nwrong input";
            return false;
        }
    }
    if(sy%4!=0)
    {
        if(sd<1||sd>leap[sm])
        {
            cout<<"\nwrong input";
            return false;
        }
    }
    
    return true;
}

int MidCalDay(int sd,int ed)
{
    int sum=0;
    for (int i=sd;i<ed;i++)
    {
        sum+=1;
    }
    return sum;
}

long long Date::Calculate()
{
    int f;
    int s;
    int t;
    
    if(ey!=sy)
    {
        f = ted(sd,sm,sy) + tem(sd,sm,sy);
        s = MidCalYear(sy,ey);
        t = tgd(ed,em,ey) + tgm(ed,em,ey);
    }
    else if(em!=sm)
    {
        f = ted(sd,sm,sy);
        s = MidCalMonth(sm,em,sy);
        t = tgd(ed,em,ey);
    }
    else
    {
        f=0;
        s=MidCalDay(sd,ed);
        t=0;
    }
    
    
    int nod = f+s+t;
    return nod;
}


int main()
{
    Date d1;
    d1.Set();
    if(d1.Valid()==1)
    {
        d1.calculate = d1.Calculate();
        cout<<"\nNumber Of Days (not including end date) = "<<d1.calculate;
        cout<<"\nNumber Of Days (including end date) = "<<d1.calculate+1;
    }
    cout<<endl;
}
