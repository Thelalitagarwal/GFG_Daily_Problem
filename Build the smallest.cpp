string buildLowestNumber(string num, int k) {

    stack<char> st;

    st.push(num[0]);

    int n = num.length();

    for(int itr = 1; itr < n;++itr) {

        while(!st.empty() && st.top() > num[itr] && k > 0) {

            st.pop();

            --k;

        }

        st.push(num[itr]);

    }

    while(k > 0) {

        st.pop();

        --k;

    }

    string ans = "";

    while(!st.empty()) {

        ans=st.top()+ans;

        st.pop();

    }

    int leadingIndex = -1;

    for(int itr = 0; itr < ans.length(); ++itr) {

        if(ans[itr] != '0') break;

        leadingIndex = itr;

    }

    if(leadingIndex == ans.length()-1) return "0";

    if(leadingIndex >= 0) return ans.substr(leadingIndex+1);

    return ans;

}