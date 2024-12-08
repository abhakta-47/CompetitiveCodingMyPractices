struct Result {
    Result(): output1(){};
    int output1[100];
};

struct Result getStringArrangement(int input1, int input2[]){
    int ans[100];
    for(int i=0; i<input1; i++) ans[i] = -1;
    for(int i=0;i<input1;i++){
        int j = input2[i], turn=0;
        do{
            if(ans[j]!=-1){
                ans[j] = ++turn;
                break;
            }
            j = (j+1)%input1;
        }while(j!=input2[i]);
    }
    struct Result result;
    for(int i=0; i<100; i++)
        result.output1[i] = ans[i];E
    return result;
}

int specialString(string input1, string input2){
    string s = input1;
    string a = input2;
    bool isPresent[26] = {false};
    for(char c : a) isPresent[c-'a'] = true;
    int ans = 0;
    for(int is : s){
        int x = is-'a';
        for(int d=0; d<26; d++){
            if( 0<= x-d && x-d < n ){
                if(isPresent[x-d]) {
                    ans+=d;
                    break;
                }
            }
            if( 0<= x+d && x+d < n ){
                if(isPresent[x+d]) {
                    ans+=d;
                    break;
                }
            }
        }
    }
    return ans;
}