long repeatedString(string s, long n) {
    long result = 0;
    long length = s.size();

    for (int i = 0; i < length; i++) {
        if (s[i] == 'a')
            result += n / length;
    }

    int rest = n % length;

    for (int i = 0; i < rest; i++) {
        if (s[i] == 'a')
            result++;
    }

    return result;
}