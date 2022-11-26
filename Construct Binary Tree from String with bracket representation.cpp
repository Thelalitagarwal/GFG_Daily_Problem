class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        stack<int> s;
        map<int, Node*> m;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ')') {
                int child = s.top();
                Node* c;
                if(m.find(child) == m.end())
                    c = new Node(child);
                else 
                    c = m[child];
                s.pop();
                int parent = s.top();
                if(m.find(parent) == m.end()) {
                    Node* p = new Node(parent);
                    p->left = c;
                    m[parent] = p;
                }
                else {
                    Node* p = m[parent];
                    p->right = c;
                }
            }
            else {
                int num = 0;
                if(str[i] == '(') {
                    continue;
                }
                else {
                    while(isdigit(str[i])) {
                        num = num*10 + (str[i]-'0');
                        i++;
                    }
                    i--;
                    s.push(num);
                }
            }
        }
        if(m.size() == 0) return new Node(s.top());
        return m[s.top()];
    }
};