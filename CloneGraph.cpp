// https://leetcode.com/problems/clone-graph/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        map<int, Node*> m_map;
        stack<Node*> dfs;
        unordered_set<int> visited;
        dfs.push(node);
        while(!dfs.empty()){
            auto nxt = dfs.top(); dfs.pop();
            if (!visited.emplace(nxt->val).second){
                continue;
            }
            
            auto newNode = new Node(nxt->val, nxt->neighbors);
            
            m_map[nxt->val] = newNode;
            for(auto &iterNode : nxt->neighbors){
                dfs.push(iterNode);
            }
        }
        
        for(auto &value : m_map){
            for(auto &node : value.second->neighbors){
                node = m_map[node->val];
            } 
        }
        
        return m_map[node->val];
    }
};
