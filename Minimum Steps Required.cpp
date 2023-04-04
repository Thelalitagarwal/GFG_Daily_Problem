int minSteps(string str) {
    int a=0,b=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a'){
            while(str[i]=='a'){
                i++;
            }
            a++;
            i--;
        }
        else{
            while(str[i]=='b'){
                i++;
            }
            b++;
            i--;
        }
    }
    int k = min(a,b);
    return k+1;
}