#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
// 集合合并问题。
int main(){
    int M = 0, N = 0, count = 0;
    cin >> N >> M;
    int a = 0, b = 0;
    int a_index = 0, b_index = 0;
    // 采用牺牲内存的方式。
    unordered_map<int, unordered_set<int> > mp;
    unordered_map<int, unordered_set<int> >::iterator it;
    for (int i = 0; i < M; ++i){
        a_index = -1, b_index = -1;
        cin >> a >> b;
        for(it = mp.begin(); it != mp.end(); it++){
            if(it->second.count(a) > 0)  a_index = it->first;
            if(it->second.count(b) > 0) b_index = it->first;
        }
        if(a_index == -1 && b_index == -1){
            mp[count].insert(a);
            mp[count].insert(b);
            count++;
        }else if(a_index == -1 && b_index != -1){
            mp[b_index].insert(a);
        }else if(a_index != -1 && b_index == -1){
            mp[a_index].insert(b);
        }else if(a_index != b_index){   // 这里表示要合并数组。
            mp[a_index].insert(mp[b_index].begin(), mp[b_index].end());
            mp.erase(b_index);
        }
    }
    cout << mp.size() << endl;
    unordered_set<int>::iterator setIt;
    for(it = mp.begin(); it != mp.end(); ++it){
        for(setIt = it->second.begin(); setIt != it->second.end(); ++setIt){
            cout << *setIt << ",";
        }
        cout << endl;
    }
    return 0;
}