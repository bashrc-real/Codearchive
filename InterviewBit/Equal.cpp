// https://www.interviewbit.com/problems/equal/
// Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array
// 1) Return the indices `A1 B1 C1 D1`, so that 
//   A[A1] + A[B1] = A[C1] + A[D1]
//   A1 < B1, C1 < D1
//   A1 < C1, B1 != D1, B1 != C1 

// 2) If there are more than one solutions, 
//    then return the tuple of values which are lexicographical smallest. 

vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int, pair<int,int>> values;
    auto ans = make_tuple(1000000000, 1000000000, 1000000000, 1000000000);
    for(int i = 0, sz = A.size(); i < sz; ++i){
        for(int j = i + 1; j < sz; ++j){
            auto sm = A[i] + A[j];
            auto it = values.find(sm);
            if (it == values.end()){
                it = values.emplace(sm, make_pair(i, j)).first;
            }else{
                if (it->second.first <  i && it->second.second != i && it->second.second != j){
                    ans = min(make_tuple(it->second.first, it->second.second, i, j), ans);
                }
            }
            it->second = min(make_pair(i, j), it->second);
        }
    }
    return vector<int>{std::get<0>(ans), std::get<1>(ans), std::get<2>(ans), std::get<3>(ans)};
}

