/*
 * isValid.c
 *
 *  Created on: Oct 7, 2019
 *      Author: New User
 */
#include "usedLibs.h"
int chkValid(void);
int charArr[26] = {0};

char* isValid(char* s) {
	for(int x = 0; ((s[x] > 96) && (s[x] < 123)); x++)
	{
		charArr[s[x] - 97]++;
	}

	if(chkValid())
	{
		return "YES";
	}
	for(int x = 0; x < 26; x++)
	{
		if(charArr[x] != 0)
		{
			charArr[x]--;
			if(chkValid())
			{
				return "YES";
			}
			charArr[x]++;
		}
	}


	return "NO";

}

int chkValid(void)
{
	int num = 0;
	int a = 1;
	for(int x = 0; x < 26; x++)
	{
		if((charArr[x] != 0) && a)
		{
			num = charArr[x];
			a--;
		}
		if(!a)
		{
			if((charArr[x] != 0) && charArr[x] != num)
			{
				return 0;
			}
		}
	}
	return 1;
}

void isValidMain(void)
{
	char input[] = "hyzzeohdidavrazjqqjfyulkoutdkywsyvrdlaitdirxkqicitijovtcpphcndwmzppmpziujzrtrcvavfjlceputwwhauvbjmnylvuuwopoqkonszzwdoqznognidorpbrazmwvaljsxzfpagmgxefktnxdqlvfoohnaflcquwnwcfwktchxhrsuqwmdtruhajkfumxplllnsjzlmjkvafqtdcywwsfycpewebnpoaegkftyoetrjjkookkmdrkhjodpstggtmpfridgoxxzijnwtziyrtfcjlrbexkxjzfcjiiafhzospmooxmhqsjzdadjzpiionnzyvzdfbtxqingfaqvuzwzcbkbqsmggziewjjbkfbcnqlsqbpmannerxghquqyvyerhpvuwywjojdhkutnkjrbizkavayqaekiwfesdaermjawgwjqfdtnefoaiosivcsrhwlmzpglbgjhctzjyuzeznehdzqybkrlhfxiwftxmceqxfcxzbczqigthyujjnusstapzvmnztfzahwaiabyjjusiqdtdznytnpukdjjyokzwhbgjehsndnxtqsyqfyjunferoqpcaqajtjtxsnlvakqrdqhipsfexjvnznrcfslzdewvujsuuilxyuhpomunyrazgsbmmplrthmnrekloxkouteiiawgryhyqjmeyxvtejjxpvkdswumqavaatgtrntkyfqycmujxdinytsspmfhmchmxpiqfdafjtenhyyedhrbcmvtyadlemzdcjujnuownulwsmbxvuyxgwshyvudktgmfcxsxnqmidlcpmakgajpwcwvzqajlixqlwkkkaysgjuvvugevrvtttovjoewzepkazwkcueiezfbvlhsdemyxctgtafsguegvatxuzhaynewanqfscephzyabduhzyqualuukbxlodhrqzwieaalcynddhnefdyfqsbawalmdudwuagycglegyklfxpmcq";
	printf("%s", isValid(input));

}
