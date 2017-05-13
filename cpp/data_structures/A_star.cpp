#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <assert.h>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;
int test = 1;

unsigned int const gridSize = 10;
namespace AStar {
    
    template<typename T>
    class priority_queue{
        public:
            void insert(T node, unsigned int cost){
                container.insert(make_pair(cost, node));
            }
  
            pair<unsigned int, T> removeMin(){
                assert(!container.empty());
                auto iter = container.begin();
                auto minVal = *iter;
                container.erase(iter);
                return minVal;
            }
  
            void updateCost(T node, unsigned int cost){
                auto nodeCostPair = make_pair(cost, node);
                auto iter = container.find(nodeCostPair);
                if (iter != container.end()){
                    container.erase(iter);
                }
                nodeCostPair.first = cost;
                container.insert(nodeCostPair);
            }
            
            bool empty() const{
                return container.empty();
            }
            
        private:
            set<pair<unsigned int, T>> container;      
    };
}

typedef pair<unsigned int, unsigned int> position;

position getStartNode(){
    return make_pair(0, 0);
}

position getDestinationNode(){
    static position destination = make_pair(rand()%gridSize+1, rand()%gridSize+1);
    return destination;
}
void generateInput(set<position> *barriers){
    
    freopen("barrierData","r",stdin);//redirects standard input
    unsigned int x;
    unsigned int y;
    while(cin >> x >> y){
    size_t maxBarriers = rand() % (100);
    for(size_t i = 0; i < maxBarriers; ++i){
        auto barrierNode = position(x, y);
        if (barrierNode != getDestinationNode()){
            barriers->insert(barrierNode);
        }
    }
    }
}

bool isBarrier(position p){
    static bool isInputProcessed = false;
    static set<position> barriers;
    if (!isInputProcessed){
        generateInput(&barriers);
        isInputProcessed = true;
    }
    return barriers.find(p) != barriers.end();
}

bool isInBounds(int i, int j){
    return i >= 0 && i < gridSize && j >= 0 && j < gridSize;
}

void getNextMoves(position curNode, deque<position>* nextPosition){
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i==0 && j==0) continue;
            auto nxtMove = make_pair(curNode.first+i, curNode.second+j);
            if(isInBounds(static_cast<int>(curNode.first)+i, static_cast<int>(curNode.second)+j) && 
            !isBarrier(nxtMove)){
                nextPosition->push_back(nxtMove);
                cout<<"("<<curNode.first<<","<<curNode.second<<"),("<<nxtMove.first<<","<<nxtMove.second<<")"<<endl;
            }
        }        
    }
}
+   unsigned int h_cost(position currentPosition){
    position destination = getDestinationNode();
    return static_cast<unsigned int>(sqrt((destination.first - currentPosition.first) * (destination.first - currentPosition.first)+
           (destination.second - currentPosition.second) * (destination.second - currentPosition.second)));
}

void printBoard(position currentNode){
    for (unsigned int i = 0; i < gridSize; i++){
        for(unsigned int j = 0; j < gridSize; j++){
            char status = '.';
            assert(!isBarrier(currentNode));
            status = ((currentNode.first == i && currentNode.second == j) ? 'S' : status);
            status = ((isBarrier(make_pair(i,j))) ? '#' : status);
            status = (getDestinationNode().first == i && getDestinationNode().second == j) ? 'D' : status;
            cout<<status;
        }
        cout<<endl;
    }
    cout<<"----------------------------------------------------------------------------------------"<<endl;
}
void makeMove(map<position, position> const path, position source, position destination){
    auto iter = path.find(destination);
    deque<position> pt;
    while(iter != path.end()){
     //   printBoard(source);
        destination = iter->second;
        pt.push_front(destination); 
        iter = path.find(destination);
    }
    for(auto iter:pt) {
        printBoard(iter);
        std::chrono::milliseconds duration(2000);
        std::this_thread::sleep_for(duration);
        }
}
void solve(){
    AStar::priority_queue<position> openList;
    set<position> closedList;
    position startNode = getStartNode();
    openList.insert(startNode, h_cost(startNode));
    map<position, unsigned int> cost;
    map<position, position> path; 
    do{
        pair<unsigned int, position> nextNodeCostPair = openList.removeMin();
        position nextNode = nextNodeCostPair.second;
        closedList.insert(nextNode);
        if (nextNode == getDestinationNode()){
            makeMove(path, getStartNode(), getDestinationNode());
            break;
        }
        deque<position> possibleNextMoves;
        getNextMoves(nextNode, &possibleNextMoves);
        for(auto iter : possibleNextMoves){
            if (closedList.find(iter) != closedList.end()) continue;
            auto handle = cost.find(iter);
            if (handle == cost.end() || handle->second > cost[nextNode] + 1){
                if (handle == cost.end()){
                    handle = cost.emplace(iter, 0).first;
                }
                handle->second = cost[nextNode] + 1;
                openList.updateCost(iter, handle->second + h_cost(iter));
                path[iter] = nextNode;
            }
        }
    }while(!openList.empty());
}


int main(){
    #ifndef ONLINE_JUDGE
    test = 1;
    #endif
    for (int i=0;i<test;i++){
        solve();
    }
}

