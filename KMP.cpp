// 1) LPS (longest prefix suffix)
// The longest proper prefix which is equal to suffix for every index

void lpsfind(vector<int>& lps, string &s){
    int pre = 0, suf = 1;
    while(suf < s.size()){
        if(s[suf] == s[pre]){
            lps[suf] = pre + 1;
            pre ++, suf ++;
        }
        else {
            if(pre == 0){
                lps[suf] = 0;
                suf ++; 
            }
            else {
                pre = lps[pre - 1];
            }
        }
    }
}

/*===============================================================================================================================*/
// KMP algorithm

// 1) find lps array of pattern;
// 2) strign -> haystack and pattern -> needle;

int KMP (string &haystack, string& needle) {
    lpsfind(lps, needle);
    int f = 0, s = 0;
    while(f < haystack.size() && s < needle.size()){
            // match
            if(haystack[f] == needle[s]){
                f ++, s ++;
            }
            // notMatch
            else {
                if(s == 0) f ++;
                else s = lps[s - 1];
            }
        }

        if(s == needle.size()) return f - s;
        else return -1;
    }
}
