//bRUTE fORCE

char* longestNiceSubstring(char* s) {
    int len = strlen(s);
    if (len < 2) {
        return "";
    }
    int i, j;
    int max_len = 0, start = -1;
    for (i = 0; i < len; i++) {
        int freq[26] = {0};
        for (j = i; j < len; j++) {
            if (s[j] >= 'a' && s[j] <= 'z') {
                freq[s[j] - 'a'] |= 1;
            } else {
                freq[s[j] - 'A'] |= 2;
            }
            int k;
            for (k = 0; k < 26; k++) {
                if (freq[k] == 1 || freq[k] == 2) {
                    break;
                }
            }
            if (k == 26 && j - i + 1 > max_len) {
                max_len = j - i + 1;
                start = i;
            }
        }
    }
    if (start == -1) {
        return "";
    } else {
        char* res = (char*)malloc((max_len + 1) * sizeof(char));
        strncpy(res, s + start, max_len);
        res[max_len] = '\0';
        return res;
    }
}

//Divide and Conqueor
char* longestNiceSubstring(char* s) {
    int len = strlen(s);
    if (len < 2) {
        return strdup("");
    }
    char* res = strdup(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (islower(c)) {
            char* upper = strchr(s, toupper(c));
            if (upper == NULL) {
                char* left = longestNiceSubstring(strndup(s, i));
                char* right = longestNiceSubstring(strdup(s+i+1));
                if (strlen(left) >= strlen(right)) {
                    free(right);
                    res = left;
                } 
                else {
                    free(left);
                    res = right;
                }
                break;
          }
       }
        else {
            char* lower = strchr(s, tolower(c));
            if (lower == NULL) {
                char* left = longestNiceSubstring(strndup(s, i));
                char* right = longestNiceSubstring(strdup(s+i+1));
                if (strlen(left) >= strlen(right)) {
                    free(right);
                    res = left;
                }
                else {
                    free(left);
                    res = right;
                }
            break;
        }
    }
}
return res;
}
