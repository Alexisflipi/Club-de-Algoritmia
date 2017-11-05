//Manacher’s Algorithm – Linear Time Longest Palindromic Substring
int Manacher(string s){
    int N = (int) s.size();
    N = 2*N + 1;
    int L[N];
    L[0] = 0;
    L[1] = 1;
    int C = 1, R = 2, i = 0;
    int iMirror;
    int maxL = 0, maxC = 0;
    int start = -1, end = -1, diff = -1;
     
    for (i = 2; i < N; i++) {
        iMirror  = 2*C-i;
        L[i] = 0;
        diff = R - i;
        if(diff > 0) L[i] = min(L[iMirror], diff);

        while (((i + L[i]) < N && (i - L[i]) > 0) && 
            (((i + L[i] + 1) % 2 == 0) || 
            (s[(i + L[i] + 1)/2] == s[(i - L[i] - 1)/2] ))) {
            L[i]++;
        }
 
        if(L[i] > maxL)
            maxL = L[i], maxC = i;
        
        if (i + L[i] > R)
            C = i, R = i + L[i];
    }
    start = (maxC - maxL)/2;
    end = start + maxL - 1;
    return end - start + 1;
}
