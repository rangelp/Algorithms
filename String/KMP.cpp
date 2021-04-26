/*pi : O(n)
  mathing: O(n+m)
 */

vector <int> pi(string s){
	vector <int> p(sz(s));
	for(int i = 1, j = 0; i < sz(s); i++){
		while(j and s[j] != s[i])
			j = p[j-1];
		if(s[j] == s[i])
			j++;
		p[i] = j;
	}
	return p;
}
 
vector <int> matching(string s, string t){
	vector <int> p = pi(s), match;
	for(int i = 0, j = 0; i < t.size(); i++) {
		while(j and s[j] != t[i])
			j = p[j-1];
		if(s[j] == t[i])
			j++;
		if(j == sz(s))
			match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}
