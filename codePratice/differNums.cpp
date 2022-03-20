#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 对字符串中的给定区间做字符大小写转换。
int main(){
    int M = 0, N = 0;
    cin >> M >> N;
    int a = 0, b = 0;
    vector<int> nums(M+1, 0);
    string s;

    cin >> s;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        nums[a] ++;
        if(b < M) nums[b+1]--;
    }
    for(int i = 1; i <= M; ++i){
        nums[i] = nums[i-1] + nums[i];
        if(nums[i] % 2 != 0){
            if(s[i-1] >= 'A' && s[i-1] <= 'Z'){
                s[i-1] = s[i-1] + 32;
            }else if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
            {
                s[i-1] = s[i-1] - 32;
            }
        }
    }
    cout << s << endl;
    return 0;
}