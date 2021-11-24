int weightCapacity(vector<int> &weights, int maxCapacity) {
        //create a set with initial value 0, (no weight is selected)
        set<long> st;
        st.insert(0);
        //iterate over the weights
        for(int weight : weights){
             //create a clone of existing set
            auto temp = st;
            //iterate over the clone and add the present weight to each weight
            //if it exceeds max capacity continue, else add it to original set.
            for(auto it = temp.begin();it != temp.end() ; it++){
                long ans = *it+weight;
                if(ans > maxCapacity)
                continue;
                st.insert(ans);
            }
        }
        //return the last element of set
        return *st.rbegin();
    }
