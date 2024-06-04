#include <set>
#include <map>

// 1. set 자료구조

set<int> s;
s.insert(1);

// find 해서 2가 없으면 end를 가리키는 포인터 반환
// find를 먼저하고 erase를 해줘야함!

if(s.find(2) != s.end()) cout << "2 found!\n";
s.erase(1);

// binary search tree 때문에 순차적으로 순회하듯 탐색

// unordered_set을 활용하면 hash set을 사용할 수 있습니다.
// 추가로 중복 키 허용 set인 multiset도 있습니다.

for(set<int>::iterator it=s.begin();it!=s.end(); ++it){
	// it를 활용하여 값 순회
}

for(auto it=s.begin();it!=s.end(); ++it){
	// it를 활용하여 값 순회, auto 사용해도 결과 동일.
}

// 2. map <key, value>



map<string, int> m;
m["asdf"] = 3;
// 선언하는 것 만으로 insert가 된다!

m["qwer"]++;

// unordered_map을 활용하면 hash map을 사용할 수 있습니다.
// 중복 키 허용인 multimap도 있습니다.

for(map<string, int>::iterator it=m.begin(); it!=m.end(); ++it){
	it->first : key, it->second : value
}
//마찬가지로 auto로 간소화 가능
// map 관련 잡기술 연마해야 코테에서 시간 단축 가능!

it->first
(*it).first