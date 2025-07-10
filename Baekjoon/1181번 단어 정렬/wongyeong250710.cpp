// 단어 정렬 성공
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 2 초	256 MB	231689	99002	74054	40.939%
// 문제
// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

// 길이가 짧은 것부터
// 길이가 같으면 사전 순으로
// 단, 중복된 단어는 하나만 남기고 제거해야 한다.

// 입력
// 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

// 출력
// 조건에 따라 정렬하여 단어들을 출력한다.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<string, int>& front, pair<string, int>& back){
    bool result = false;
    if(front.second == back.second){
        result = (front.first < back.first);
    }
    else{
        result = front.second < back.second;
    }
    
    return result;
}

int main(){
    int N;
    cin >> N;
    vector<pair<string, int>> words;
    string word;
    for(int i=0; i<N; i++){
        cin >> word;
        pair<string, int> info = make_pair(word, word.length());
        words.push_back(info);
    }
    
    sort(words.begin(), words.end(), compare);
        
    for(int i=0; i<N; i++){
        if(i!=0 && (words[i].first == words[i-1].first))
            continue;
        cout << words[i].first << endl;
    }
    
    return 0;
}