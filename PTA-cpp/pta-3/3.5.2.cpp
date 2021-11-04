//
// Created by szy on 2021/11/1.
//

#include<iostream>
#include "map"

using namespace std;

int main()
{
    int team;
    cin>>team;

    for(int i=0; i<team; i++)
    {
        map<string,int> mp;
        int num;
        cin>>num;
        string str[num];
        for(int j=0; j<num; j++)
        {
            cin>>str[j];
            mp[str[j]] = 0;
        }

        for(int j=0; j<num; j++)
        {
            mp[str[j]] ++;
        }

        map<string, int>::iterator iter;

        for(iter = mp.begin();iter!=mp.end();iter++){

            cout<<iter->first<<" "<<iter->second<<endl;
        }
    }
    return 0;
}
