//graph, tree, dfs, bfs, 격자 탐색 트릭

// 1) graph:
// 포항 - 서울 이어놓고 싶을 때 쓰는 자료구조
// cs에서는 정점(node, vertex)과 간선(edge)이 쌍으로 이루어진 집합
// node가 인물 edge : 관계 사랑한다 등,
// 간선 : 단방향, 양방향(방향이 없다)

// 2차원배열에 1, 0 -> 메모리 많이써야함 0은 낭비임 : 인접 여부 체크가 쉬움
// 인접리스트(VV) : vector<pair<int, int>> : 인접 여부 체크하려면 3의 인접노드들을 모두 탐색해야함

// 간선: + 가중치
// 도시(정점), 길(간선), 거리(가중치)

// 양방향. 단방향


//2) tree: 나무를 거꾸로 뒤집어둔 상태!
// 사이클이 없는 그래프(간선을 중복해서 사용하지 않고 어떠한 정점에서 자기 자신으로 돌아올 수 있을 떄)

// 원하는 노드를 찾기위한, 탐색의 방법
// 3) DFS : 깊이 우선 탐색 
// 4) BFS : 너비 우선 탐색


// DFS 기본 코드
// stack을 사용하고 있음! stack을 사용하고 있다고 볼 수 있음 정점 정점을 쌓으니까!
void dfs(int cur) {
    visited[cur] = true;
    for (int nxt : G[cur]) {      
        if (!visited[nxt])        
            dfs(nxt);
    }
}

// BFS 기본 코드
// queue를 사용한다!

//시작점 : root, 그래프 저장 방식 : 인접 리스트

// 장점: 메모리를 별로 안쓴다! heap이 더 비싼 메모리 > 스택, heap공간을 활용할 수 있다!
// 스택, 힙 메모리 영역 크기를 다르게 주는 경우가 있음.. 그래서 
// 메모리 영역 : 힙이 더 빠르게! 동적 할당 하고 있음, 스택은 정적 영역 
// 그래서 힙 영역에 할당할 수 있는 queue!

queue<int> q;
q.push(root);

while(!q.empty()){
    // 2) front를 빼면서 cur체크함
	int cur = q.front(); q.pop();
	cout << cur << " ";

	for(auto it:G[cur]) {
		if(visited[it]) continue;
        // 1) queue에 넣을 때 visited 체크!
		visited[it]=1;
		q.push(it);
	}
}



#include<bits/stdc++.h>
using namespace std;

int main(){

}