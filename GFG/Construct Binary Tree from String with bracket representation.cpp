class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        stack<int> st;
        map<int,Node*> mp;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==')')
            {
                int child=st.top();
                Node* c;
                if(mp.find(child)==mp.end())
                {
                    c=new Node(child);
                }
                else
                    c=mp[child];
                st.pop();
                int parent=st.top();
                if(mp.find(parent)==mp.end())
                {
                    Node* p=new Node(parent);
                    p->left=c;
                    mp[parent]=p;
                }
                else
                {
                    Node *p= mp[parent];
                    p->right = c;
                }
            }
            else
            {
                int num=0;
                if(str[i]=='(')
                {
                    continue;
                }
                else
                {
                    while(isdigit(str[i]))
                    {
                        num=num*10+(str[i]-'0');
                        i++;
                    }
                    i--;
                    st.push(num);
                }
            }
        }
        if(mp.size()==0)
            return new Node(st.top());
        return mp[st.top()];
    }
};
