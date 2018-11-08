// 水水更健康
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int sz = A.size();
        vector<int>l;
        vector<int>r;
        for(int i=0;i<sz;i++){
            if( (A[i] & 1) && !(i & 1)){
                l.push_back(i);
            }
             if( !(A[i] & 1) && (i & 1)){
                   r.push_back(i);
            }
        }
        for(int i=0;i<l.size();i++){
            swap(A[l[i]],A[r[i]]);
        }
        return A;
    }
};