/*
 * substrCount.c
 *
 *  Created on: Oct 8, 2019
 *      Author: Omar Zayed
 */

#include "usedLibs.h"
int substrChk(int a, int b, char* s);



long substrCount(int n, char* s) {

	long out = 0;
	for(int y = 0; y < n; y++)
	{
		for(int x = 0; (x + y) < n; x++)
		{
			out += substrChk(x, x + y, s);

		}
	}

	return out;
}

int substrChk(int a, int b, char* s)
{
	char chk = s[a];
	while((b - a) >= 0)
	{
		if((s[a] != s[b]) || (s[a] != chk))
		{
			if(a != b)
			{
			return 0;
			}
		}
		a++;
		b--;
	}


	return 1;
}



void substrCountMain(void)
{
	int size = 727310;
	char* str = "ccacacabccacabaaaabbcbccbabcbbcaccabaababcbcacabcabacbbbccccabcbcabbaaaaabacbcbbbcababaabcbbaaababababbabcaabcaacacbbaccbbabbcbbcbacbacabaaaaccacbaabccabbacabaabaaaabbccbaaaabacabcacbbabbacbcbccbbbaaabaaacaabacccaacbcccaacbbcaabcbbccbccacbbcbcaaabbaababacccbacacbcbcbbccaacbbacbcbaaaacaccbcaaacbbcbbabaaacbaccaccbbabbcccbcbcbcbcabbccbacccbacabcaacbcaccabbacbbccccaabbacccaacbbbacbccbcaaaaaabaacaaabccbbcccaacbacbccaaacaacaaaacbbaaccacbcbaaaccaabcbccacaaccccacaacbcacccbcababcabacaabbcacccbacbbaaaccabbabaaccabbcbbcaabbcabaacabacbcabbaaabccabcacbcbabcbccbabcabbbcbacaaacaabbbabbaacbbacaccccabbabcbcabababbcbaaacbaacbacacbabbcacccbccbbbcbcabcabbbcaabbaccccabaabbcbcccabaacccccaaacbbbcbcacacbabaccccbcbabacaaaabcccaaccacbcbbcccaacccbbcaaaccccaabacabcabbccaababbcabccbcaccccbaaabbbcbabaccacaabcabcbacaccbaccbbaabccbbbccaccabccbabbbccbaabcaabcabcbbabccbaaccabaacbbaaaabcbcabaacacbcaabbaaabaaccacbaacababcbacbaacacccacaacbacbbaacbcbbbabccbababcbcccbccbcacccbababbcacaaaaacbabcabcacaccabaabcaaaacacbccccaaccbcbccaccacbcaaaba";
	printf("%ld", substrCount(size, str));

}



